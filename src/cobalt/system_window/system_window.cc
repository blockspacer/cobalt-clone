// Copyright 2015 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "base/logging.h"
#include "base/memory/scoped_ptr.h"
#include "base/stringprintf.h"
#include "cobalt/base/event_dispatcher.h"
#include "cobalt/system_window/input_event.h"
#include "cobalt/system_window/system_window.h"
#include "starboard/system.h"

namespace cobalt {
namespace system_window {

namespace {

SystemWindow* g_the_window = NULL;

}  // namespace

SystemWindow::SystemWindow(base::EventDispatcher* event_dispatcher,
                           const base::optional<math::Size>& window_size)
    : event_dispatcher_(event_dispatcher),
      window_(kSbWindowInvalid),
      key_down_(false) {
  if (!window_size) {
    window_ = SbWindowCreate(NULL);
  } else {
    SbWindowOptions options;
    SbWindowSetDefaultOptions(&options);
    options.size.width = window_size->width();
    options.size.height = window_size->height();
    window_ = SbWindowCreate(&options);
  }
  DCHECK(SbWindowIsValid(window_));
  DCHECK(!g_the_window) << "TODO: Support multiple SystemWindows.";
  g_the_window = this;
}

SystemWindow::~SystemWindow() {
  DCHECK_EQ(this, g_the_window);

  if (g_the_window == this) {
    g_the_window = NULL;
  }
  SbWindowDestroy(window_);
}

math::Size SystemWindow::GetWindowSize() const {
  SbWindowSize window_size;
  if (!SbWindowGetSize(window_, &window_size)) {
    DLOG(WARNING) << "SbWindowGetSize() failed.";
    return math::Size(0, 0);
  }
  return math::Size(window_size.width, window_size.height);
}

float SystemWindow::GetVideoPixelRatio() const {
  SbWindowSize window_size;
  if (!SbWindowGetSize(window_, &window_size)) {
    DLOG(WARNING) << "SbWindowGetSize() failed.";
    return 1.0;
  }
  return window_size.video_pixel_ratio;
}

SbWindow SystemWindow::GetSbWindow() { return window_; }

void* SystemWindow::GetWindowHandle() {
  return SbWindowGetPlatformHandle(window_);
}

void SystemWindow::HandleInputEvent(const SbInputData& data) {
  DCHECK_EQ(window_, data.window);

  if (data.type == kSbInputEventTypePress) {
    // Starboard handily uses the Microsoft key mapping, which is also what
    // Cobalt uses.
    int key_code = static_cast<int>(data.key);
    scoped_ptr<InputEvent> input_event(
        new InputEvent(InputEvent::kKeyDown, key_code, data.key_modifiers,
                       key_down_ /* is_repeat */));
    key_down_ = true;
    event_dispatcher()->DispatchEvent(input_event.PassAs<base::Event>());
  } else if (data.type == kSbInputEventTypeUnpress) {
    key_down_ = false;
    int key_code = static_cast<int>(data.key);
    scoped_ptr<InputEvent> input_event(
        new InputEvent(InputEvent::kKeyUp, key_code, data.key_modifiers,
                       false /* is_repeat */));
    event_dispatcher()->DispatchEvent(input_event.PassAs<base::Event>());
  } else if (data.type == kSbInputEventTypeMove) {
    int key_code = static_cast<int>(data.key);
    scoped_ptr<InputEvent> input_event(new InputEvent(
        InputEvent::kKeyMove, key_code, data.key_modifiers,
        false /* is_repeat */, math::PointF(data.position.x, data.position.y)));
    event_dispatcher()->DispatchEvent(input_event.PassAs<base::Event>());
  }
}

void OnDialogClose(SbSystemPlatformErrorResponse response, void* user_data) {
  DCHECK(user_data);
  SystemWindow* system_window =
      static_cast<SystemWindow*>(user_data);
  system_window->HandleDialogClose(response);
}

void SystemWindow::ShowDialog(
    const SystemWindow::DialogOptions& options) {
  SbSystemPlatformErrorType error_type;
  switch (options.message_code) {
    case kDialogConnectionError:
      error_type = kSbSystemPlatformErrorTypeConnectionError;
      break;
    default:
      NOTREACHED();
      break;
  }

  SbSystemPlatformError handle =
      SbSystemRaisePlatformError(error_type, OnDialogClose, this);
  if (SbSystemPlatformErrorIsValid(handle)) {
    current_dialog_callback_ = options.callback;
  } else {
    DLOG(WARNING) << "Failed to notify user of error: "
                  << options.message_code;
  }
}

void SystemWindow::HandleDialogClose(
    SbSystemPlatformErrorResponse response) {
  DCHECK(!current_dialog_callback_.is_null());
  switch (response) {
    case kSbSystemPlatformErrorResponsePositive:
      current_dialog_callback_.Run(kDialogPositiveResponse);
      break;
    case kSbSystemPlatformErrorResponseNegative:
      current_dialog_callback_.Run(kDialogNegativeResponse);
      break;
    case kSbSystemPlatformErrorResponseCancel:
      current_dialog_callback_.Run(kDialogCancelResponse);
      break;
    default:
      DLOG(WARNING) << "Unrecognized dialog response: " << response;
      break;
  }
}

void HandleInputEvent(const SbEvent* event) {
  if (event->type != kSbEventTypeInput) {
    return;
  }

  DCHECK(g_the_window);
  DCHECK(event->data);
  SbInputData* data = reinterpret_cast<SbInputData*>(event->data);
  g_the_window->HandleInputEvent(*data);
  return;
}

}  // namespace system_window
}  // namespace cobalt