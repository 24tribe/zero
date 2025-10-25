#include <MinHook.h>

#include <memoryapi.h>

#include <stdio.h>

typedef LPVOID (WINAPI *MAPVIEWOFFILE)(HANDLE, DWORD, DWORD, DWORD, SIZE_T);
typedef LPVOID (WINAPI *MAPVIEWOFFILEEX)(HANDLE, DWORD, DWORD, DWORD, SIZE_T, LPVOID);

MAPVIEWOFFILE fpMapViewOfFile = NULL;
MAPVIEWOFFILEEX fpMapViewOfFileEx = NULL;

LPVOID DetourMapViewOfFile(
    HANDLE hFileMappingObject,
    DWORD  dwDesiredAccess,
    DWORD  dwFileOffsetHigh,
    DWORD  dwFileOffsetLow,
    SIZE_T dwNumberOfBytesToMap
) {
    printf("DetourMapViewOfFile(dwNumberOfBytesToMap=%zu)\n", dwNumberOfBytesToMap);
    return fpMapViewOfFile(
        hFileMappingObject,
        dwDesiredAccess,
        dwFileOffsetHigh,
        dwFileOffsetLow,
        dwNumberOfBytesToMap
    );
}

LPVOID DetourMapViewOfFileEx(
    HANDLE hFileMappingObject,
    DWORD  dwDesiredAccess,
    DWORD  dwFileOffsetHigh,
    DWORD  dwFileOffsetLow,
    SIZE_T dwNumberOfBytesToMap,
    LPVOID lpBaseAddress
) {
    printf("DetourMapViewOfFileEx(dwNumberOfBytesToMap=%zu, lpBaseAddress=%p)\n",
           dwNumberOfBytesToMap, lpBaseAddress);
    return fpMapViewOfFileEx(
        hFileMappingObject,
        dwDesiredAccess,
        dwFileOffsetHigh,
        dwFileOffsetLow,
        dwNumberOfBytesToMap,
        lpBaseAddress
    );
}

void HookMapViewOfFile() {
    if (MH_CreateHook(&MapViewOfFile, &DetourMapViewOfFile, (PVOID *)&fpMapViewOfFile) != MH_OK) {
        fputs("MH_CreateHook MapViewOfFile failed\n", stdout);
        return;
    }

    if (MH_EnableHook(&MapViewOfFile, TRUE)) {
        fputs("MH_EnableHook MapViewOfFile failed\n", stdout);
        return;
    }

    if (MH_CreateHook(&MapViewOfFileEx, &DetourMapViewOfFileEx, (PVOID *)&fpMapViewOfFileEx) != MH_OK) {
        fputs("MH_CreateHook MapViewOfFileEx failed\n", stdout);
        return;
    }

    if (MH_EnableHook(&MapViewOfFileEx, TRUE)) {
        fputs("MH_EnableHook MapViewOfFileEx failed\n", stdout);
        return;
    }
}