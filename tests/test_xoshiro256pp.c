#include "xoshiro256pp.h"

#include <stdio.h>

int main(void) {
    xoshiro256pp_set_state(
        0x5490141ec56727c2ull,
        0xf4e7615431a42bdbull,
        0xb6a380264f8df51full,
        0x4d93987efefaa433ull 
    );

    /*
    0xa3724504c0383998
    0x1f399cb51519992c
    0x58825c9cd8a17e2b
    0xde9fee7862310532
    0xf3afc52fed83fb71
    0x25ddc36152b6e3c9
    0x517d516a7ffff275
    0x360892443cd11fda
    0x707f9c6fe1a8a9e1
    0x668307cf48d3463c
    */

    for (int i = 0; i < 10; ++i) {
        printf("0x%llx\n", xoshiro256pp_next());
    }
}