#ifndef CUSTOM_COLOR_WINDOW_H_20260219_0422
#define CUSTOM_COLOR_WINDOW_H_20260219_0422

#include "../CharHairColor.h"

#include <functional>

class CustomColorWindow {
    public:

    HairColorHelper hairColorHelper;

    std::function<void(CharHairColor&)> onEnableHairColor;
    std::function<void(CharHairColor&)> onHairColorChange;
    std::function<void(CharHairColor&)> onEndHairColorChange;

    void Show(bool* showCustomColorWindow);
    CustomColorWindow();
};

#endif