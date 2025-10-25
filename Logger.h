#ifndef STACK_TRACE_LOGGER_H_2025_09_09_06_23
#define STACK_TRACE_LOGGER_H_2025_09_09_06_23

#include "il2cpp_shared.h"

#include <sds.h>

sds CreateStackTracePath(const char *url);
void SaveStackTrace(sds url);
void InitLogger(void *GameAssembly);
void LogResponse(Il2CppObject *obj);
System_String_o *ConvertObjectToString(Il2CppObject *obj);
System_String_o *GetStackTrace(void);

#endif