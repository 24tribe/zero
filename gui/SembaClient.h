#pragma once

#include <jansson.h>

json_t* encode_semba_mail_gear_request(
    int rarity, int piece, int set, int tier, int substat1, int substat2, int substat3
);