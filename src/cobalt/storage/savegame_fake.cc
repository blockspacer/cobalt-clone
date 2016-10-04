/*
 * Copyright 2015 Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if !defined(COBALT_BUILD_TYPE_GOLD)

#include "cobalt/storage/savegame_fake.h"

namespace cobalt {
namespace storage {

Savegame::ByteVector* SavegameFake::s_persistent_data_;

bool SavegameFake::PlatformRead(ByteVector* bytes_ptr) {
  if (s_persistent_data_) {
    *bytes_ptr = *s_persistent_data_;
    return true;
  } else {
    return false;
  }
}

bool SavegameFake::PlatformWrite(const ByteVector& bytes) {
  if (!s_persistent_data_) {
    s_persistent_data_ = new ByteVector();
  }
  *s_persistent_data_ = bytes;
  return true;
}

bool SavegameFake::PlatformDelete() {
  if (s_persistent_data_) {
    delete s_persistent_data_;
    s_persistent_data_ = NULL;
    return true;
  } else {
    return false;
  }
}

// static
scoped_ptr<Savegame> SavegameFake::Create(const Options& options) {
  scoped_ptr<Savegame> savegame(new SavegameFake(options));
  return savegame.Pass();
}

}  // namespace storage
}  // namespace cobalt

#endif  // #if !defined(COBALT_BUILD_TYPE_GOLD)