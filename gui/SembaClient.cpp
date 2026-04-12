#include "SembaClient.h"

#include <iostream>

json_t* encode_semba_mail_gear_request(
    int rarity, int piece, int set, int tier, int substat1, int substat2, int substat3
) {
    json_t* req = json_object();

    if (req) {
        json_object_set_new(req, "rarity", json_integer(rarity));
        json_object_set_new(req, "piece", json_integer(piece));
        json_object_set_new(req, "set", json_integer(set));
        json_object_set_new(req, "tier", json_integer(tier));
        json_object_set_new(req, "substat1", json_integer(substat1));
        json_object_set_new(req, "substat2", json_integer(substat2));
        json_object_set_new(req, "substat3", json_integer(substat3));
    }

    return req;
}

json_t *createUpdateColorReq(CharHairColor& charHairColor) {
    json_t *req = json_object();
    json_object_set_new(req, "charId", json_integer(charHairColor.charId));
    json_object_set_new(req, "r", json_real(charHairColor.hairColor[0]));
    json_object_set_new(req, "g", json_real(charHairColor.hairColor[1]));
    json_object_set_new(req, "b", json_real(charHairColor.hairColor[2]));
    json_object_set_new(req, "enabled", json_boolean(charHairColor.enable));
    return req;
}

std::string createSaveReq(const char* saves_dir, const char *name) {
    json_t *req = json_object();
    json_object_set_new(req, "saves_dir", json_string(saves_dir));
    json_object_set_new(req, "name", json_string(name));
    char *req_s = json_dumps(req, 0);
    std::string result = req_s;
    free(req_s);
    return result;
}

std::pair<int, std::string> createListSaveFilesRequest(const std::string& savesDir) {
    json_t *req = json_object();

    if (!req) {
        return std::make_pair(-1, std::string("json_object() failed!"));
    }

    json_object_set_new(req, "savesDir", json_string(savesDir.c_str()));

    char *reqStr = json_dumps(req, 0);

    if (!reqStr) {
        return std::make_pair(-1, std::string("json_dumps failed!"));
    }

    std::string result = reqStr;

    ::free(reqStr);

    return std::make_pair(0, result);
}

std::pair<int, std::string> wrapSkipTutorial(bool skipTutorial) {
    json_t* req = json_object();

    if (!req) {
        return std::make_pair(-1, "json_object() failed!");
    }

    json_object_set_new(req, "skipTutorial", json_boolean(skipTutorial));

    char *reqStr = json_dumps(req, 0);

    if (!reqStr) {
        return std::make_pair(-1, "json_dumps failed!");
    }

    std::string reqResult(reqStr);
    ::free(reqStr);

    return std::make_pair(0, reqResult);
}

std::pair<int, std::string> parseGetSkipTutorialResponse(std::string response, bool& skipTutorial) {
    json_t *resJson = json_loads(response.c_str(), 0, NULL);

    if (!resJson) {
        return std::make_pair(-1, std::string("json_loads failed!"));
    }

    json_t *skipTutorialJson = json_object_get(resJson, "skipTutorial");

    if (!skipTutorialJson) {
        return std::make_pair(-1, std::string("skipTutorial field missing from response"));
    }

    skipTutorial = json_boolean_value(skipTutorialJson);

    json_decref(resJson);

    return std::make_pair(0, std::string());
}

std::pair<int, std::string> parseListSaveFilesResponse(
    const std::string& response, std::vector<std::string>& save_files
) {
    json_t *resJson = json_loads(response.c_str(), 0, NULL);

    if (!resJson) {
        return std::make_pair(-1, std::string("json_loads failed!"));
    }

    json_t *names = json_object_get(resJson, "names");

    if (!names) {
        return std::make_pair(-1, std::string("failed to get names field from res"));
    }

    for (size_t i = 0; i < json_array_size(names); ++i) {
        json_t *name = json_array_get(names, i);

        save_files.push_back(json_string_value(name));
    }

    return std::make_pair(0, std::string());
}

void updateHairColorMapWithHairColors(CharHairColorMap& hairColorMap, json_t *hair_colors) {
    for (size_t i = 0; i < json_array_size(hair_colors); ++i) {
        json_t *hair_color = json_array_get(hair_colors, i);

        int charId = json_integer_value(json_object_get(hair_color, "charId"));
        float r = json_real_value(json_object_get(hair_color, "r"));
        float g = json_real_value(json_object_get(hair_color, "g"));
        float b = json_real_value(json_object_get(hair_color, "b"));
        bool enabled = json_boolean_value(json_object_get(hair_color, "enabled"));

        if (auto search = hairColorMap.find(charId); search != hairColorMap.end()) {
            search->second.hairColor[0] = r;
            search->second.hairColor[1] = g;
            search->second.hairColor[2] = b;
            search->second.enable = enabled;
        } else {
            std::cout << "Warning: charId=" << charId << " not found is hairColorMap\n";
        }
    }
}