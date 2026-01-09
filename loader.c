#include "LoaderAux.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fputs("Usage: Loader.exe game_exe_path dll_path\n", stdout);
        return 1;
    }

    char *path = argv[1];
    char *dll_path = argv[2];
    
    return LoadGame(path, dll_path);
}

