#include <semba.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fputs("Usage: semba semba_db uri reqJson\n", stderr);
        return 1;
    }

    char *semba_db = argv[1];
    char *uri = argv[2];
    char *reqJson = argv[3];

    NimMain();
    SembaInitOfflineDb(semba_db);
    puts(SembaCall(uri, reqJson));
}