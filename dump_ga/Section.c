#include "Section.h"

#include <stdio.h>
#include <limits.h>
#include <string.h>

unsigned long Align(unsigned long x, unsigned long Alignment) {
    unsigned long res = Alignment;

    while (res < x) {
        res += Alignment;
    }

    return res;
}

void FillUnknown(
    struct Section *Result, struct Section *GameAssembly, size_t GameAssemblyLen,
    unsigned long DataSectionSizeOfRawData
) {
    for (size_t i = 0; i < GameAssemblyLen; ++i) {
        struct Section *ResSection = Result + i;
        struct Section *GASection = GameAssembly + i;

        ResSection->Name = GASection->Name;

        if (i == 0) {
            ResSection->RawAddr = 0x400;
        } else {
            ResSection->RawAddr = Result[i-1].RawAddr + Result[i-1].RawSize;
        }

        if (!strcmp(GASection->Name, ".data") && DataSectionSizeOfRawData != ULONG_MAX) {
            ResSection->RawSize = DataSectionSizeOfRawData;
        } else {
            ResSection->RawSize = Align(GASection->VirtualSize, 0x200);
        }
        
        ResSection->VirtualAddr = GASection->VirtualAddr;
        ResSection->VirtualSize = GASection->VirtualSize;
    }
}

void PrintSection(struct Section *Section) {
    printf(
        "%s, %lx, %lx, %lx, %lx\n",
        Section->Name, Section->RawAddr, Section->RawSize,
        Section->VirtualAddr, Section->VirtualSize
    );
}