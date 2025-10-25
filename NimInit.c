#include "semba.h"

#include <stdbool.h>

bool isNimMainCalled = false;

void RunNimMainOnce(void) {
    if (!isNimMainCalled) {
        NimMain();
        isNimMainCalled = true;
    }
}