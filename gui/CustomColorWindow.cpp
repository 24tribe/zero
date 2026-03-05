#include "CustomColorWindow.h"

#include <imgui.h>



CustomColorWindow::CustomColorWindow() : hairColorHelper(),
                                         onEnableHairColor(),
                                         onHairColorChange(),
                                         onEndHairColorChange() {
    ImGui::SetColorEditOptions(ImGuiColorEditFlags_InputRGB);
}

void CustomColorWindow::Show(bool* showCustomColorWindow) {
    ImGui::SetNextWindowSize(ImVec2(660, 465), ImGuiCond_FirstUseEver);

    if (!ImGui::Begin("Hair Colors", showCustomColorWindow)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Tip: to open the color picker click the little color square");

    auto& hairColorMap = hairColorHelper.hairColorMap;

    for (auto& [charId, charHairColor] : hairColorMap) {
        ImGui::PushID(charId);
        if (ImGui::ColorEdit3(charHairColor.charName.c_str(), &(charHairColor.hairColor[0])) && onHairColorChange) {
            onHairColorChange(charHairColor);
        }
        if (onEndHairColorChange && ImGui::IsItemDeactivatedAfterEdit()) {
            onEndHairColorChange(charHairColor);
        }
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetWindowWidth() - 80.0f);
        if (ImGui::Checkbox("Enable", &charHairColor.enable) && onEnableHairColor) {
            onEnableHairColor(charHairColor);
        }
        ImGui::PopID();
    }

    ImGui::End();
}