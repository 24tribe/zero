#include "UserInterface.h"

extern "C" {
#include "HookTN.h"
#include "Config.h"
#include "semba.h"
#include <jansson.h>
#include "create_file_hook.h"
#include "il2cpp_lean.h"
}

#include "SaveFileRow.h"
#include "semba_enum.h"
#include "Backend.h"
#include "DrawFunc.h"
#include "SembaContext.h"
#include "SembaClient.h"

#include <windows.h>
#include <synchapi.h>

#include <sstream>
#include <iostream>

static bool KeyPressed(int vKey) {
    static bool pressed = false;
    
    short state = GetAsyncKeyState(vKey);
    
    if (!pressed && state != 0) {
        pressed = true;
        return true;
    }

    if (pressed && state == 0) {
        pressed = false;
    }

    return false;
}

std::string sembaStatusToString(SembaStatus status) {
    switch (status) {
    case SEMBA_STATUS_OK:
        return "SEMBA_STATUS_OK";
    case SEMBA_STATUS_EXCEPTION:
        return "SEMBA_STATUS_EXCEPTION";
    case SEMBA_STATUS_VERSION_UNKNOWN:
        return "SEMBA_STATUS_VERSION_UNKNOWN";
    case SEMBA_STATUS_DB_ERROR:
        return "SEMBA_STATUS_DB_ERROR";
    case SEMBA_STATUS_ALLOC_ERROR:
        return "SEMBA_STATUS_ALLOC_ERROR";
    case SEMBA_STATUS_INVALID_CONTEXT:
        return "SEMBA_STATUS_INVALID_CONTEXT";
    }

    return "";
}

std::pair<int, std::string> SembaCallPair(const char *path, json_t *req) {
    SembaStatus status;
    char *reqStr = json_dumps(req, 0);
    char *res = GlobalSembaCall(path, reqStr, &status);
    ::free(reqStr);
    std::string response;
    if (res) { response = res; }
    GlobalSembaFreeResponse(res);

    if (status == SEMBA_STATUS_OK) {
        return std::make_pair(0, response);
    } else if (status == SEMBA_STATUS_EXCEPTION) {
        return std::make_pair(-1, response);
    } else {
        return std::make_pair(-1, std::string("SembaCall failed: ") + sembaStatusToString(status));
    }
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

static json_t *getHairColors() {
    enum SembaStatus status;
    char *res = GlobalSembaCall("/semba/get_hair_colors", "", &status);
    if (status == SEMBA_STATUS_EXCEPTION) {
        printf("getHairColors: %s\n", res);
        GlobalSembaFreeResponse(res);
        return NULL;
    }
    json_t *jsonRes = json_loads(res, 0, NULL);

    return jsonRes;
}

int saveHairColorToDB(void *userdata) {
    auto& charHairColor = *reinterpret_cast<CharHairColor *>(userdata);

    json_t *req = createUpdateColorReq(charHairColor);
    char *reqStr = json_dumps(req, 0);
    enum SembaStatus status;
    char *res = GlobalSembaCall("/semba/update_hair_color", reqStr, &status);
    if (status == SEMBA_STATUS_EXCEPTION) {
        printf("saveHairColorToDB: %s\n", res);
    }
    GlobalSembaFreeResponse(res);
    
    free(reqStr);
    json_decref(req);

    return 0;
}

int onLoadHairColors(void *userdata) {
    auto& customColorWindow = *reinterpret_cast<CustomColorWindow*>(userdata);
    auto& hairColorMap = customColorWindow.hairColorHelper.hairColorMap;

    json_t *hair_colors = getHairColors();

    updateHairColorMapWithHairColors(hairColorMap, hair_colors);

    json_decref(hair_colors);

    return 0;
}

static void InitSavesWindow(SavesWindow& savesWindow) {
    savesWindow.saves_dir = ZERO_CONFIG.savesDir;

    savesWindow.onStart = [&savesWindow]() {
        auto reqResult = createListSaveFilesRequest(ZERO_CONFIG.savesDir);

        if (reqResult.first < 0) {
            return reqResult;
        }

        enum SembaStatus status;
        char *res = GlobalSembaCall("/semba/list_save_files", reqResult.second.c_str(), &status);
        std::string response;
        if (res) { response = res; }
        GlobalSembaFreeResponse(res);

        if (status == SEMBA_STATUS_OK) {
            return parseListSaveFilesResponse(response, savesWindow.saveFileRows);
        } else if (status == SEMBA_STATUS_EXCEPTION) {
            return std::make_pair(-1, response);
        } else {
            return std::make_pair(-1, std::string("SembaCall failed: ") + sembaStatusToString(status));
        }
    };

    savesWindow.createSaveFile = [](const char *name) {
        auto result = std::make_pair(0, std::string());
        std::string req = createSaveReq(ZERO_CONFIG.savesDir, name);
        enum SembaStatus status;
        char *res = GlobalSembaCall("/semba/create_save_file", req.c_str(), &status);

        if (status == SEMBA_STATUS_OK) {
            result.second = unpackSaveResError(res);
            result.first = (result.second == "" ? 0 : -1);
        } else if (status == SEMBA_STATUS_EXCEPTION) {
            result.first = -1;
            result.second = res;
        } else {
            result.first = -1;
            result.second = std::string("SembaExCall failed: ") + sembaStatusToString(status);
        }

        GlobalSembaFreeResponse(res);

        return result;
    };

    savesWindow.loadSaveFile = [](const char *name) {
        auto result = std::make_pair(0, std::string());
        std::string req = createSaveReq(ZERO_CONFIG.savesDir, name);
        enum SembaStatus status;
        char *res = GlobalSembaCall("/semba/load_save_file", req.c_str(), &status);
        if (status == SEMBA_STATUS_OK) {
            result.second = unpackSaveResError(res);
            result.first = (result.second == "" ? 0 : -1);
        } else if (status == SEMBA_STATUS_EXCEPTION) {
            result.first = -1;
            result.second = res;
        } else {
            result.first = -1;
            result.second = std::string("SembaExCall failed: ") + sembaStatusToString(status);
        }
        GlobalSembaFreeResponse(res);
        return result;
    };

    savesWindow.deleteSaveFile = [](const char* name) {
        auto result = std::make_pair(0, std::string());
        std::string req = createSaveReq(ZERO_CONFIG.savesDir, name);
        enum SembaStatus status;
        char *res = GlobalSembaCall("/semba/delete_save_file", req.c_str(), &status);
        if (status == SEMBA_STATUS_OK) {
            result.second = "";
            result.first = 0;
        } else if (status == SEMBA_STATUS_EXCEPTION) {
            result.first = -1;
            result.second = res;
        } else {
            result.first = -1;
            result.second = std::string("SembaExCall failed: ") + sembaStatusToString(status);
        }
        GlobalSembaFreeResponse(res);
        return result;
    };
}

static void InitGachaRatesWindow(GachaRatesWindow& gachaRatesWindow) {
    gachaRatesWindow.getGachaRates = []() {
        enum SembaStatus status;
        char *resStr = GlobalSembaCall("/semba/get_std_gacha_rates", "", &status);
        if (status == SEMBA_STATUS_EXCEPTION) {
            printf("getGachaRates: %s\n", resStr);
            GlobalSembaFreeResponse(resStr);
            return (json_t *)nullptr;
        }
        json_t *res = json_loads(resStr, 0, NULL);
        GlobalSembaFreeResponse(resStr);
        return res; 
    };

    gachaRatesWindow.setGachaRates = [](json_t* req) {
        char *reqStr = json_dumps(req, 0);
        enum SembaStatus status;
        char *res = GlobalSembaCall("/semba/set_std_gacha_rates", reqStr, &status);
        if (status == SEMBA_STATUS_EXCEPTION) {
            printf("setGachaRates: %s\n", res);
            GlobalSembaFreeResponse(res);
        }
        free(reqStr);
    };
}

static void InitCustomColorWindow(CustomColorWindow& customColorWindow) {
#ifndef TRIBE_NINE_DEMO
    HookTN_SetHairColorHelper(&customColorWindow.hairColorHelper);

    customColorWindow.onHairColorChange = [](CharHairColor& charHairColor) {
        if (charHairColor.material && charHairColor.enable) {
            il2cpp_thread_attach( il2cpp_domain_get());
            SetMaterialAlbedoColor(
                reinterpret_cast<UnityEngine_Material_o *>(charHairColor.material),
                &charHairColor.hairColor[0]
            );
        }
    };

    customColorWindow.onEndHairColorChange = [](CharHairColor& charHairColor) {
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)saveHairColorToDB, &charHairColor, 0, NULL);
    };

    customColorWindow.onEnableHairColor = [](CharHairColor& charHairColor) {
        auto mat = reinterpret_cast<UnityEngine_Material_o *>(charHairColor.material);

        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)saveHairColorToDB, &charHairColor, 0, NULL);

        if (charHairColor.enable) {
            if (mat) {
                il2cpp_thread_attach( il2cpp_domain_get());
                SetMaterialAlbedoColor(mat, &charHairColor.hairColor[0]);
                SetMaterialAlbedoTexture(mat, NULL);
            }
        } else {
            if (mat) {
                il2cpp_thread_attach( il2cpp_domain_get());
                float white[] = {1.0f, 1.0f, 1.0f};
                SetMaterialAlbedoColor(mat, white);
                SetMaterialAlbedoTexture(
                    mat, reinterpret_cast<UnityEngine_Texture_o*>(charHairColor.texture)
                );
            }
        }
    };
#endif

    CreateThread(
        NULL, 0, (LPTHREAD_START_ROUTINE)onLoadHairColors, &customColorWindow, 0, NULL
    );
}

void InitDrawFunc(DrawFunc& draw_func) {
    InitSavesWindow(draw_func.savesWindow);
    InitGachaRatesWindow(draw_func.gachaRatesWindow);
    InitCustomColorWindow(draw_func.customColorWindow);

    draw_func.patimonMakerWindow.onSendGear = [](
        int rarity, int piece, int set, int tier, int substat1, int substat2, int substat3
    ) {
        json_t *req = encode_semba_mail_gear_request(rarity, piece, set, tier, substat1, substat2, substat3);
        return SembaCallPair("/semba/mail_gear", req);
    };

    draw_func.pausePositionPtr = getPausePositionPtr();

    draw_func.onStart = [&draw_func]() {
        SembaStatus status;
        char *res = GlobalSembaCall("/semba/get_skip_tutorial", "", &status);

        std::string result;
        if (res) { result = res; }
        GlobalSembaFreeResponse(res);

        if (status == SEMBA_STATUS_OK) {
            auto getSkipTutorialRes = parseGetSkipTutorialResponse(result, draw_func.skipTutorial);
            if (getSkipTutorialRes.first < 0) {
                return std::make_pair(-1, getSkipTutorialRes.second);
            } else {
                return std::make_pair(0, std::string(""));
            }
        } else if (status == SEMBA_STATUS_EXCEPTION) {
            return std::make_pair(-1, result);
        } else {
            return std::make_pair(-1, std::string("SembaCall failed: ") + sembaStatusToString(status));
        }
    };

    draw_func.onChangeSkipTutorial = [&draw_func](bool skipTutorial) {
        auto req = wrapSkipTutorial(skipTutorial);
        if (req.first < 0) {
            return req;
        }

        SembaStatus status;
        char *res = GlobalSembaCall("/semba/set_skip_tutorial", req.second.c_str(), &status);
        std::string result;
        if (res) { result = res; }
        GlobalSembaFreeResponse(res);

        if (status == SEMBA_STATUS_OK) {
            return std::make_pair(0, result);
        } else if (status == SEMBA_STATUS_EXCEPTION) {
            return std::make_pair(-1, result);
        } else {
            return std::make_pair(-1, std::string("SembaCall failed: ") + sembaStatusToString(status));
        }
    };

    draw_func.onStartNewGame = [&draw_func](bool skipTutorial) {
        auto req = wrapSkipTutorial(skipTutorial);
        if (req.first < 0) {
            return req;
        }

        SembaStatus status;
        char *res = GlobalSembaCall("/semba/new_game", req.second.c_str(), &status);
        std::string result;
        if (res) { result = res; }
        GlobalSembaFreeResponse(res);

        if (status == SEMBA_STATUS_OK) {
            return std::make_pair(0, result);
        } else if (status == SEMBA_STATUS_EXCEPTION) {
            return std::make_pair(-1, result);
        } else {
            return std::make_pair(-1, std::string("SembaCall failed: ") + sembaStatusToString(status));
        }
    };

    draw_func.onMoveToZoneArea = [&draw_func](int zone_area_id) {
        json_t *req = encode_move_to_area_request(zone_area_id);

        if (!req) {
            return std::make_pair(-1, std::string("Failed to create move to area request"));
        }

        auto res = SembaCallPair("/semba/move_to_area", req);

        if (!res.first) {
            std::stringstream ss;
            ss << "Moved to area with id " << zone_area_id;
            res.second = ss.str();
        }

        return res;
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
 
	while (1) {
        if (KeyPressed(ZERO_CONFIG.cheatsKey)) {
            if (draw_func) {
                draw_func->active = !draw_func->active;
            } else {
                Backend_Load([&draw_func]{
                    if (!draw_func) {
                        draw_func = new DrawFunc(true);
                        InitDrawFunc(*draw_func);
                    }
                    (*draw_func)(); 
                });
            }
        }

        if (draw_func) {
            draw_func->gamePtrsReady = areGamePtrsReady();
        }

        Sleep(100);
    }

	return 0;
}
