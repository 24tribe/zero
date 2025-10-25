#include <stdio.h>

void print_msg(char *msg) {
    printf("msg: %s\n", msg);
}

int main(void) {
    char line[1024];
    while (fgets(line, 1024, stdin)) {
        print_msg(line);
    }
}