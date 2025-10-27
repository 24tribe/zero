#include "stacktrace_path.h"

#include <ctype.h>

void EscapeSymbols(char *s) {
    while (*s) {
        if (!isalpha(*s)) {
            *s++ = '_';
        } else {
            s++;
        }
    }
}

sds CreateStackTracePath(const char *url) {
    sds myUrl = sdsnew(url);
    EscapeSymbols(myUrl);

    sds res = sdscatprintf(
        sdsempty(),
        "%s/%s.txt",
        STACKTRACES_PATH,
        myUrl
    );

    sdsfree(myUrl);

    return res;
}