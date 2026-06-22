#ifndef KEYS_H_019ef0c8_526e_79e8_af03_b3848de2ef16
#define KEYS_H_019ef0c8_526e_79e8_af03_b3848de2ef16

#include <stdint.h>

struct VirtualKey {
    const char *name;
    uint8_t val;
};

uint8_t findVirtualKeyCode(const char *s);

#endif