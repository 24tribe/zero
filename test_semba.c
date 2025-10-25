#include <semba.h>

#include <stdio.h>

int main(void) {
    printf("%s\n", SembaCall("echo", "{\"data\":\"Hello World!!!\"}"));

    const char *idk = SembaCall("", "asjdkajsdk");

    printf("idk: %p\n", (void *)idk);
}