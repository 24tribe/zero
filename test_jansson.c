#include "utils.h"
#include "TimeString.h"

#include <stdio.h>

int main(void) {
    sds data = SlurpFile("responses\\2025_9_14_12_57_57_UserCrossDateResponse.txt");

    char *newData = ChangeLoggedInAtStr(data, GetDateTime());

    puts(newData);
}