#ifndef XOSHIRO256PP_H_09_11_2025_11_42_AM
#define XOSHIRO256PP_H_09_11_2025_11_42_AM

#include <stdint.h>

void xoshiro256pp_set_state(uint64_t s0, uint64_t s1, uint64_t s2, uint64_t s3);
uint64_t xoshiro256pp_next(void);

#endif