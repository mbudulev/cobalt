// Copyright 2025 The Cobalt Authors. All Rights Reserved.
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

#ifndef STARBOARD_EXTENSION_JS_INJECTION_H_
#define STARBOARD_EXTENSION_JS_INJECTION_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Extension name constant for SbSystemGetExtension().
#define kCobaltExtensionJsInjectionName "dev.cobalt.extension.JsInjection"

typedef struct CobaltExtensionJsInjectionApi {
  // Must be kCobaltExtensionJsInjectionName.
  const char* name;

  // Version of this API. Must be 1.
  uint32_t version;

  // The fields below this point were added in version 1 or later.

  // Returns a null-terminated JavaScript string to inject at DocumentStart
  // for all origins, or NULL if no script should be injected.
  // The returned pointer must remain valid for the lifetime of the process.
  const char* (*GetInjectedJavaScript)(void);
} CobaltExtensionJsInjectionApi;

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // STARBOARD_EXTENSION_JS_INJECTION_H_
