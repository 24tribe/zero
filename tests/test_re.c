#include "Patterns.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(x) (sizeof x/sizeof *x)

char *test_cases[] = {
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.AdventureMoveToAreaResponse]",
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.AuthSteamUserResponse]",
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.UserLogInResponse]",
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.UserCrossDateResponse]",
    "Google.Protobuf.MessageParser`1[Neon.Model.Api.Rpc.AdventureAreaObjectResponse]"
};

struct PathTestCase {
    char *s1;
    char *s2;
};

struct PathTestCase path_test_cases[] = {
    {"/field_boss/entry", "/field/boss_entry"},
    {"/fractal_vise/battle/start", "/fractal_vise/battle_start"},
    {"/obvious/inequal", "/to/this/path"},
    {"/another/test", "/another/estt"},
    {"/another/test", "/another"}
};

static void TestNeonModelApiPattern(void) {
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

static void TestFuzzyPathPattern(void) {
    struct PathTestCase *it;
    struct PathTestCase *end = path_test_cases + ARRAY_SIZE(path_test_cases);

    re_t pattern = GetFuzzyApiPattern();

    for (it = path_test_cases; it != end; ++it) {
        bool res = RegexEqualMatches(pattern, it->s1, it->s2);
        printf("'%s' %s '%s'\n", it->s1, res ? "==" : "!=", it->s2);
    }
}


int main(void) {
    TestNeonModelApiPattern();
    TestFuzzyPathPattern();
}