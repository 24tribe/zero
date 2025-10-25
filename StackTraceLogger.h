#ifndef STACK_TRACE_LOGGER_H_2025_09_09_06_23
#define STACK_TRACE_LOGGER_H_2025_09_09_06_23

#include <sds.h>

sds CreateStackTracePath(const char *url);
void SaveStackTrace(sds url);
void InitStackTraceLogger(void *GameAssembly);

#endif