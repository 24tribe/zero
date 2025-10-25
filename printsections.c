#include "MetadataDump.h"

#include <windows.h>
#include <ntdef.h>

#include <stdio.h>
#include <limits.h>
#include <math.h>

NTAPI PIMAGE_NT_HEADERS RtlImageNtHeader(PVOID ModuleAddress);

void PrintSection(PIMAGE_SECTION_HEADER section) {
    unsigned char *sectionName = section->Name;
    printf("SectionName: %c%c%c%c%c%c%c%c\n",
            sectionName[0], sectionName[1], sectionName[2], sectionName[3],
            sectionName[4], sectionName[5], sectionName[6], sectionName[7]);
    printf(" Misc.PhysicalAddress: 0x%lx\n", section->Misc.PhysicalAddress);
    printf(" Misc.VirtualSize: 0x%lx\n", section->Misc.VirtualSize);
    printf(" VirtualAddress: 0x%lx\n", section->VirtualAddress);
    printf(" SizeOfRawData: 0x%lx\n", section->SizeOfRawData);
    printf(" PointerToRawData: 0x%lx\n", section->PointerToRawData);
    printf(" PointerToRelocations: 0x%lx\n", section->PointerToRelocations);
    printf(" PointerToLinenumbers: 0x%lx\n", section->PointerToLinenumbers);
    printf(" NumberOfRelocations: %d\n", section->NumberOfRelocations);
    printf(" NumberOfLinenumbers: %d\n", section->NumberOfLinenumbers);
    printf(" Characteristics: 0x%lx\n", section->Characteristics);
}


// printf("Name,RawAddr,RawSize,VirtualAddr,VirtualSize\n");

void PrintSection2(PIMAGE_SECTION_HEADER section) {
    unsigned char *sectionName = section->Name;
    if (!memchr(sectionName, 0, 8)) {
        fputs("sectionName is not a c-string\n", stderr);
        exit(1);
    }

    printf(
        "%s,%lx,%lx,%lx,%lx\n",
        sectionName, (unsigned long)(section->PointerToRawData),
        section->SizeOfRawData, section->VirtualAddress, section->Misc.VirtualSize
    );
}

void PrintSections(void *data) {
    PIMAGE_NT_HEADERS headers = RtlImageNtHeader(data);

    if (!headers) {
        printf("RtlImageNtHeader failed\n");
        return;
    }

    int numberOfSections = headers->FileHeader.NumberOfSections;

    printf("NumberOfSections: %d\n", numberOfSections);


    PIMAGE_SECTION_HEADER sections = IMAGE_FIRST_SECTION(headers);
    for (int i = 0; i < numberOfSections; ++i) {
        PIMAGE_SECTION_HEADER section = sections + i;
        PrintSection2(section);
    }

    printf("ImageBase: 0x%llx\n", headers->OptionalHeader.ImageBase);

}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fputs("Usage: printsections.exe file.dll\n", stderr);
        return 1;
    }

    const char *assemblyPath = argv[1];

    long long size = GetMetadataSize((char *)assemblyPath);

    if (size == LLONG_MAX) {
        fputs("GetMetadataSize failed\n", stderr);
        return 1;
    }

    if (size > (long long)ULONG_MAX) {
        fputs("size doens't fit in a unsigned long\n", stderr);
        return 1;
    }

    unsigned long ulSize = (unsigned long)size;

    HANDLE hFile = CreateFileA(
        assemblyPath, GENERIC_READ, FILE_SHARE_READ,
        NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        fputs("CreateFileA failed\n", stderr);
        return 1;
    }

    char *buf = malloc(ulSize);

    if (!buf) {
        fputs("malloc failed\n", stderr);
        return 1;
    }

    unsigned long numberOfBytesRead;

    if (!ReadFile(hFile, buf, ulSize, &numberOfBytesRead, NULL) || numberOfBytesRead != ulSize) {
        fputs("Readfile failed\n", stderr);
        return 1;
    }

    PrintSections(buf);
}