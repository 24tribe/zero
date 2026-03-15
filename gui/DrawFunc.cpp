#include "DrawFunc.h"

#include "imgui.h"

DrawFunc::DrawFunc(bool active) : active(active),
                                  showSavesWindow(false),
                                  showDemo(false),
                                  showGachaRates(false),
                                  gamePtrsReady(false),
                                  showCustomColorWindow(false),
                                  skipTutorial(true),
                                  result("..."),
                                  gachaRatesWindow(),
                                  customColorWindow(),
                                  savesWindow(),
                                  pos(nullptr),
                                  rotation(nullptr),
                                  fov_scale(nullptr),
                                  customFovFlag(nullptr),
                                  pausePositionPtr(nullptr),
                                  zone_area_id(130801),
                                  on_move_to_zone_area(),
                                  onChangeSkipTutorial(),
                                  onStartNewGame(),
                                  runCommand() {    
}

void DrawFunc::operator()(void) {
    auto& io = ImGui::GetIO();

    io.MouseDrawCursor = active;

    ImGui::NewFrame();

    if (active) {
        ImGui::SetNextWindowSize(ImVec2(300,345), ImGuiCond_FirstUseEver);
        if (ImGui::Begin("Tribe Nine Zero", &active, 0)) {
            ImGui::Text("Result: %s", result);

            ImGui::Checkbox("Show saves window", &showSavesWindow);
            ImGui::Checkbox("Show gacha rates window", &showGachaRates);
            ImGui::Checkbox("Show hair colors window", &showCustomColorWindow);

            ImGui::Separator();

            if (pausePositionPtr) {
                ImGui::Checkbox("Pause position", pausePositionPtr);
            }

            if (pos) {
                ImGui::DragFloat3("pos", pos, 0.1f);
            }

            if (rotation) {
                ImGui::DragFloat4("rotation", rotation, 0.1f);
            }

            ImGui::Separator();

            if (customFovFlag) {
                ImGui::Checkbox("Enable custom fov", customFovFlag);
            }

            if (fov_scale) {
                ImGui::DragFloat("fovScale", fov_scale, 0.1f);
            }

            ImGui::Separator();

            ImGui::InputInt("zone_area_id", &zone_area_id);
            if (ImGui::Button("Move to zoneArea") && on_move_to_zone_area) {
                on_move_to_zone_area(zone_area_id);
            }

            ImGui::Separator();

            if (ImGui::Checkbox("Skip tutorial for new games", &skipTutorial) && onChangeSkipTutorial) {
                onChangeSkipTutorial(skipTutorial);
            }

            // FIXME: add a confirmation dialog
            if (ImGui::Button("Start a new game") && onStartNewGame) {
                onStartNewGame(&result);
            }

            ImGui::Separator();

            ImGui::Checkbox("Show demo", &showDemo);

            if (ImGui::Button("Run command (Debug)") && gamePtrsReady && runCommand) {
                runCommand();
            }
        }

        ImGui::End();

        if (showDemo) {
            ImGui::ShowDemoWindow(&showDemo);
        }

        if (showGachaRates) {
            gachaRatesWindow.Show(&showGachaRates);
        }

        if (showCustomColorWindow) {
            customColorWindow.Show(&showCustomColorWindow);
        }

        if (showSavesWindow) {
            savesWindow.Show(&showSavesWindow);
        }
    }

    ImGui::EndFrame();
    ImGui::Render();
}
