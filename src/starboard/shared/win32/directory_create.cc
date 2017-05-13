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

#include "starboard/directory.h"

#include <windows.h>

#include "starboard/shared/win32/directory_internal.h"
#include "starboard/shared/win32/wchar_utils.h"

bool SbDirectoryCreate(const char* path) {
  if ((path == nullptr) || (path[0] == '\0')) {
    return false;
  }

  std::wstring path_wstring = starboard::shared::win32::CStringToWString(path);

  starboard::shared::win32::TrimExtraFileSeparators(&path_wstring);

  if (!starboard::shared::win32::IsAbsolutePath(path_wstring)) {
    return false;
  }

  BOOL directory_created = CreateDirectoryW(path_wstring.c_str(), NULL);

  bool directory_exists =
      directory_created || (GetLastError() == ERROR_ALREADY_EXISTS);

  return directory_exists;
}
