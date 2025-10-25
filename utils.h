#ifndef UTILS_H_202506121437
#define UTILS_H_202506121437

#include <windows.h>
#include <stdint.h>

#define MY_LINE_SIZE 4096

typedef char *sds;

void press_enter_to_continue();
void QueryPageInfo(HMODULE GameAssembly, ptrdiff_t offset);
sds sds16to8(const uint16_t *s, uint32_t size);
sds SlurpFile(const char *path);
char *ChangeLoggedInAtStr(sds data, const char *newValue);

#endif