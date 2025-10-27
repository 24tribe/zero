#ifndef UTILS_H_202506121437
#define UTILS_H_202506121437

#include "il2cpp_shared.h"

#include <windows.h>
#include <stdint.h>

#define MY_LINE_SIZE 4096

typedef char *sds;

sds SlurpFile(const char *path);
char *ChangeLoggedInAtStr(sds data, const char *newValue);
void PutString(System_String_o *s);
sds System_String_toSds(System_String_o *s);

#endif