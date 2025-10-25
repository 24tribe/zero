#ifndef UTILS_H_202506121437
#define UTILS_H_202506121437

#include <windows.h>
#include <stdint.h>

#define MY_LINE_SIZE 4096

void press_enter_to_continue();
void QueryPageInfo(HMODULE GameAssembly, ptrdiff_t offset);
char *sds16to8(const uint16_t *s, uint32_t size);

#endif