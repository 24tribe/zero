#include "UserInterface.h"

extern "C" {
#include "HookTN.h"
#include "Config.h"
#include "semba/semba.h"
#include <jansson.h>
}

#include "Backend.h"
#include "DrawFunc.h"
#include "SavesHelper.hpp"

#include <windows.h>
#include <synchapi.h>

#include <sstream>

static bool KeyPressed(int vKey) {
	return (GetAsyncKeyState(vKey) & 1) != 0;
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

std::string unpackSaveResError(const char *res) {
    json_error_t unused;
    json_t *resJson = json_loads(res, 0, &unused);
    if (!resJson) {
        return "Couldn't load response json";
    }
    const char *err = json_string_value(json_object_get(resJson, "err"));
    if (!err) {
        return "Couldn't get the value of err key";
    }
    std::string errStr = err;
    json_decref(resJson);
    return errStr;
}

void InitDrawFunc(DrawFunc& draw_func) {
    draw_func.saves_dir = ZERO_CONFIG.savesDir;

    std::string what;

    try {
        if (GetSaveFiles(ZERO_CONFIG.savesDir, draw_func.save_files) != SH_OK) {
            draw_func.result = "Failed to load save files names";
        }
    } catch (const std::exception& e) {
        what = e.what();
        draw_func.result = what.c_str();
    }

    draw_func.pausePositionPtr = getPausePositionPtr();

    static std::string saveFileErr;

    draw_func.createSaveFile = [](char *name) {
        std::string req = createSaveReq(ZERO_CONFIG.savesDir, name);
        char *res = SembaCall("/semba/create_save_file", req.c_str());
        if (res) {
            saveFileErr = unpackSaveResError(res);
            res = (saveFileErr != "" ? (char *)saveFileErr.c_str() : NULL);
        }
        return res;
    };

    draw_func.loadSaveFile = [](const char *name) {
        std::string req = createSaveReq(ZERO_CONFIG.savesDir, name);
        char *res = SembaCall("/semba/load_save_file", req.c_str());
        if (res) {
            saveFileErr = unpackSaveResError(res);
            res = (saveFileErr != "" ? (char *)saveFileErr.c_str() : NULL);
        }
        return res;
    };

    draw_func.deleteSaveFile = [](const std::string& name) {
        std::string req = createSaveReq(ZERO_CONFIG.savesDir, name.c_str());
        SembaCall("/semba/delete_save_file", req.c_str());
    };

    draw_func.on_move_to_zone_area = [&draw_func](int zone_area_id) {
        const char *currentLocation = "{\"areaType\": 1, \"direction\": 5, \"positionCoordinates\": {\"x\": -6, \"y\": 53.59764, \"z\": -15.75}, \"areaKeyId\": 300402}";

        std::stringstream ss;
        ss << "{";
        ss << "\"areaId\": " << zone_area_id << ", ";
        ss << "\"currentLocation\": " << currentLocation << ", ";
        ss << "}";
        draw_func.result = SembaCall("/adventure/move_to_area", ss.str().c_str());
        if (!draw_func.result) {
            draw_func.result = "Failed to move to area";
        }
    };

    draw_func.gachaRatesWindow.getGachaRates = []() {
        char *resStr = SembaCall("/semba/get_std_gacha_rates", "");
        json_error_t unused;
        json_t *res = json_loads(resStr, 0, &unused);
        free(resStr);
        return res; 
    };

    draw_func.gachaRatesWindow.setGachaRates = [](json_t* req) {
        char *reqStr = json_dumps(req, 0);
        SembaCall("/semba/set_std_gacha_rates", reqStr);
        free(reqStr);
    };

    draw_func.runCommand = [&draw_func]() {
    };

    draw_func.fov_scale = getFovScale();
    draw_func.customFovFlag = getCustomFovFlag();

    draw_func.pos = getPosArray();
    draw_func.rotation = getRotationArray();
}

extern "C" int UIMainThread(LPVOID _1) {
    (void)_1;

    DrawFunc *draw_func = nullptr;

    Backend_Load([&draw_func]{
        if (!draw_func) {
            draw_func = new DrawFunc(false);
            InitDrawFunc(*draw_func);
        }
        (*draw_func)(); 
    });

	while (1) {
        if (KeyPressed(VK_INSERT) && draw_func) {
            draw_func->active = !draw_func->active;
        }

        if (draw_func) {
            draw_func->gamePtrsReady = areGamePtrsReady();
        }

        Sleep(100);
    }

	return 0;
}