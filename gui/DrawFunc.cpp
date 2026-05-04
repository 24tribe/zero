#include "DrawFunc.h"

#include "imgui.h"

DrawFunc::DrawFunc(bool active) : currentOperation(),
                                  state(DRAW_FUNC_STATE_START),
                                  onStart(),
                                  active(active),
                                  showSavesWindow(false),
                                  showDemo(false),
                                  showGachaRates(false),
                                  showPatimonMakerWindow(false),
                                  gamePtrsReady(false),
                                  showCustomColorWindow(false),
                                  skipTutorial(true),
                                  gachaRatesWindow(),
                                  customColorWindow(),
                                  savesWindow(),
                                  patimonMakerWindow(),
                                  pos(nullptr),
                                  rotation(nullptr),
                                  fov_scale(nullptr),
                                  customFovFlag(nullptr),
                                  pausePositionPtr(nullptr),
                                  zone_area_id(130801),
                                  onMoveToZoneArea(),
                                  onChangeSkipTutorial(),
                                  onStartNewGame(),
                                  runCommand(),
                                  onCurrentOperationFail(),
                                  msg("")
{
}

void DrawFunc::HandleStartState() {
    if (onStart) {
        currentOperation = std::async(std::launch::async, onStart);
        state = DRAW_FUNC_STATE_LOADING;
    } else {
        ImGui::Text("Waiting onStart to be set!!!");
    }
}

void DrawFunc::HandleLoadingState() {
    if (auto status = currentOperation.wait_for(std::chrono::milliseconds(0)); status == std::future_status::ready) {
        auto res = currentOperation.get();
        if (res.first < 0) {
            msg = res.second;
            state = DRAW_FUNC_STATE_ERROR;
        } else {
            state = DRAW_FUNC_STATE_INITIALIZED;
        }
    } else {
        ImGui::Text("Loading...");
    }
}

void DrawFunc::HandleErrorState() {
    ImGui::Text("Error: %s", msg.c_str());
}

void DrawFunc::CheckCurrentOperation() {
    if (auto status = currentOperation.wait_for(std::chrono::milliseconds(0)); status == std::future_status::ready) {
        auto res = currentOperation.get();

        msg = res.second;

        if (res.first < 0 && onCurrentOperationFail) {
            onCurrentOperationFail();
            onCurrentOperationFail = std::function<void()>();
        }
    }
}

void DrawFunc::HandleInitializedState() {
    if (currentOperation.valid()) {
        CheckCurrentOperation();
    }

    ImGui::Text("Result: %s", msg.c_str());

    ImGui::Checkbox("Show saves window", &showSavesWindow);
    ImGui::Checkbox("Show gacha rates window", &showGachaRates);
    ImGui::Checkbox("Show hair colors window", &showCustomColorWindow);
    ImGui::Checkbox("Show Patimon maker", &showPatimonMakerWindow);

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

    ImGui::BeginDisabled(currentOperation.valid());

    ImGui::InputInt("zone_area_id", &zone_area_id);
    if (ImGui::Button("Move to zoneArea") && onMoveToZoneArea) {
        msg = "Moving to area zone...";
        currentOperation = std::async(std::launch::async, onMoveToZoneArea, zone_area_id);
    }

    ImGui::Separator();

    if (ImGui::Checkbox("Skip tutorial for new games", &skipTutorial) && onChangeSkipTutorial) {
        msg = "Saving new 'skip tutorial' setting...";
        currentOperation = std::async(std::launch::async, onChangeSkipTutorial, skipTutorial);
        onCurrentOperationFail = [this]() {
            skipTutorial = !skipTutorial;
        };
    }

    // FIXME: add a confirmation dialog
    if (ImGui::Button("Start a new game") && onStartNewGame) {
        msg = "Starting a new game...";
        currentOperation = std::async(std::launch::async, onStartNewGame, skipTutorial);
    }

    ImGui::EndDisabled();

    ImGui::Separator();

    ImGui::Checkbox("Show demo", &showDemo);

    if (ImGui::Button("Run command (Debug)") && gamePtrsReady && runCommand) {
        runCommand();
    }
}

void DrawFunc::operator()(void) {
    auto& io = ImGui::GetIO();

    io.MouseDrawCursor = active;

    ImGui::NewFrame();

    if (active) {
        ImGui::SetNextWindowSize(ImVec2(390, 420), ImGuiCond_FirstUseEver);
        if (ImGui::Begin("Tribe Nine Zero", &active, 0)) {
            switch (state) {
            case DRAW_FUNC_STATE_START:
                HandleStartState();
                break;
            case DRAW_FUNC_STATE_LOADING:
                HandleLoadingState();
                break;
            case DRAW_FUNC_STATE_INITIALIZED:
                HandleInitializedState();
                break;
            case DRAW_FUNC_STATE_ERROR:
                HandleErrorState();
                break;
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

        if (showPatimonMakerWindow) {
            patimonMakerWindow.Show(&showPatimonMakerWindow);
        }
    }

    ImGui::EndFrame();
    ImGui::Render();
}
