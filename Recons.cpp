#include "peconv.h"

extern "C" {
    #include "Recons.h"
    #include "Section.h"
}

#include <iostream>
#include <vector>

extern "C" {
    NTAPI PIMAGE_NT_HEADERS RtlImageNtHeader(PVOID ModuleAddress);
}

int ChangeSections(BYTE *data) {
    PIMAGE_NT_HEADERS headers = RtlImageNtHeader(data);

    if (!headers) {
        printf("RtlImageNtHeader failed\n");
        return -1;
    }

    int numberOfSections = headers->FileHeader.NumberOfSections;

    printf("NumberOfSections: %d\n", numberOfSections);

    std::vector<Section> mySections;

    PIMAGE_SECTION_HEADER sections = IMAGE_FIRST_SECTION(headers);
    for (int i = 0; i < numberOfSections; ++i) {
        PIMAGE_SECTION_HEADER section = sections + i;
        Section mySection = {
            (const char *)section->Name,
            (unsigned long)section->PointerToRawData,
            section->SizeOfRawData,
            section->VirtualAddress,
            section->Misc.VirtualSize
        };
        mySections.push_back(mySection);
    }

    std::vector<Section> Result(mySections.size());

    FillUnknown(&Result[0], &mySections[0], mySections.size());

    sections = IMAGE_FIRST_SECTION(headers);

    for (int i = 0; i < numberOfSections; ++i) {
        PrintSection(&Result[i]);
        PIMAGE_SECTION_HEADER section = sections + i;
        section->PointerToRawData = Result[i].RawAddr;
        section->SizeOfRawData = Result[i].RawSize;
        section->VirtualAddress = Result[i].VirtualAddr;
        section->Misc.VirtualSize = Result[i].VirtualSize;
    }

    return 0;
}

extern "C" int DumpGameAssembly(const char *outpath, BYTE *buf, unsigned long smallSize, unsigned long long start_address) {
    if (ChangeSections(buf) < 0) {
        std::cout << "Failed to change sections\n";
        return -1;
    }

    auto dumpMode = peconv::PE_DUMP_UNMAP;

    if (!peconv::dump_pe(outpath, buf, smallSize, start_address, dumpMode)) {
        std::cout << "Failed to dump pe\n";
        return -1;
    }

    return 0;
}