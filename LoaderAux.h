#ifndef LOADER_AUX_H_202601090813PM
#define LOADER_AUX_H_202601090813PM

#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

int LoadGameEx(const wchar_t *exe_path, const wchar_t *dll_path);
int LoadGame(const char *path, const char *dll_path);

#ifdef __cplusplus
}
#endif

#endif