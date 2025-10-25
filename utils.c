#include "utils.h"

#include "sds.h"

#include <windows.h>

#include <stdio.h>

sds sds16to8(const uint16_t *s, uint32_t size) {
    int len = WideCharToMultiByte(CP_UTF8, 0, s, size, 0, 0, 0, 0);
    sds res = sdsnewlen(NULL, len);
    WideCharToMultiByte(CP_UTF8, 0, s, size, res, len, 0, 0);
    return res;
}

void press_enter_to_continue() {
    printf("Press enter to continue...\n");
    char line[MY_LINE_SIZE];
    fgets(line, MY_LINE_SIZE, stdin);
}

void QueryPageInfo(HMODULE GameAssembly, ptrdiff_t offset) {
    MEMORY_BASIC_INFORMATION info;
    if (!VirtualQuery(((char *)GameAssembly) + offset, &info, sizeof(info))) {
        fputs("VirtualQuery failed\n", stdout);
        return;
    }
    printf("BaseAddress: %p\n", info.BaseAddress);
    printf("AllocationBase: %p\n", info.AllocationBase);
    printf("AllocationProtect: %lx\n", info.AllocationProtect);
    printf("RegionSize: %zu\n", info.RegionSize);
    printf("State: %lx\n", info.State);
    printf("Protect: %lx\n", info.Protect);
    printf("Type: %lx\n", info.Type);
}

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