#ifndef STACKTRACE_PATH_H_27_10_2025_06_32
#define STACKTRACE_PATH_H_27_10_2025_06_32

#include <sds.h>

#define STACKTRACES_PATH "stacktraces"

sds CreateStackTracePath(const char *url);

#endif