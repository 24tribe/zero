#ifndef MD5SUM_H_2025_23_09_04_35
#define MD5SUM_H_2025_23_09_04_35

void md5sum_buffer(const uint8_t *data, size_t len, uint8_t digest[16]);
char *md5_hex(const uint8_t digest[16]);

#endif