#include "StackTraceLogger.h"

#include <stdio.h>

int main(void) {
    sds path = CreateStackTracePath("https://man7.org/linux/man-pages/man3/fwrite.3p.html");
    printf("path: %s\n", path);
}