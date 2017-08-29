// Copyright 2017 Google Inc. All Rights Reserved.
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

#include "cobalt/browser/lib/exported/main.h"

#include "base/bind.h"
#include "base/callback.h"
#include "base/lazy_instance.h"
#include "base/logging.h"
#include "cobalt/base/wrap_main.h"
#include "cobalt/browser/application.h"
#include "starboard/event.h"
#include "starboard/input.h"

namespace {

cobalt::browser::Application* g_application = NULL;
typedef base::Callback<void(void)> InitializedCallback;
typedef base::Callback<bool(const SbEvent*)> HandleEventCallback;
static base::LazyInstance<InitializedCallback>
    g_on_cobalt_initialized_callback = LAZY_INSTANCE_INITIALIZER;
static base::LazyInstance<HandleEventCallback> g_handle_event_callback =
    LAZY_INSTANCE_INITIALIZER;

// We cannot use LazyInstance here as this can be set before Cobalt has been
// initialized at all - thus there will not yet exist an AtExitManager which
// means the app would crash if we tried to replace the lazy instance too
// early. Instead, for this one callback, we simply do things manually.
CbLibMainCallbackRegistrationReadyCallback g_callback_registration_ready =
    nullptr;
void* g_registration_ready_context = nullptr;


void PreloadApplication(int /*argc*/, char** /*argv*/, const char* /*link*/,
                        const base::Closure& quit_closure) {
  DCHECK(!g_application);
  CHECK(g_callback_registration_ready);
  g_callback_registration_ready(g_registration_ready_context);
  g_application =
      new cobalt::browser::Application(quit_closure, true /*should_preload*/);
  DCHECK(g_application);
}

void StartApplication(int /*argc*/, char** /*argv*/, const char* /*link*/,
                      const base::Closure& quit_closure) {
  LOG(INFO) << "Starting application!";
  if (!g_application) {
    CHECK(g_callback_registration_ready);
    g_callback_registration_ready(g_registration_ready_context);
    g_application = new cobalt::browser::Application(quit_closure,
                                                     false /*should_preload*/);
    DCHECK(g_application);
  } else {
    g_application->Start();
  }
  DCHECK(g_application);
  if (!g_on_cobalt_initialized_callback.Get().is_null())
    g_on_cobalt_initialized_callback.Get().Run();
}

void StopApplication() {
  DCHECK(g_application);
  LOG(INFO) << "Stopping application!";
  delete g_application;
  g_application = NULL;
}

void HandleStarboardEvent(const SbEvent* starboard_event) {
  if (g_application && (g_handle_event_callback.Get().is_null() ||
                        !g_handle_event_callback.Get().Run(starboard_event))) {
    g_application->HandleStarboardEvent(starboard_event);
  }
}

}  // namespace

COBALT_WRAP_MAIN(PreloadApplication, StartApplication, HandleStarboardEvent,
                 StopApplication);

void CbLibMainSetCallbackRegistrationReadyCallback(
    void* context, CbLibMainOnCobaltInitializedCallback callback) {
  g_registration_ready_context = context;
  g_callback_registration_ready = callback;
}

void CbLibMainSetOnCobaltInitializedCallback(
    void* context, CbLibMainOnCobaltInitializedCallback callback) {
  g_on_cobalt_initialized_callback.Get() =
      callback ? base::Bind(callback, context) : InitializedCallback();
}

void CbLibMainSetHandleEventCallback(void* context,
                                     CbLibMainHandleEventCallback callback) {
  g_handle_event_callback.Get() =
      callback ? base::Bind(callback, context) : HandleEventCallback();
}