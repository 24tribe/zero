#include "utils.h"
#include "TimeString.h"
#include "sds_utf_conv.h"

#include <sds.h>

#include <windows.h>

#include <stdio.h>

sds SlurpFile(const char *path) {    
    HANDLE hFile = CreateFileA(
        path, GENERIC_READ, FILE_SHARE_READ,
        NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        fputs("CreateFileA failed\n", stdout);
        return NULL;
    }

    LARGE_INTEGER size;

    if (!GetFileSizeEx(hFile, &size)) {
        fputs("GetFileSizeEx failed\n", stdout);
        return NULL;
    }

    sds res = sdsnewlen(NULL, size.QuadPart);

    unsigned long numberOfBytesRead;

    if (!ReadFile(hFile, res, size.QuadPart, &numberOfBytesRead, NULL)) {
        printf("ReadFile failed\n");
        sdsfree(res);
        return NULL;
    }

    if (numberOfBytesRead < size.QuadPart) {
        printf("Read less than the size of the file\n");
        sdsfree(res);
        return NULL;
    }
    
    return res;
}

sds System_String_toSds(System_String_o *s) {
    return sds16to8(&(s->fields._firstChar), s->fields._stringLength);
}