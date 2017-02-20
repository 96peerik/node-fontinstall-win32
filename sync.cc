#include <nan.h>
#include "fontinstaller.h"
#include "sync.h"
#include "V8Utils.h"

NAN_METHOD(InstallSync) {
  wstring filename = V8Utils::v8StrToWStr(info[0]->ToString());
  int err = InstallFont(filename);
  info.GetReturnValue().Set(err);
}

NAN_METHOD(UninstallSync) {
  wstring filename = V8Utils::v8StrToWStr(info[0]->ToString());
  bool err = UninstallFont(filename);
  info.GetReturnValue().Set(err);
}
