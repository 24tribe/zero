#include "utils.h"
#include "funcs.h"

#include <MinHook.h>

#include <windows.h>
#include <stdio.h>
#include <memoryapi.h>

typedef HANDLE (WINAPI *CREATEFILEMAPPINGA)(
    HANDLE                hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    DWORD                 flProtect,
    DWORD                 dwMaximumSizeHigh,
    DWORD                 dwMaximumSizeLow,
    LPCSTR                lpName
);

typedef HANDLE (WINAPI *CREATEFILEMAPPINGW)(
    HANDLE                hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    DWORD                 flProtect,
    DWORD                 dwMaximumSizeHigh,
    DWORD                 dwMaximumSizeLow,
    LPCWSTR               lpName
);

CREATEFILEMAPPINGA fpCreateFileMappingA = NULL;
CREATEFILEMAPPINGW fpCreateFileMappingW = NULL;

WINAPI HANDLE DetourCreateFileMappingA(
    HANDLE                hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    DWORD                 flProtect,
    DWORD                 dwMaximumSizeHigh,
    DWORD                 dwMaximumSizeLow,
    LPCSTR                lpName
) {
    printf("CreateFileMappingA(flProtect=%ld)\n", flProtect);
    return fpCreateFileMappingA(
        hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName
    );
}

WINAPI HANDLE DetourCreateFileMappingW(
    HANDLE                hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    DWORD                 flProtect,
    DWORD                 dwMaximumSizeHigh,
    DWORD                 dwMaximumSizeLow,
    LPCWSTR               lpName
) {
    printf("CreateFileMappingW(flProtect=%ld)\n", flProtect);
    return fpCreateFileMappingW(
        hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName
    );
}

int main(void) {
    if (MH_Initialize() != MH_OK) {
        printf("MinHook failed\n");
        return 1;
    }

    if (MH_CreateHook(&CreateFileMappingA, &DetourCreateFileMappingA, (LPVOID *)&fpCreateFileMappingA) != MH_OK) {
        printf("MH_CreateHook CreateFileMappingA failed\n");
        return 1;
    }

    if (MH_CreateHook(&CreateFileMappingW, &DetourCreateFileMappingW, (LPVOID *)&fpCreateFileMappingW) != MH_OK) {
        printf("MH_CreateHook CreateFileMappingW failed\n");
        return 1;
    }

    if (MH_EnableHook(&CreateFileMappingA, TRUE) != MH_OK) {
        printf("MH_EnableHook CreateFileMappingA failed\n");
        return 1;
    }

    if (MH_EnableHook(&CreateFileMappingW, TRUE) != MH_OK) {
        printf("MH_EnableHook CreateFileMappingW failed\n");
        return 1;
    }

    HANDLE steam_api64 = LoadLibraryA("D:\\tribenine\\dllinj\\steam_api64.dll");
    
    PIMAGE_NT_HEADERS headers = RtlImageNtHeader(steam_api64);

    if (!headers) {
        printf("RtlImageNtHeader failed\n");
        return 1;
    }

    if (!steam_api64) {
        printf("LoadLibraryA failed: %ld\n", (long)GetLastError());
        return 1;
    }

    printf("steam_api64.dll location: %p\n", (void *)steam_api64);
    printf(".text location: %p\n", (char *)steam_api64 + 0x1000);
    
    MEMORY_BASIC_INFORMATION info;
    if (!VirtualQuery((void*)steam_api64, &info, sizeof(info))) {
        fputs("VirtualQuery failed\n", stdout);
        return;
    }
    
    printf("AllocationBase: %p\n", info.AllocationBase);
    printf("RegionSize: %zu\n", info.RegionSize);
    
    LARGE_INTEGER regionSize = {.QuadPart = (info.RegionSize & ~(ULONG)0xffff)+0x10000};

    HANDLE sectionHandle;
    if (NtCreateSection(&sectionHandle,
                        SECTION_MAP_READ | SECTION_MAP_WRITE | SECTION_MAP_EXECUTE,
                        NULL,
                        &regionSize,
                        PAGE_EXECUTE_READWRITE, SEC_COMMIT, NULL))
    {
        printf("NtCreateSection failed\n");
        return 1;
    }

    void *localSectionAddress = NULL;

    ULONG size = info.RegionSize;

    NTSTATUS status;

    if ((status = NtMapViewOfSection(
        sectionHandle, GetCurrentProcess(),
        &localSectionAddress, NULL, NULL, NULL, &size, 2, NULL, PAGE_EXECUTE_READWRITE))) {
        printf("NtMapViewOfSection failed: %lx\n", status);
        return 1;
    }

    memcpy(localSectionAddress, steam_api64, info.RegionSize);
    
    NtUnmapViewOfSection(NtCurrentProcess(), (void *)steam_api64);

    void *newAddr = (void *)steam_api64;

    if ((status = NtMapViewOfSection(
        sectionHandle, GetCurrentProcess(), &newAddr,
         0, 0, NULL, &size, 2, MEM_COMMIT, PAGE_EXECUTE_READWRITE))) {
        printf("NtMapViewOfSection2 failed: %lx\n", status);
        return;
    }

    press_enter_to_continue();

    

    fputs("OK\n", stdout);

    

    press_enter_to_continue();
}