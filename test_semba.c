#include <semba.h>

#include <stdio.h>

int main(void) {
    NimMain();

    printf("%s\n", SembaCall("echo", "{\"data\":\"Hello World!!!\"}"));

    const char *idk = SembaCall("asdsdjaksjd", "");

    printf("%s\n", SembaCall("/auth/steam_user", ""));

    printf("idk: %p\n", (void *)idk);
}