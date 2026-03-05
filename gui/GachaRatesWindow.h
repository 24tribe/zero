#ifndef GACHA_RATES_WINDOW_H_0240012026
#define GACHA_RATES_WINDOW_H_0240012026

#include <windows.h>

#include <jansson.h>

#include <functional>
#include <string>

enum GachaRatesWindowState {
    GACHA_RATES_STATE_START,
    GACHA_RATES_STATE_LOADING,
    GACHA_RATES_STATE_INITIALIZED,
    GACHA_RATES_STATE_ERROR
};

struct NormalPullRates {
    float threeStarCharRate;
    float threeStarTCRate;
    float twoStarCharRate;
    float twoStarTCRate;
    float oneStarTCRate;
};

struct PromisedPullRates {
    float threeStarCharRate;
    float threeStarTCRate;
    float twoStarCharRate;
    float twoStarTCRate;
};

struct GuaranteedPullRates {
    float threeStarCharRate;
    float threeStarTCRate;
};

using GetGachaRatesFuncType = std::function<json_t*()>;

class GachaRatesWindow {
    public:

    GachaRatesWindowState state;

    GetGachaRatesFuncType getGachaRates;
    std::function<void(json_t*)> setGachaRates;

    GachaRatesWindow();
    void Show(bool* showGachaRates);
    bool InitGachaRates();
    void ApplyGachaRates();

    GachaRatesWindowState HandleStartState();
    GachaRatesWindowState HandleLoadingState();
    void HandleInitializedState();

    void DrawGachaRateSliders();

    private:

    bool initialized;
    NormalPullRates normalPullRates;
    GuaranteedPullRates guaranteedPullRates;
    PromisedPullRates promisedPullRates;
    std::string error;
    std::string result;
    std::string getGachaRatesError;
    std::string setGachaRatesResult;

    HANDLE getGachaRatesThread;
    HANDLE setGachaRatesThread;
};

#endif