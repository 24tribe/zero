#include "TimeUtil.h"

#include "windows.h"
#include "sysinfoapi.h"

uint64_t TimeUtil_GetTimeInMs(void) {
    FILETIME fileTime;
    GetSystemTimeAsFileTime(&fileTime);
    ULARGE_INTEGER result = {
        .LowPart = fileTime.dwLowDateTime,
        .HighPart = fileTime.dwHighDateTime
    };
    return (uint64_t)(result.QuadPart / 10000ULL);
}