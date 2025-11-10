#include "DrawFunc.h"

#include "imgui.h"

DrawFunc::DrawFunc(bool active) : active(active),
                                  showDemo(false),
                                  gamePtrsReady(false),
                                  result("..."),
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

            ImGui::Text("gamePtrsReady: %s\n", gamePtrsReady ? "true" : "false");
            ImGui::Text(result);
        }

        ImGui::End();

        if (showDemo) {
            ImGui::ShowDemoWindow(&showDemo);
        }
    }

    ImGui::EndFrame();
    ImGui::Render();
}
