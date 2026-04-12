#include "SembaClient.h"

json_t* encode_semba_mail_gear_request(
    int rarity, int piece, int set, int tier, int substat1, int substat2, int substat3
) {
    json_t* req = json_object();

    if (req) {
        json_object_set_new(req, "rarity", json_integer(rarity))
        json_object_set_new(req, "piece", json_integer(piece))
        json_object_set_new(req, "set", json_integer(set))
        json_object_set_new(req, "tier", json_integer(tier))
        json_object_set_new(req, "substat1", json_integer(substat1))
        json_object_set_new(req, "substat2", json_integer(substat2))
        json_object_set_new(req, "substat3", json_integer(substat3))
    }

    return req;
}