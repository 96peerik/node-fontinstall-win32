#include "nan.h"
#include "V8Utils.h"
#include <sstream>
  
using namespace std;
using namespace v8;

namespace V8Utils {
  wstring v8StrToWStr(v8::Local<v8::String> s) {
    char *buf = new char[s->Length() + 1];
    s->WriteUtf8(buf);
    std::string str(buf);
    delete[] buf;
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
  }

// Create a string with last error message
std::string GetErrorStdStr(DWORD error)
{
  if (error)
  {
    LPVOID lpMsgBuf;
    DWORD bufLen = FormatMessage(
      FORMAT_MESSAGE_ALLOCATE_BUFFER |
      FORMAT_MESSAGE_FROM_SYSTEM |
      FORMAT_MESSAGE_IGNORE_INSERTS,
      NULL,
      error,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
      (LPTSTR)&lpMsgBuf,
      0, NULL);
    if (bufLen)
    {
      LPCSTR lpMsgStr = (LPCSTR)lpMsgBuf;
      std::string result(lpMsgStr, lpMsgStr + bufLen);

      LocalFree(lpMsgBuf);

      return result;
    }
  }
  return std::string();
}}

