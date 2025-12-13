#include "DrawFunc.h"

#include "imgui.h"

#include <processthreadsapi.h>

#include <string>
#include <algorithm>

DrawFunc::DrawFunc(bool active) : active(active),
                                  showSavesWindow(false),
                                  showDemo(false),
                                  gamePtrsReady(false),
                                  result("..."),
                                  pos(nullptr),
                                  rotation(nullptr),
                                  fov_scale(nullptr),
                                  customFovFlag(nullptr),
                                  saves_dir(nullptr),
                                  save_files(),
                                  createSaveFile(),
                                  loadSaveFile(),
                                  togglePausePos(),
                                  runCommand() {
}

struct ThreadData {
    std::function<char *(const char *)> loadSaveFile;
    const char *name;
    bool completed;
    char *res;
    bool started;
};

int CallLoadSaveFile(void *userData) {
    ThreadData& data = *reinterpret_cast<ThreadData*>(userData);
    data.started = true;
    data.res = data.loadSaveFile(data.name);
    data.completed = true;
    return 0;
}

void DrawSaveTable(
    std::vector<std::string>& save_files,
    std::function<char *(const char *)> loadSaveFile,
    const char **err
) {
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

    static ThreadData thread_data = {0, NULL, false, NULL, false};

    if (thread_data.completed) {
        thread_data.started = false;
        thread_data.completed = false;
        if (thread_data.res) {
            *err = thread_data.res;
        } else {
            *err = "Save file loaded!";
        }
    }

    if (thread_data.started) {
        *err = "Loading game...";
    }

    if (ImGui::BeginTable("saves_table", 2, flags)) {
        ImGuiListClipper clipper;
        clipper.Begin(save_files.size());

        while (clipper.Step()) {
            for (int row_n = clipper.DisplayStart; row_n < clipper.DisplayEnd; ++row_n) {
                const std::string& save_file = save_files[row_n];

                ImGui::PushID(save_file.c_str());
                ImGui::TableNextRow(ImGuiTableRowFlags_None, 0);

                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%s", save_file.c_str());

                ImGui::TableSetColumnIndex(1);

                if (ImGui::Button("Load Game") && loadSaveFile && !thread_data.started) {
                    thread_data.started = true;
                    thread_data.name = save_file.c_str();
                    thread_data.loadSaveFile = loadSaveFile;
                    if (!CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CallLoadSaveFile, &thread_data, 0, NULL)) {
                        thread_data.started = false;
                        *err = "Failed to create thread";
                    }
                }

                ImGui::SameLine();
                ImGui::Button("Delete Game");

                ImGui::PopID();
            }
        }
        ImGui::EndTable();
    }
}

void ShowSavesWindow(
    bool* p_open, std::vector<std::string>& save_files, char *saves_dir,
    std::function<char *(char *)> createSaveFile,
    std::function<char *(const char *)> loadSaveFile
) {
    if (!ImGui::Begin("Saves", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Saves Directory Path: %s", saves_dir ? saves_dir : "(null)");

#define LINE_BUFFER_SIZE 1024
    static char line_buffer[LINE_BUFFER_SIZE] = {0};
    static const char *err = "";

    ImGui::InputText("File Name", line_buffer, LINE_BUFFER_SIZE);
    if (ImGui::Button("Save Game") && createSaveFile && line_buffer[0] != '\0') {
        std::string name{line_buffer};

        if (std::find(save_files.begin(), save_files.end(), name) != save_files.end()) {
            err = "error: can't overwrite save file yet";
        } else {
            err = createSaveFile(line_buffer);
            if (!err) {
                save_files.push_back(line_buffer);
                err = "";
            }
        }
    }

    ImGui::SameLine();
    ImGui::Text("%s", err);

    if (ImGui::BeginChild("saves_child",
        ImVec2(-FLT_MIN, ImGui::GetFontSize() * 20),
        ImGuiChildFlags_ResizeY)
    ) {
        DrawSaveTable(save_files, loadSaveFile, &err);
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
            ShowSavesWindow(&showSavesWindow, save_files, saves_dir, createSaveFile, loadSaveFile);
        }
    }

    ImGui::EndFrame();
    ImGui::Render();
}
