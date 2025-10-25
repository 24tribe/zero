#include <windows.h>
#include <memoryapi.h>

#include <stdio.h>

#include <MinHook.h>

typedef LPVOID (WINAPI *VIRTUALALLOC)(LPVOID, SIZE_T, DWORD, DWORD);
typedef LPVOID (WINAPI *VIRTUALALLOCEX)(HANDLE, LPVOID, SIZE_T, DWORD, DWORD);

VIRTUALALLOC fpVirtualAlloc = NULL;
VIRTUALALLOCEX fpVirtualAllocEx = NULL;

LPVOID WINAPI DetourVirtualAlloc(LPVOID address, SIZE_T size, DWORD flAllocationType, DWORD flProt) {
    (void)flProt;
    printf("DetourVirtualAlloc called\n");
    return fpVirtualAlloc(address, size, flAllocationType, PAGE_EXECUTE_READWRITE);
}

LPVOID WINAPI DetourVirtualAllocEx(HANDLE hProcess, LPVOID address, SIZE_T size,
                                   DWORD flAllocationType, DWORD flProt) {
    (void)flProt;
    printf("DetourVirtualAllocEx called\n");
    return fpVirtualAllocEx(hProcess, address, size, flAllocationType, PAGE_EXECUTE_READWRITE);
}   

void HookVirtualAlloc() {
    if (MH_CreateHook(&VirtualAlloc, &DetourVirtualAlloc, (LPVOID*)&fpVirtualAlloc) != MH_OK) {
        fputs("CreateHook failed for VirtualAlloc\n", stdout);
        return;
    }

    if (MH_CreateHook(&VirtualAllocEx, &DetourVirtualAllocEx, (LPVOID*)&fpVirtualAllocEx) != MH_OK) {
        fputs("CreateHook failed for VirtualAllocEx\n", stdout);
        return;
    }

    if (MH_EnableHook(&VirtualAlloc, TRUE) != MH_OK) {
        fputs("EnableHook failed for VirtualAlloc\n", stdout);
        return;
    }

    if (MH_EnableHook(&VirtualAllocEx, TRUE) != MH_OK) {
        fputs("EnableHook failed for VirtualAllocEx\n", stdout);
        return;
    }
}
