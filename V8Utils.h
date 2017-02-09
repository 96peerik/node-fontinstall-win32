#pragma once
#include <v8.h>

using namespace std;

namespace V8Utils {
  wstring v8StrToWStr(v8::Local<v8::String> s);
  void EmitChange(void* owner);
  void EmitError(void* owner, string message);
  std::string GetErrorStdStr(DWORD error);
}