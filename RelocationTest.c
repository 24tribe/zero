#include <stdio.h>

static int Hellorld = 0;

extern void SetHellorld(int x) {
    Hellorld = x;
}

extern void PrintHellorld(void) {
    printf("Hellorld is %d!\n", Hellorld);
}