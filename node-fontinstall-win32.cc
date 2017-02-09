#include <nan.h>
#include "sync.h"
#include "async.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

NAN_MODULE_INIT(InitAll) {
  Set(target, New<String>("installSync").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(InstallSync)).ToLocalChecked());

  Set(target, New<String>("install").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(Install)).ToLocalChecked());
}

NODE_MODULE(FontInstaller, InitAll)
