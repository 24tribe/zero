#include "Section.h"

#include <stdio.h>

#define ARRAY_LEN(x) (sizeof x/sizeof *x)

int main(void) {
    struct Section GameAssembly[] = {
        {".text", 0x400, 0x297c00, 0x1000, 0x297b00},
        {"il2cpp",0x298000,0x178a000,0x299000,0x1789f4f},
        {".rdata",0x1a22000,0x4e9400,0x1a23000,0x4e93c4},
        {".data",0x1f0b400,0x1cbc00,0x1f0d000,0x47f2b4},
        {".pdata",0x20d7000,0x160e00,0x238d000,0x160cbc},
        {"_RDATA",0x2237e00,0x200,0x24ee000,0xf4},
        {".reloc",0x2238000,0x73e00,0x24ef000,0x73c64},
    };

    size_t GameAssemblyLen = ARRAY_LEN(GameAssembly);

    struct Section Result[ARRAY_LEN(GameAssembly)];

    FillUnknown(Result, GameAssembly, GameAssemblyLen);

    for (size_t i = 0; i < GameAssemblyLen; ++i) {
        PrintSection(Result + i);
    }
}