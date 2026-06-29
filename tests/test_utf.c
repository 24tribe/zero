#include "sds_utf_conv.h"

#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint16_t data[] = u"みなも";
    uint32_t data_len = sizeof data/sizeof *data;
    sds s = sds16to8(data, data_len);
    char *it = s;
    while (*it) {
        printf("%02x", (unsigned int)(unsigned char)*it++);
    }
    printf("\n");
    sdsfree(s);
}