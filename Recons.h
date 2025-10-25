#ifndef RECONS_H_04050403
#define RECONS_H_04050403

#include <windows.h>

int DumpGameAssembly(const char *outpath, BYTE *buf, unsigned long smallSize, unsigned long long start_address);

#endif