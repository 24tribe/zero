#include "DrawFunc.h"

#include "imgui.h"

DrawFunc::DrawFunc(bool active) : active(active) {
}

void DrawFunc::operator()(void) {
    auto& io = ImGui::GetIO();

    io.MouseDrawCursor = active;

    ImGui::NewFrame();

    if (active) {
        ImGui::ShowDemoWindow(&active);
    }

    ImGui::EndFrame();
    ImGui::Render();
}
