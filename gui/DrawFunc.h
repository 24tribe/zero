#ifndef DRAW_FUNC_H_10_11_2025_09_40_AM
#define DRAW_FUNC_H_10_11_2025_09_40_AM

#include "GachaRatesWindow.h"
#include "CustomColorWindow.h"
#include "SavesWindow.h"

#include <jansson.h>

#include <functional>
#include <string>
#include <future>
#include <utility>

enum DrawFuncState {
    DRAW_FUNC_STATE_START,
    DRAW_FUNC_STATE_LOADING,
    DRAW_FUNC_STATE_INITIALIZED,
    DRAW_FUNC_STATE_ERROR,
};

class DrawFunc {
    public:

    std::future<std::pair<int, std::string>> currentOperation;
    DrawFuncState state;
    std::function<std::pair<int, std::string>()> onStart;

    bool active;
    bool showSavesWindow;
    bool showDemo;
    bool showGachaRates;
    bool gamePtrsReady;
    bool showCustomColorWindow;
    bool skipTutorial;

    GachaRatesWindow gachaRatesWindow;
    CustomColorWindow customColorWindow;
    SavesWindow savesWindow;

    float* pos;
    float* rotation;
    float* fov_scale;
    bool* customFovFlag;
    bool* pausePositionPtr;

    int zone_area_id;

    std::function<std::pair<int, std::string>(int)> onMoveToZoneArea;
    std::function<std::pair<int, std::string>(bool)> onChangeSkipTutorial;
    std::function<std::pair<int, std::string>(bool)> onStartNewGame;
    std::function<void()> runCommand;

    DrawFunc(bool active);
    void operator()(void);
    void HandleStartState();
    void HandleErrorState();
    void HandleInitializedState();
    void HandleLoadingState();
    void CheckCurrentOperation();

    private:
    std::function<void()> onCurrentOperationFail;
    std::string msg;
};

#endif