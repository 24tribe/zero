#include "re.h"

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

re_t GetFuzzyApiPattern(void) {
    return re_compile("[a-zA-Z]+");
}

bool RegexEqualMatches(re_t patt, char *s1, char *s2) {
    int len1 = 0;
    int len2 = 0;
    int idx1;
    int idx2;
    int it1 = 0;
    int it2 = 0;
    do {
        idx1 = re_matchp(patt, s1 + it1, &len1);
        idx2 = re_matchp(patt, s2 + it2, &len2);
        // printf("idx1(%d): %d, idx2(%d): %d\n", len1, idx1, len2, idx2);
        if (idx1 != -1 && idx2 != -1) {
            if (len1 != len2) {
                return false;
            }

            if (memcmp(s1 + it1 + idx1, s2 + it2 + idx2, len1)) {
                return false;
            }

            it1 += len1;
            it2 += len2;
        }
    } while (idx1 != -1 && idx2 != -1);

    if (((idx1 == -1) && (idx2 != -1)) || ((idx1 != -1) && (idx2 == -1))) {
        return false;
    }

    return true;
}

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