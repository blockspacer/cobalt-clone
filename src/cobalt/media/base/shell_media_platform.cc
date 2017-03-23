// Copyright 2012 Google Inc. All Rights Reserved.
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

#include "cobalt/media/base/shell_media_platform.h"

namespace cobalt {
namespace media {

namespace {

ShellMediaPlatform* s_shell_media_platform_;

}  // namespace

// static
ShellMediaPlatform* ShellMediaPlatform::Instance() {
  return s_shell_media_platform_;
}

// static
void ShellMediaPlatform::SetInstance(ShellMediaPlatform* shell_media_platform) {
  s_shell_media_platform_ = shell_media_platform;
}

}  // namespace media
}  // namespace cobalt