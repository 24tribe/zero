#pragma once

#include <functional>
#include <future>

class PatimonMakerWindow {
    public:
    PatimonMakerWindow();
    void Show(bool* p_open);
    void ShowSetsCombo();
    void ShowTiersCombo();

    int rarity;
    int piece;
    int set;
    int tier;
    int substat1;
    int substat2;
    int substat3;

    std::string msg;

    std::function<std::pair<int, std::string>(int, int, int, int, int, int, int)> onSendGear;
    std::future<std::pair<int, std::string>> currentOperation;
};