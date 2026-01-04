#include "UserInterface.h"

extern "C" {
#include "HookTN.h"
#include "Config.h"
#include "semba/semba.h"
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

extern "C" int UIMainThread(LPVOID _1) {
    (void)_1;

    DrawFunc draw_func{false};

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

    draw_func.togglePausePos = []() {
        togglePausePosition();
    };

    draw_func.createSaveFile = [](char *name) {
        return SembaCreateSaveFile(ZERO_CONFIG.savesDir, name);
    };

    draw_func.loadSaveFile = [](const char *name) {
        return SembaLoadSaveFile(ZERO_CONFIG.savesDir, name);
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

    draw_func.runCommand = [&draw_func]() {
    };

    draw_func.fov_scale = getFovScale();
    draw_func.customFovFlag = getCustomFovFlag();

    draw_func.pos = getPosArray();
    draw_func.rotation = getRotationArray();

    Backend_Load([&draw_func]{ draw_func(); });

	while (1) {
        if (KeyPressed(VK_INSERT)) {
            draw_func.active = !draw_func.active;
        }

        draw_func.gamePtrsReady = areGamePtrsReady();

        Sleep(100);
    }

	return 0;
}