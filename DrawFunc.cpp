#include "DrawFunc.h"

#include "imgui.h"

DrawFunc::DrawFunc(bool active) : active(active),
                                  showSavesWindow(false),
                                  showDemo(false),
                                  gamePtrsReady(false),
                                  result("..."),
                                  pos(nullptr),
                                  rotation(nullptr),
                                  fov_scale(nullptr),
                                  customFovFlag(nullptr),
                                  togglePausePos(),
                                  runCommand() {
}

void ShowSavesWindow(bool* p_open) {
    if (ImGui::Begin("Saves", p_open)) {
        ImGui::Text("Saves window!!!");
        ImGui::End();
    }
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

            if (gamePtrsReady && ImGui::Button("Run command") && runCommand) {
                runCommand();
            }

            if (ImGui::Button("Toggle pause position") && togglePausePos) {
                togglePausePos();
            }

            ImGui::Text("gamePtrsReady: %s\n", gamePtrsReady ? "true" : "false");
            ImGui::Text(result);

            if (pos) {
                ImGui::DragFloat3("pos", pos, 0.1f);
            }

            if (rotation) {
                ImGui::DragFloat4("rotation", rotation, 0.1f);
            }

            if (customFovFlag) {
                ImGui::Checkbox("Enable custom fov", customFovFlag);
            }

            ImGui::Checkbox("Show saves window", &showSavesWindow);

            if (fov_scale) {
                ImGui::DragFloat("fovScale", fov_scale, 0.1f);
            }
        }

        ImGui::End();

        if (showDemo) {
            ImGui::ShowDemoWindow(&showDemo);
        }

        if (showSavesWindow) {
            ShowSavesWindow(&showSavesWindow);
        }
    }

    ImGui::EndFrame();
    ImGui::Render();
}
