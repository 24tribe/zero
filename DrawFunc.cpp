#include "DrawFunc.h"

#include "imgui.h"

DrawFunc::DrawFunc(bool active) : active(active),
                                  showDemo(false),
                                  gamePtrsReady(false),
                                  result("..."),
                                  pos(nullptr),
                                  rotation(nullptr),
                                  togglePausePos(),
                                  runCommand() {
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
        }

        ImGui::End();

        if (showDemo) {
            ImGui::ShowDemoWindow(&showDemo);
        }
    }

    ImGui::EndFrame();
    ImGui::Render();
}
