#ifndef UTILS_H_202506121437
#define UTILS_H_202506121437

#include <windows.h>

#define MY_LINE_SIZE 4096

void WideToUtf8(char *out, LPCWSTR in);
void press_enter_to_continue();
void QueryPageInfo(HMODULE GameAssembly, ptrdiff_t offset);

#endif