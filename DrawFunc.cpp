#include "DrawFunc.h"

#include "imgui.h"

DrawFunc::DrawFunc(bool active) : active(active), showDemo(false), runCommand() {
}

void DrawFunc::operator()(void) {
    auto& io = ImGui::GetIO();

    io.MouseDrawCursor = active;

    ImGui::NewFrame();

    if (active) {
        if (ImGui::Begin("Tribe Nine Zero", &active, 0)) {
            if (ImGui::Button("Toggle demo")) {
                showDemo = !showDemo;
            }

            if (ImGui::Button("Run command") && runCommand) {
                runCommand();
            }
        }

        ImGui::End();

        if (showDemo) {
            ImGui::ShowDemoWindow(&showDemo);
        }
    }

    ImGui::EndFrame();
    ImGui::Render();
}
