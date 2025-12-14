#include "TimeUtil.h"

ULONGLONG GetFileTimeDiff(FILETIME tim1, FILETIME tim2) {
    ULARGE_INTEGER res = {
        .LowPart = tim1.dwLowDateTime - tim2.dwLowDateTime,
        .HighPart = tim1.dwHighDateTime - tim2.dwHighDateTime
    };
    return res.QuadPart;
}

ULONGLONG TimeDiffToMs(ULONGLONG timeDiff) {
    return timeDiff / 10000ull;
}