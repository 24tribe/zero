#pragma once

#include "../CharHairColor.h"

#include <jansson.h>

#include <string>
#include <vector>

json_t* encode_semba_mail_gear_request(
    int rarity, int piece, int set, int tier, int substat1, int substat2, int substat3
);

json_t *createUpdateColorReq(CharHairColor& charHairColor);

std::string createSaveReq(const char* saves_dir, const char *name);

std::pair<int, std::string> createListSaveFilesRequest(const std::string& savesDir);

std::pair<int, std::string> wrapSkipTutorial(bool skipTutorial);

std::pair<int, std::string> parseGetSkipTutorialResponse(std::string response, bool& skipTutorial);

std::pair<int, std::string> parseListSaveFilesResponse(
    const std::string& response, std::vector<std::string>& save_files
);

void updateHairColorMapWithHairColors(CharHairColorMap& hairColorMap, json_t *hair_colors);