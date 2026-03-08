#include "LoaderAux.h"

#include <stdio.h>

int wmain(int argc, wchar_t* argv[]) {
    if (argc != 3) {
        fputs("Usage: Loader.exe game_exe_path dll_path\n", stdout);
        return 1;
    }

    wchar_t *path = argv[1];
    wchar_t *dll_path = argv[2];
    
    return LoadGameEx(path, dll_path);
}

