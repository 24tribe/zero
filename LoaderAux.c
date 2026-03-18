#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <tlhelp32.h>
#include <synchapi.h>

int LoadGameEx(const wchar_t *exe_path, const wchar_t *dll_path) {
    HMODULE hKernel32 = GetModuleHandleA("Kernel32");

    if (!hKernel32) {
        fputs("GetModuleHandle failed", stderr);
        return 1;
    }

    LPTHREAD_START_ROUTINE LoadLibraryWPtr = (LPTHREAD_START_ROUTINE)(uintptr_t)GetProcAddress(
        hKernel32, "LoadLibraryW"
    );

    if (!LoadLibraryWPtr) {
        fputs("GetProcAddress failed", stderr);
        return 1;
    }

    STARTUPINFOW si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);

    size_t exe_path_len = wcslen(exe_path) + 1;
    wchar_t *exe_path_copy = malloc(sizeof(*exe_path_copy)*exe_path_len);
    memcpy(exe_path_copy, exe_path, sizeof(*exe_path_copy)*exe_path_len);

    BOOL ret = CreateProcessW(
        NULL, exe_path_copy, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi
    );

    if (!ret) {
        fputs("CreateProcessW failed\n", stderr);
        return 1;
    }

    size_t dll_path_len = wcslen(dll_path) + 1;
    size_t buffer_size = sizeof(wchar_t)*dll_path_len;

    HANDLE ph = pi.hProcess;
    LPVOID rb = VirtualAllocEx(
        ph, NULL, buffer_size, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE
    );

    if (!rb) {
        fputs("VirtualAllocEx failed", stderr);
        return 1;
    }

    if (!WriteProcessMemory(ph, rb, dll_path, buffer_size, NULL)) {
        fputs("WriteProcessMemory failed", stderr);
        return 1;
    }

    HANDLE zeroHookFinishEvent = CreateEventA(NULL, TRUE, FALSE, "zeroHookFinishEvent");
    ResetEvent(zeroHookFinishEvent);

    HANDLE rt = CreateRemoteThread(ph, NULL, 0, LoadLibraryWPtr, rb, 0, NULL);

    if (!rt) {
        fputs("CreateRemoteThread failed", stderr);
        return 1;
    }

    WaitForSingleObject(zeroHookFinishEvent, INFINITE);
    CloseHandle(zeroHookFinishEvent);

    ResumeThread(pi.hThread);

    CloseHandle(ph);

    return 0;
}