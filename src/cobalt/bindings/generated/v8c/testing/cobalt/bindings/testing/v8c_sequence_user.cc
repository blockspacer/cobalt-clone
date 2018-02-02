

// Copyright 2018 Google Inc. All Rights Reserved.
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

// clang-format off

// This file has been auto-generated by bindings/code_generator_cobalt.py. DO NOT MODIFY!
// Auto-generated from template: bindings/v8c/templates/interface.cc.template

#include "cobalt/bindings/testing/v8c_sequence_user.h"

#include "base/debug/trace_event.h"
#include "cobalt/base/polymorphic_downcast.h"
#include "cobalt/script/global_environment.h"
#include "cobalt/script/script_value.h"
#include "cobalt/script/value_handle.h"
#include "cobalt/bindings/testing/arbitrary_interface.h"
#include "cobalt/bindings/testing/v8c_arbitrary_interface.h"

#include "v8c_gen_type_conversion.h"

#include "cobalt/script/callback_interface_traits.h"
#include "cobalt/script/v8c/callback_function_conversion.h"
#include "cobalt/script/v8c/conversion_helpers.h"
#include "cobalt/script/v8c/entry_scope.h"
#include "cobalt/script/v8c/native_promise.h"
#include "cobalt/script/v8c/type_traits.h"
#include "cobalt/script/v8c/v8c_callback_function.h"
#include "cobalt/script/v8c/v8c_callback_interface_holder.h"
#include "cobalt/script/v8c/v8c_exception_state.h"
#include "cobalt/script/v8c/v8c_global_environment.h"
#include "cobalt/script/v8c/v8c_value_handle.h"
#include "cobalt/script/v8c/wrapper_private.h"
#include "v8/include/v8.h"


namespace {
using cobalt::bindings::testing::SequenceUser;
using cobalt::bindings::testing::V8cSequenceUser;
using cobalt::bindings::testing::ArbitraryInterface;
using cobalt::bindings::testing::V8cArbitraryInterface;
using cobalt::script::CallbackInterfaceTraits;
using cobalt::script::GlobalEnvironment;
using cobalt::script::ScriptValue;
using cobalt::script::ValueHandle;
using cobalt::script::ValueHandle;
using cobalt::script::ValueHandleHolder;
using cobalt::script::Wrappable;

using cobalt::script::v8c::EntryScope;
using cobalt::script::v8c::EscapableEntryScope;
using cobalt::script::v8c::FromJSValue;
using cobalt::script::v8c::InterfaceData;
using cobalt::script::v8c::kConversionFlagClamped;
using cobalt::script::v8c::kConversionFlagNullable;
using cobalt::script::v8c::kConversionFlagObjectOnly;
using cobalt::script::v8c::kConversionFlagRestricted;
using cobalt::script::v8c::kConversionFlagTreatNullAsEmptyString;
using cobalt::script::v8c::kConversionFlagTreatUndefinedAsEmptyString;
using cobalt::script::v8c::kNoConversionFlags;
using cobalt::script::v8c::ToJSValue;
using cobalt::script::v8c::TypeTraits;
using cobalt::script::v8c::V8cExceptionState;
using cobalt::script::v8c::V8cGlobalEnvironment;
using cobalt::script::v8c::WrapperFactory;
using cobalt::script::v8c::WrapperPrivate;

v8::Local<v8::Object> DummyFunctor(v8::Isolate*, const scoped_refptr<Wrappable>&) {
  NOTIMPLEMENTED();
  return {};
}

}  // namespace

namespace cobalt {
namespace bindings {
namespace testing {


namespace {



void Constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  V8cExceptionState exception_state(isolate);
  if (!info.IsConstructCall()) {
    exception_state.SetSimpleException(script::kTypeError, "Illegal constructor");
    return;
  }

  scoped_refptr<SequenceUser> new_object =
      new SequenceUser();
  v8::Local<v8::Value> result_value;
  ToJSValue(isolate, new_object, &result_value);
  DCHECK(result_value->IsObject());
  info.GetReturnValue().Set(result_value);
}




void getInterfaceSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();

  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->GetInterfaceSequence(),
              &result_value);
  }
  if (!exception_state.is_exception_set()) {
    info.GetReturnValue().Set(result_value);
  }

}



void getInterfaceSequenceSequenceSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();

  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->GetInterfaceSequenceSequenceSequence(),
              &result_value);
  }
  if (!exception_state.is_exception_set()) {
    info.GetReturnValue().Set(result_value);
  }

}



void getLongSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();

  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->GetLongSequence(),
              &result_value);
  }
  if (!exception_state.is_exception_set()) {
    info.GetReturnValue().Set(result_value);
  }

}



void getStringSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();

  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->GetStringSequence(),
              &result_value);
  }
  if (!exception_state.is_exception_set()) {
    info.GetReturnValue().Set(result_value);
  }

}



void getStringSequenceSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();

  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->GetStringSequenceSequence(),
              &result_value);
  }
  if (!exception_state.is_exception_set()) {
    info.GetReturnValue().Set(result_value);
  }

}



void getUnionOfStringAndStringSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();

  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->GetUnionOfStringAndStringSequence(),
              &result_value);
  }
  if (!exception_state.is_exception_set()) {
    info.GetReturnValue().Set(result_value);
  }

}



void getUnionSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();

  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->GetUnionSequence(),
              &result_value);
  }
  if (!exception_state.is_exception_set()) {
    info.GetReturnValue().Set(result_value);
  }

}



void setInterfaceSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<::cobalt::script::Sequence< scoped_refptr<ArbitraryInterface> > >::ConversionType elements;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &elements);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->SetInterfaceSequence(elements);
  result_value = v8::Undefined(isolate);

}



void setInterfaceSequenceSequenceSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<::cobalt::script::Sequence< ::cobalt::script::Sequence< ::cobalt::script::Sequence< scoped_refptr<ArbitraryInterface> > > > >::ConversionType elements;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &elements);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->SetInterfaceSequenceSequenceSequence(elements);
  result_value = v8::Undefined(isolate);

}



void setLongSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<::cobalt::script::Sequence< int32_t > >::ConversionType elements;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &elements);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->SetLongSequence(elements);
  result_value = v8::Undefined(isolate);

}



void setStringSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<::cobalt::script::Sequence< std::string > >::ConversionType elements;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &elements);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->SetStringSequence(elements);
  result_value = v8::Undefined(isolate);

}



void setStringSequenceSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<::cobalt::script::Sequence< ::cobalt::script::Sequence< std::string > > >::ConversionType elements;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &elements);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->SetStringSequenceSequence(elements);
  result_value = v8::Undefined(isolate);

}



void setUnionOfStringAndStringSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<::cobalt::script::UnionType2<std::string, ::cobalt::script::Sequence< std::string > > >::ConversionType elements;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &elements);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->SetUnionOfStringAndStringSequence(elements);
  result_value = v8::Undefined(isolate);

}



void setUnionSequenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.This();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<SequenceUser>())) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  SequenceUser* impl =
      wrapper_private->wrappable<SequenceUser>().get();
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<::cobalt::script::Sequence< ::cobalt::script::UnionType2<std::string, scoped_refptr<ArbitraryInterface> > > >::ConversionType elements;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &elements);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->SetUnionSequence(elements);
  result_value = v8::Undefined(isolate);

}


void InitializeTemplateAndInterfaceObject(v8::Isolate* isolate, InterfaceData* interface_data) {
  v8::Local<v8::FunctionTemplate> function_template = v8::FunctionTemplate::New(isolate);
  function_template->SetClassName(
    v8::String::NewFromUtf8(isolate, "SequenceUser",
        v8::NewStringType::kInternalized).ToLocalChecked());
  v8::Local<v8::ObjectTemplate> instance_template = function_template->InstanceTemplate();
  instance_template->SetInternalFieldCount(WrapperPrivate::kInternalFieldCount);


  v8::Local<v8::ObjectTemplate> prototype_template = function_template->PrototypeTemplate();



  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, getInterfaceSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "getInterfaceSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, getInterfaceSequenceSequenceSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "getInterfaceSequenceSequenceSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, getLongSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "getLongSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, getStringSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "getStringSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, getStringSequenceSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "getStringSequenceSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, getUnionOfStringAndStringSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "getUnionOfStringAndStringSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, getUnionSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "getUnionSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, setInterfaceSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "setInterfaceSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, setInterfaceSequenceSequenceSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "setInterfaceSequenceSequenceSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, setLongSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "setLongSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, setStringSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "setStringSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, setStringSequenceSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "setStringSequenceSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, setUnionOfStringAndStringSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "setUnionOfStringAndStringSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }

  {
    v8::Local<v8::FunctionTemplate> method_template = v8::FunctionTemplate::New(isolate, setUnionSequenceMethod);
    method_template->RemovePrototype();
    prototype_template->Set(
        v8::String::NewFromUtf8(
            isolate,
            "setUnionSequence",
            v8::NewStringType::kInternalized).ToLocalChecked(),
        method_template);
  }


  interface_data->function_template.Set(isolate, function_template);
}

inline InterfaceData* GetInterfaceData(V8cGlobalEnvironment* global_environment) {
  const int kInterfaceUniqueId = 43;
  // By convention, the |V8cGlobalEnvironment| that we are associated with
  // will hold our |InterfaceData| at index |kInterfaceUniqueId|, as we asked
  // for it to be there in the first place, and could not have conflicted with
  // any other interface.
  return global_environment->GetInterfaceData(kInterfaceUniqueId);
}

}  // namespace

v8::Local<v8::Object> V8cSequenceUser::CreateWrapper(v8::Isolate* isolate, const scoped_refptr<Wrappable>& wrappable) {
  EscapableEntryScope entry_scope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  InterfaceData* interface_data = GetInterfaceData(global_environment);
  if (interface_data->function_template.IsEmpty()) {
    InitializeTemplateAndInterfaceObject(isolate, interface_data);
  }
  DCHECK(!interface_data->function_template.IsEmpty());

  v8::Local<v8::FunctionTemplate> function_template = interface_data->function_template.Get(isolate);
  DCHECK(function_template->InstanceTemplate()->InternalFieldCount() == WrapperPrivate::kInternalFieldCount);
  v8::Local<v8::Object> object = function_template->InstanceTemplate()->NewInstance(context).ToLocalChecked();
  DCHECK(object->InternalFieldCount() == WrapperPrivate::kInternalFieldCount);

  // This |WrapperPrivate|'s lifetime will be managed by V8.
  new WrapperPrivate(isolate, wrappable, object);
  return entry_scope.Escape(object);
}

v8::Local<v8::FunctionTemplate> V8cSequenceUser::CreateTemplate(v8::Isolate* isolate) {
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  InterfaceData* interface_data = GetInterfaceData(global_environment);
  if (interface_data->function_template.IsEmpty()) {
    InitializeTemplateAndInterfaceObject(isolate, interface_data);
  }

  return interface_data->function_template.Get(isolate);
}


}  // namespace testing
}  // namespace bindings
}  // namespace cobalt

