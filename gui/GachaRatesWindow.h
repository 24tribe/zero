#ifndef GACHA_RATES_WINDOW_H_0240012026
#define GACHA_RATES_WINDOW_H_0240012026

#include <windows.h>

#include <jansson.h>

#include <functional>
#include <string>

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

    GetGachaRatesFuncType getGachaRates;
    std::function<void(json_t*)> setGachaRates;

    GachaRatesWindow();
    void Show(bool* showGachaRates);
    bool InitGachaRates();

    private:

    bool initialized;
    NormalPullRates normalPullRates;
    GuaranteedPullRates guaranteedPullRates;
    PromisedPullRates promisedPullRates;
    std::string error;
    std::string getGachaRatesError;

    HANDLE getGachaRatesThread;
};

#endif