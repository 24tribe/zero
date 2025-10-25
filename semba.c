#include <semba.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fputs("Usage: semba uri reqJson\n", stderr);
        return 1;
    }

    NimMain();
    puts(SembaCall(argv[1], argv[2]));
}