#include "HairColorHelper.h"

#include <iostream>

int main(void) {
    const char *matName = "mat_chr030_001_hair01";
    int res = HairColorHelper_GetCharIdFromMaterialName(matName);
    return res == 30 ? 0 : 1;
}