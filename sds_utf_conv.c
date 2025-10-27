#include "sds_utf_conv.h"

#include <windows.h>

sds sds16to8(const uint16_t *s, uint32_t size) {
    int len = WideCharToMultiByte(CP_UTF8, 0, s, size, 0, 0, 0, 0);
    sds res = sdsnewlen(NULL, len);
    WideCharToMultiByte(CP_UTF8, 0, s, size, res, len, 0, 0);
    return res;
}

uint16_t *sds_utf8_to_utf16(sds s) {
    int nLenWide = MultiByteToWideChar(CP_UTF8, 0, s, sdslen(s), NULL, 0);
    uint16_t *res = calloc(nLenWide + 1, 2);
    MultiByteToWideChar(CP_UTF8, 0, s, sdslen(s), res, nLenWide);
    return res;
}