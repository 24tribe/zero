#include "webview/webview.h"
#include <stddef.h>

#include <jansson.h>

#include <windows.h>
#include <commdlg.h>

#include <sstream>
#include <iostream>

#define CURRENT_DIR_SIZE 4096
#define EXE_PATH_SIZE 4096

static void initOpenInfo(OPENFILENAMEA* openInfo, char *exePath) {
  ZeroMemory(openInfo, sizeof(*openInfo));
  openInfo->lStructSize = sizeof(*openInfo);
  openInfo->lpstrFilter = "TRIBE NINE executable\0tribenine.exe\0\0";
  openInfo->lpstrFile = exePath;
  openInfo->nMaxFile = EXE_PATH_SIZE;
  openInfo->Flags = OFN_FILEMUSTEXIST;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow) {
  (void)hInst;
  (void)hPrevInst;
  (void)lpCmdLine;
  (void)nCmdShow;
  webview_t w = webview_create(1, NULL);
  webview_set_title(w, "Tribe Nine Launcher");
  webview_set_size(w, 720, 480, WEBVIEW_HINT_NONE);

  webview_bind(w, "selectTribeNineExePath", [](const char *id, const char *req, void *arg) {
    (void)req;
    webview_t wv = reinterpret_cast<webview_t>(arg);
    OPENFILENAMEA openInfo;
    char exePath[EXE_PATH_SIZE] = {0};
    initOpenInfo(&openInfo, exePath);

    // FIXME: this should be GetOpenFileNameW
    if (GetOpenFileNameA(&openInfo)) {
      json_t *value = json_string(exePath);
      char *s = json_dumps(value, JSON_ENCODE_ANY);
      webview_return(wv, id, 0, s);
      free(s);
      json_decref(value);
    } else {
      webview_return(wv, id, 1, "");
    }
  }, w);

  char current_dir[CURRENT_DIR_SIZE];
  // FIXME: this should be GetCurrentDirectoryW
  if (GetCurrentDirectoryA(CURRENT_DIR_SIZE, current_dir) == 0) {
    return 0;
  }

  std::stringstream index_path;
  index_path << "file:///" << current_dir << "/index.html";
  webview_navigate(w, index_path.str().c_str());
  webview_run(w);
  webview_destroy(w);
  return 0;
}