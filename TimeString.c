#include "TimeString.h"

#include <sds.h>

#include <sysinfoapi.h>

sds GetTime(void) {
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    return sdscatprintf(
        sdsempty(),
        "%d_%d_%d_%d_%d_%d",
        (int)systemTime.wYear,
        (int)systemTime.wMonth,
        (int)systemTime.wDay,
        (int)systemTime.wHour,
        (int)systemTime.wMinute,
        (int)systemTime.wSecond
    );
}

// 2025-09-14T22:29:57Z
sds GetDateTime(void) {
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    return sdscatprintf(
        sdsempty(),
        "%d-%02d-%02dT%02d:%02d:%02dZ",
        (int)systemTime.wYear,
        (int)systemTime.wMonth,
        (int)systemTime.wDay,
        (int)systemTime.wHour,
        (int)systemTime.wMinute,
        (int)systemTime.wSecond
    );
}