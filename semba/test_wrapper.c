#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: test_wrapper cmd\n");
        return 1;
    }
    return system(argv[1]);
}