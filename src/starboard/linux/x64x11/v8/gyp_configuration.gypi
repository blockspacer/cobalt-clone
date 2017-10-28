# Copyright 2017 Google Inc. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

{
  'variables': {
    'javascript_engine': 'v8',
    'cobalt_enable_jit': 1,
  },
  'target_defaults': {
    'default_configuration': 'linux-x64x11-v8_debug',
    'configurations': {
      'linux-x64x11-v8_debug': {
        'inherit_from': ['debug_base'],
      },
      'linux-x64x11-v8_devel': {
        'inherit_from': ['devel_base'],
      },
      'linux-x64x11-v8_qa': {
        'inherit_from': ['qa_base'],
      },
      'linux-x64x11-v8_gold': {
        'inherit_from': ['gold_base'],
      },
    }, # end of configurations
  },

  'includes': [
    '../gyp_configuration.gypi',
  ],
}
