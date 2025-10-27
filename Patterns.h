#ifndef PATTERNS_H_27_10_2025_06_57
#define PATTERNS_H_27_10_2025_06_57

#include "re.h"

#include <sds.h>

#include <stdbool.h>

re_t GetFuzzyApiPattern(void);
re_t GetNeonModelApiPattern(void);
bool RegexEqualMatches(re_t patt, char *s1, char *s2);
sds MatchNeonModelApi(re_t patt, char *s);

#endif