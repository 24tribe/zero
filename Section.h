#ifndef SECTION_H_030620251139
#define SECTION_H_030620251139

#include <stddef.h>

struct Section {
    const char *Name;
    unsigned long RawAddr;
    unsigned long RawSize;
    unsigned long VirtualAddr;
    unsigned long VirtualSize;
};

void FillUnknown(struct Section *Result, struct Section *GameAssembly, size_t GameAssemblyLen);
void PrintSection(struct Section *Section);

#endif