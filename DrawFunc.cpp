#include "DrawFunc.h"

#include "imgui.h"

#include <string>

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

struct SaveFile {
    std::string name;
};

void DrawSaveTable(std::vector<SaveFile>& save_files) {
    ImGuiTableFlags flags = (
        ImGuiTableFlags_RowBg
        | ImGuiTableFlags_BordersV
        | ImGuiTableFlags_BordersOuterV
        | ImGuiTableFlags_BordersInnerV
        | ImGuiTableFlags_BordersH
        | ImGuiTableFlags_BordersOuterH
        | ImGuiTableFlags_BordersInnerH
        | ImGuiTableFlags_NoBordersInBody
    );

    if (ImGui::BeginTable("saves_table", 2, flags)) {
        ImGuiListClipper clipper;
        clipper.Begin(save_files.size());
        while (clipper.Step()) {
            for (int row_n = clipper.DisplayStart; row_n < clipper.DisplayEnd; ++row_n) {
                const SaveFile& save_file = save_files[row_n];

                ImGui::PushID(save_file.name.c_str());
                ImGui::TableNextRow(ImGuiTableRowFlags_None, 0);

                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%s", save_file.name.c_str());

                ImGui::TableSetColumnIndex(1);

                ImGui::Button("Load Game");
                ImGui::SameLine();
                ImGui::Button("Delete Game");

                ImGui::PopID();
            }
        }
        ImGui::EndTable();
    }
}

void ShowSavesWindow(bool* p_open) {
    std::vector<SaveFile> save_files = {
        {"zero"},
        {"magata"},
        {"ichinose"},
        {"shark"},
        {"brave diver"},
        {"solitaire"},
        {"backgammon"},
        {"minatoxb"},
        {"tsuki"},
        {"yo"},
    };

    if (!ImGui::Begin("Saves", p_open)) {
        ImGui::End();
        return;
    }

#define LINE_BUFFER_SIZE 1024
    static char line_buffer[LINE_BUFFER_SIZE] = {0};

    ImGui::InputText("File Name", line_buffer, LINE_BUFFER_SIZE);
    ImGui::Button("Save Game");

    if (ImGui::BeginChild("saves_child",
        ImVec2(-FLT_MIN, ImGui::GetFontSize() * 20),
        ImGuiChildFlags_ResizeY)
    ) {
        DrawSaveTable(save_files);
    }
    ImGui::EndChild();

    ImGui::End();
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
