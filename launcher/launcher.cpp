#include "webview/webview.h"
#include <stddef.h>

#include <windows.h>

#include <sstream>

#define CURRENT_DIR_SIZE 4096

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow) {
  (void)hInst;
  (void)hPrevInst;
  (void)lpCmdLine;
  (void)nCmdShow;
  webview_t w = webview_create(1, NULL);
  webview_set_title(w, "Tribe Nine Launcher");
  webview_set_size(w, 720, 480, WEBVIEW_HINT_NONE);
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