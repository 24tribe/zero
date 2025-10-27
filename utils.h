#ifndef UTILS_H_202506121437
#define UTILS_H_202506121437

#include "il2cpp_shared.h"

#include <windows.h>
#include <stdint.h>

#define MY_LINE_SIZE 4096

typedef char *sds;

void QueryPageInfo(HMODULE GameAssembly, ptrdiff_t offset);
sds sds16to8(const uint16_t *s, uint32_t size);
sds SlurpFile(const char *path);
char *ChangeLoggedInAtStr(sds data, const char *newValue);
void PutString(System_String_o *s);
sds System_String_toSds(System_String_o *s);
uint16_t *sds_utf8_to_utf16(sds s);

#endif