#ifndef DRAW_FUNC_H_10_11_2025_09_40_AM
#define DRAW_FUNC_H_10_11_2025_09_40_AM

#include "GachaRatesWindow.h"
#include "CustomColorWindow.h"
#include "SavesWindow.h"

#include <jansson.h>

#include <functional>
#include <string>

class DrawFunc {
    public:

    bool active;
    bool showSavesWindow;
    bool showDemo;
    bool showGachaRates;
    bool gamePtrsReady;
    bool showCustomColorWindow;
    const char* result;

    GachaRatesWindow gachaRatesWindow;
    CustomColorWindow customColorWindow;
    SavesWindow savesWindow;

    float* pos;
    float* rotation;
    float* fov_scale;
    bool* customFovFlag;
    bool* pausePositionPtr;

    int zone_area_id;

    std::function<void(int)> on_move_to_zone_area;
    std::function<void()> runCommand;

    DrawFunc(bool active);
    void operator()(void);
};

#endif