#include <cstdlib>
#include "fontinstaller.h"
#include "windows.h"
#include "shlobj.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int InstallFont (wstring filename) {
  PWSTR path;
  HRESULT hr = SHGetKnownFolderPath(FOLDERID_Fonts, 0, NULL, &path);
  if FAILED(hr) return hr;
  wstring str(path);
  CoTaskMemFree(path);
  wstring sep = L"\\";
  wstring destination = str + sep + basename(filename);
  BOOL ok = CopyFileW(filename.c_str(), destination.c_str(), true);
  if (!ok) {
    int err = GetLastError();
    if (err != ERROR_FILE_EXISTS) return err;
  }

  int addedFonts = AddFontResourceW(destination.c_str());
  if (addedFonts != 0) return ERROR;

  SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
  return 0;
}

wstring basename(wstring filename) {
  wstring temp;
  vector<wstring> parts;
  wstringstream wss(filename);
  while (getline(wss, temp, L'\\'))
    parts.push_back(temp);
  return parts[parts.size() - 1];
}
