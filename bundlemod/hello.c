#include "BundleMod.h"

#include <windows.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fputs("usage: hello in_bundle out_bundle textureChanges\n", stderr);
        return 1;
    }

    HANDLE in_bundle = CreateFileA(argv[1], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (in_bundle == INVALID_HANDLE_VALUE) {
        fputs("createfilew failed\n", stderr);
        return 1;
    }

    HANDLE out_bundle = CreateFileA(argv[2], GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (out_bundle == INVALID_HANDLE_VALUE) {
        fputs("createfilew failed\n", stderr);
        return 1;
    }   

    BundleMod_ChangeTextures(in_bundle, out_bundle, argv[3]);
}