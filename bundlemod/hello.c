#include <windows.h>

extern void hellorld(char *s);

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fputs("usage: hello bundle_file\n", stderr);
        return 1;
    }

    HANDLE h = CreateFileA(argv[1], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h == INVALID_HANDLE_VALUE) {
        fputs("createfilew failed\n", stderr);
        return 1;
    }
    hellorld(h);
}