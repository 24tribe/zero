#include "../LoaderAux.h"

#include "webview/webview.h"
#include <stddef.h>

#include <jansson.h>

#include <windows.h>
#include <commdlg.h>

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#define CURRENT_DIR_SIZE 2048
#define EXE_PATH_SIZE 2048

std::wstring UTF8StringToUTF16(std::string s) {
    int nLenWide = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), s.size(), NULL, 0);
    std::vector<wchar_t> res(nLenWide + 1);
    res[nLenWide] = 0;
    MultiByteToWideChar(CP_UTF8, 0, s.c_str(), s.size(), &(res[0]), nLenWide);
    return std::wstring(&(res[0]));
}

std::string UTF16StringToUTF8(std::wstring s) {
    int len = WideCharToMultiByte(CP_UTF8, 0, s.c_str(), s.size(), 0, 0, 0, 0);
    std::vector<char> res(len + 1);
    res[len] = 0;
    WideCharToMultiByte(CP_UTF8, 0, s.c_str(), s.size(), &(res[0]), len, 0, 0);
    return std::string(&(res[0]));
}

static void initOpenInfo(OPENFILENAMEW* openInfo, wchar_t *exePath) {
  ZeroMemory(openInfo, sizeof(*openInfo));
  openInfo->lStructSize = sizeof(*openInfo);
  openInfo->lpstrFilter = L"TRIBE NINE executable\0tribenine.exe\0\0";
  openInfo->lpstrFile = exePath;
  openInfo->nMaxFile = EXE_PATH_SIZE;
  openInfo->Flags = OFN_FILEMUSTEXIST;
}

wchar_t CURRENT_DIR[CURRENT_DIR_SIZE];

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow) {
  (void)hInst;
  (void)hPrevInst;
  (void)lpCmdLine;
  (void)nCmdShow;

  if (GetCurrentDirectoryW(CURRENT_DIR_SIZE, CURRENT_DIR) == 0) {
    return 0;
  }

  webview_t w = webview_create(1, NULL);
  webview_set_title(w, "Tribe Nine Launcher");
  webview_set_size(w, 720, 480, WEBVIEW_HINT_NONE);

  webview_bind(w, "selectTribeNineExePath", [](const char *id, const char *req, void *arg) {
    (void)req;
    webview_t wv = reinterpret_cast<webview_t>(arg);
    OPENFILENAMEW openInfo;
    wchar_t exePath[EXE_PATH_SIZE] = {0};
    initOpenInfo(&openInfo, exePath);

    if (GetOpenFileNameW(&openInfo)) {
      std::string exePathUtf8 = UTF16StringToUTF8(std::wstring(exePath));
      json_t *value = json_string(exePathUtf8.c_str());
      char *s = json_dumps(value, JSON_ENCODE_ANY);
      webview_return(wv, id, 0, s);
      free(s);
      json_decref(value);
    } else {
      webview_return(wv, id, 1, "");
    }
  }, w);

  webview_bind(w, "launchTribeNine", [](const char *id, const char *req, void *arg) {
    webview_t wv = reinterpret_cast<webview_t>(arg);
    json_t *jsonReq = json_loads(req, 0, NULL);
    if (!jsonReq || json_array_size(jsonReq) == 0) {
      webview_return(wv, id, 1, "");
      return;
    }

    const char *exePath = json_string_value(json_array_get(jsonReq, 0));

    if (!exePath) {
      webview_return(wv, id, 1, "");
      return;
    }

    std::wstring exePathW = UTF8StringToUTF16(std::string(exePath));

    std::wstring dllPath{CURRENT_DIR};
    dllPath.append(L"/libzero.dll");

    LoadGameEx(exePathW.c_str(), dllPath.c_str());

    webview_terminate(wv);
  }, w);


  std::wstringstream index_path_ss;
  index_path_ss << L"file:///" << CURRENT_DIR << L"/index.html";
  std::string index_path = UTF16StringToUTF8(index_path_ss.str());
  webview_navigate(w, index_path.c_str());
  webview_run(w);
  webview_destroy(w);
  return 0;
}