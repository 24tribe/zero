#include "utils.h"

#include <stdio.h>

void WideToUtf8(char *out, LPCWSTR in) {
    int len = WideCharToMultiByte(CP_UTF8, 0, in, -1, 0, 0, 0, 0);
    WideCharToMultiByte(CP_UTF8, 0, in, -1, out, len, 0, 0);
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