#ifndef STACK_TRACE_LOGGER_H_2025_09_09_06_23
#define STACK_TRACE_LOGGER_H_2025_09_09_06_23

#include "il2cpp_shared.h"

#include <sds.h>

sds CreateStackTracePath(const char *url);
void SaveStackTrace(sds url);
System_String_o *ConvertObjectToString(Il2CppObject *obj);
System_String_o *GetStackTrace(void);
void GetNameAndNamespaze(Il2CppObject *obj, const char **name, const char **namespaze);

#endif