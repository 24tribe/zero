#include "re.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *test_cases[] = {
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.AdventureMoveToAreaResponse]",
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.AuthSteamUserResponse]",
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.UserLogInResponse]",
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.UserCrossDateResponse]",
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.AdventureAreaObjectResponse]"
};

re_t GetNeonModelApiPattern(void) {
    return re_compile("Neon.Model.Api.Rpc.\\w+");
}

char *MatchNeonModelApi(re_t patt, char *s) {
    int match_length;
    int match_idx = re_matchp(patt, s, &match_length);
    if (match_idx != -1) {
        char *res = malloc(strlen(s) + 1);
        strcpy(res, s);
        res += match_idx;
        res[match_length] = '\0';
        return res;
    }

    return NULL;
}

#define ARRAY_SIZE(x) (sizeof x/sizeof *x)

int main(void) {
    char **it;
    char **end = test_cases + ARRAY_SIZE(test_cases);

    re_t pattern = GetNeonModelApiPattern();

    for (it = test_cases; it != end; ++it) {
        char *s = MatchNeonModelApi(pattern, *it);
        if (s) {
            puts(s);
        }
    }    
}