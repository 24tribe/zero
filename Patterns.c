#include "Patterns.h"

#include <string.h>

re_t GetFuzzyApiPattern(void) {
    return re_compile("[a-zA-Z]+");
}

re_t GetNeonModelApiPattern(void) {
    return re_compile("Neon.Model.Api.Rpc.\\w+");
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

sds MatchNeonModelApi(re_t patt, char *s) {
    int match_length;
    int match_idx = re_matchp(patt, s, &match_length);
    if (match_idx != -1) {
        return sdsnewlen(s + match_idx, match_length);
    }

    return NULL;
}