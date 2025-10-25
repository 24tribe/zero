#include "utils.h"

#include "sds.h"

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