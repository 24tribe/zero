#ifndef SDS_UTF_CONV_H_2025_27_10_05_55
#define SDS_UTF_CONV_H_2025_27_10_05_55

#include <sds.h>

sds sds16to8(const uint16_t *s, uint32_t size);
uint16_t *sds_utf8_to_utf16(sds s);

#endif