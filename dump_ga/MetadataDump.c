#include "MetadataDump.h"

#include <windows.h>
#include <fileapi.h>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>



long long GetMetadataSize(char *path) {
    HANDLE hFile = CreateFileA(
        path, GENERIC_READ, FILE_SHARE_READ,
        NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        fputs("CreateFileA failed\n", stdout);
        return LLONG_MAX;
    }

    LARGE_INTEGER size;

    if (!GetFileSizeEx(hFile, &size)) {
        fputs("GetFileSizeEx failed\n", stdout);
        return LLONG_MAX;
    }

    CloseHandle(hFile);

    return size.QuadPart;
}

bool SaveMetadata(char *path, BYTE *buf, unsigned long smallSize) {
    HANDLE hFile = CreateFileA(
        path, GENERIC_WRITE, 0,
        NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        fputs("CreateFileA failed\n", stdout);
        return false;
    }

    unsigned long numberOfBytesWritten;

    bool ret = true;

    if (!WriteFile(hFile, buf, smallSize, &numberOfBytesWritten, NULL)) {
        fputs("WriteFile failed\n", stdout);
        ret = false;
    }

    if (numberOfBytesWritten != smallSize) {
        fputs("numberOfBytesWritten != size\n", stdout);
        ret = false;
    }

    if (!CloseHandle(hFile)) {
        fputs("Failed to close file handle\n", stdout);
        ret = false;
    }

    return ret;
}

bool IsMetadata(BYTE *buf) {
    BYTE METADATA_SIG[] = {0xaf, 0x1b, 0xb1, 0xfa};

    return (buf[0] == METADATA_SIG[0])
           && (buf[1] == METADATA_SIG[1])
           && (buf[2] == METADATA_SIG[2])
           && (buf[3] == METADATA_SIG[3]);
}

BYTE *ReadMetadata(const char *filename, unsigned long smallSize) {
    

    HANDLE hMetadata = CreateFileA(
        filename, GENERIC_READ, FILE_SHARE_READ, 
        NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    );

    if (hMetadata == INVALID_HANDLE_VALUE) {
        fputs("Failed to open metadata\n", stdout);
        return NULL;
    }

    void *buf = malloc(smallSize);

    if (!buf) {
        fputs("Malloc failed\n", stdout);
        return NULL;
    }

    unsigned long numberOfBytesRead;

    if (!ReadFile(hMetadata, buf, smallSize, &numberOfBytesRead, NULL)) {
        printf("ReadFile failed\n");
        free(buf);
        return NULL;
    }

    if (numberOfBytesRead < smallSize) {
        printf("Read less than the size of the file\n");
        free(buf);
        return NULL;
    }
    
    return (BYTE *)buf;
}

