#include "Recons.h"
#include "MetadataDump.h"

#include <windows.h>

#include <stdio.h>
#include <stdlib.h>

#define MY_SIZE 4096

int Il2CppDumper(char *dll_path, char *metadata_path, char *output_path) {
    STARTUPINFO si = {.cb = sizeof(si)};
    PROCESS_INFORMATION pi = {0};

    char cmdline[MY_SIZE] = {0};
    /*
    usage: Il2CppDumper <executable-file> <global-metadata> <output-directory>
    */
    snprintf(
        cmdline,
        MY_SIZE,
        "D:/tribenine/Il2CppDumper/Il2CppDumper/bin/Debug/net8.0/Il2CppDumper.exe"
        " \"%s\" \"%s\" \"%s\\\"",
        dll_path,
        metadata_path,
        output_path
    );

    printf("cmdline: %s\n", cmdline);

    if (!CreateProcess(
        NULL, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi
    )) {
        return -1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD res;
    GetExitCodeProcess(pi.hProcess, &res);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return res;
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fputs(
            "Usage: Bruteforce.exe metadata_path data_section_start data_section_end module_start module_dump_path\n",
            stderr
        );
        return 1;
    }

    char *metadata_path = argv[1];
    unsigned long data_section_start = strtoul(argv[2], NULL, 10);
    unsigned long data_section_end = strtoul(argv[3], NULL, 10);
    unsigned long long module_start = strtoull(argv[4], NULL, 10);
    char *module_dump_path = argv[5];

    printf("metadata_path: %s\n", metadata_path);
    printf("data_section_start: 0x%lx\n", data_section_start);
    printf("data_section_end: 0x%lx\n", data_section_end);
    printf("module_start: 0x%llx\n", module_start);
    printf("module_dump_path: %s\n", module_dump_path);

    if (data_section_start % 0x200 != 0) {
        printf("error: data_section_start not aligned to 0x200\n");
        return 1;
    }

    unsigned long long module_dump_size = GetMetadataSize(module_dump_path);
    if (module_dump_size == LLONG_MAX) {
        fputs("error: getmetadatasize failed\n", stderr);
        return 1;
    }

    BYTE *module_dump = ReadMetadata(module_dump_path, module_dump_size);

    if (!module_dump) {
        fputs("error: readmetadata failed\n", stderr);
        return 1;
    }
    
    printf("Press enter to start...\n");
    fgets((char[10]){0}, 10, stdin);

    char temp_path[MY_SIZE] = {0};
    GetTempPathA(MY_SIZE, temp_path);

    for (unsigned long size = data_section_start; size < data_section_end; size += 0x200) {
        printf("Trying 0x%lx...\n", size);
        
        char output_path[MY_SIZE] = {0};
        snprintf(output_path, MY_SIZE, "%sil2cpp-%lx", temp_path, size);
        printf("output_path: %s\n", output_path);

        char ga_path[MY_SIZE] = {0};
        snprintf(ga_path, MY_SIZE, "%sGA-%lx.dll", temp_path, size);
        printf("ga_path: %s\n", ga_path);

        if (DumpGameAssembly(ga_path, module_dump, module_dump_size, module_start, size) < 0) {
            fputs("DumpGameAssembly failed\n", stderr);
            return 1;
        }

        int dumper_res = Il2CppDumper(ga_path, metadata_path, output_path);

        /*
        if (!dumper_res) {
            printf("Success with .data rawsize: %lx\n", size);
            return 0;
        } else if (dumper_res < 0) {
            printf("Failed to call il2cppdumper\n");
            return 1;
        }
        */
    }
}