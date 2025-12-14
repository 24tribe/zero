#ifndef TIME_UTIL_H_13_12_2025_07_02_PM
#define TIME_UTIL_H_13_12_2025_07_02_PM

#include "windows.h"
#include "sysinfoapi.h"

ULONGLONG GetFileTimeDiff(FILETIME tim1, FILETIME tim2);
ULONGLONG TimeDiffToMs(ULONGLONG timeDiff);

#endif