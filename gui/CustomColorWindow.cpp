#include "CustomColorWindow.h"

#include <imgui.h>

CustomColorWindow::CustomColorWindow() : hairColor{0.5, 1, 0.5},
                                         enableHairColor(false),
                                         onEnableHairColor() {
    ImGui::SetColorEditOptions(ImGuiColorEditFlags_InputHSV);
}

void CustomColorWindow::Show(bool* showCustomColorWindow) {
    ImGui::SetNextWindowSize(ImVec2(350, 90), ImGuiCond_FirstUseEver);

    if (!ImGui::Begin("CustomColor", showCustomColorWindow)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Tip: to open the color picker click the little color square");

    ImGui::ColorEdit3("Hair color", hairColor);
    ImGui::SameLine();
    if (ImGui::Checkbox("Enable", &enableHairColor) && onEnableHairColor) {
        onEnableHairColor(enableHairColor);
    }

    ImGui::End();
}