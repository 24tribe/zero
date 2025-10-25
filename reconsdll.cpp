#include "peconv.h"

#include <stdio.h>

extern "C" {
#include "MetadataDump.h"
}

#define INT2VOIDP(i) (void*)(uintptr_t)(i)
#include <iostream>
int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cout << "Usage: reconsdll.exe ga.dump out.dll start_address mode\n";
        return 1;
    }
    char *ga_path = argv[1];
    char *outpath = argv[2];
    unsigned long long start_address = std::stoull(argv[3], nullptr, 0);
    peconv::t_pe_dump_mode dumpMode = (peconv::t_pe_dump_mode)atoi(argv[4]);

    printf("address: %p, dumpMode: %d\n", (void *)start_address, (int)dumpMode);

    long long size = GetMetadataSize(ga_path);
    if (size == LLONG_MAX || size > (long long)ULONG_MAX) {
        std::cout << "Invalid size\n";
        return 1;
    }
    unsigned long smallSize = (unsigned long)size;
    BYTE *buf = (BYTE *)ReadMetadata(ga_path, smallSize);
    if (!buf) {
        std::cout << "Failed to read game assembly dll\n";
        return 1;
    }

    if (!peconv::dump_pe(outpath, buf, smallSize, start_address, dumpMode)) {
        std::cout << "Failed to dump pe\n";
        return 1;
    }
}