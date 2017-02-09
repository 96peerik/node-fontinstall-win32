#include <nan.h>
#include "fontinstaller.h"
#include "async.h"
#include "V8Utils.h"

using v8::Function;
using v8::Local;
using v8::Number;
using v8::Value;
using v8::String;
using Nan::AsyncQueueWorker;
using Nan::AsyncWorker;
using Nan::Callback;
using Nan::HandleScope;
using Nan::New;
using Nan::Null;
using Nan::To;

class FontInstallerWorker : public AsyncWorker {
 public:
  FontInstallerWorker(Callback *callback, std::wstring filename)
    : AsyncWorker(callback), filename(filename), res(-1) {}
  ~FontInstallerWorker() {}

  // Executed in worker thd
  void Execute () {
    res = InstallFont(filename);
    if (res != 0) {
      SetErrorMessage(V8Utils::GetErrorStdStr(res).c_str());
    }
  }

  // Executed in main thd
  void HandleOKCallback () {
    HandleScope scope;

    Local<Value> argv[] = {
        Null()
    };

    callback->Call(1, argv);
  }

  void HandleErrorCallback() {
    HandleScope scope;
    Local<Value> argv[] = {
      Nan::Error(Nan::New<v8::String>(ErrorMessage()).ToLocalChecked())
    };

    callback->Call(1, argv);
  }

private:
  wstring filename;
  int res;
};

// Asynchronous access
NAN_METHOD(Install) {
  std::wstring filename = V8Utils::v8StrToWStr(info[0]->ToString());
  Callback *callback = new Callback(info[1].As<Function>());

  AsyncQueueWorker(new FontInstallerWorker(callback, filename));
}
