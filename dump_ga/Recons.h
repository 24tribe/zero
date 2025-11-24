#ifndef RECONS_H_04050403
#define RECONS_H_04050403

#include <windows.h>

// DumpGameAssembly to `outpath`
// Return 0 on success and -1 on error
int DumpGameAssembly(
    const char *outpath, BYTE *buf, unsigned long smallSize, unsigned long long start_address,
    unsigned long DataSectionSizeOfRawData
);

#endif