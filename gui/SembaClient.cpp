#include "SembaClient.h"

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