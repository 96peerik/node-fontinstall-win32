#include <cstdlib>
#include "fontinstaller.h"
#include "windows.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int InstallFont (wstring filename) {
  int addedFonts = AddFontResourceW(filename.c_str());
  if (addedFonts != 0) return ERROR;

  SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
  return 0;
}

bool UninstallFont(wstring filename) {
  bool res = RemoveFontResourceW(filename.c_str());
  if (!res) return false;
  SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
  return true;
}