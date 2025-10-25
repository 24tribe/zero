#include "RemapMem.h"

#include <stdio.h>

typedef void (*myHellorld)(void);

int main()
{
	InitRemapMem();

    char line[1024];
    HANDLE steam_api64 = LoadLibraryA("D:\\tribenine\\dllinj\\testingdll.dll");

    if (!steam_api64) {
        puts("NOOO");
        return 1;
    }

    myHellorld fHellorld = (void *)(GetProcAddress(steam_api64,
     "Hellorld"));

    printf("Hellord addr: %p\n", (void *)fHellorld);

	unsigned long long size = CalcDLLSize(steam_api64);

    if (size == ULLONG_MAX) {
        printf("CalcDLLSize failed\n");
        return 1;
    }

    printf("Full Region Size: 0x%llx\n", size);

    printf("Before Remap:\n");
    fHellorld();

    puts("Press enter...");
    fgets(line, 1024, stdin);

	if (RemapViewOfSection(GetCurrentProcess(), (void*)steam_api64, size, PAGE_EXECUTE_READWRITE)) {
        printf("DETOUR: Remap success!\n");
    }

    printf("After Remap:\n");
    fHellorld();

    puts("Press enter...");
    fgets(line, 1024, stdin);

    return 0;
}