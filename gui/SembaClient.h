#pragma once

#include "../CharHairColor.h"

#include <jansson.h>

#include <string>

json_t* encode_semba_mail_gear_request(
    int rarity, int piece, int set, int tier, int substat1, int substat2, int substat3
);

json_t *createUpdateColorReq(CharHairColor& charHairColor);

std::string createSaveReq(const char* saves_dir, const char *name);