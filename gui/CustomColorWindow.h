#ifndef CUSTOM_COLOR_WINDOW_H_20260219_0422
#define CUSTOM_COLOR_WINDOW_H_20260219_0422

#include <functional>

class CustomColorWindow {
    public:
    float hairColor[3];
    bool enableHairColor;
    std::function<void(bool)> onEnableHairColor;

    void Show(bool* showCustomColorWindow);
    CustomColorWindow();
};

#endif