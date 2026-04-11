#pragma once

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
};