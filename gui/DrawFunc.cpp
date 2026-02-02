#include "DrawFunc.h"

extern "C" {
#include "../TimeUtil.h"
}

#include "imgui.h"

#include <processthreadsapi.h>

#include <string>
#include <algorithm>
#include <sstream>

DrawFunc::DrawFunc(bool active) : active(active),
                                  showSavesWindow(false),
                                  showDemo(false),
                                  showGachaRates(false),
                                  gamePtrsReady(false),
                                  result("..."),
                                  gachaRatesWindow(),
                                  pos(nullptr),
                                  rotation(nullptr),
                                  fov_scale(nullptr),
                                  customFovFlag(nullptr),
                                  pausePositionPtr(nullptr),
                                  saves_dir(nullptr),
                                  zone_area_id(130801),
                                  save_files(),
                                  on_move_to_zone_area(),
                                  createSaveFile(),
                                  loadSaveFile(),
                                  deleteSaveFile(),
                                  runCommand() {
}

struct ThreadData {
    std::function<char *(const char *)> loadSaveFile;
    const char *name;
    bool completed;
    char *res;
    bool started;
    FILETIME start;
    FILETIME end;
};

int CallLoadSaveFile(void *userData) {
    ThreadData& data = *reinterpret_cast<ThreadData*>(userData);
    data.started = true;
    data.res = data.loadSaveFile(data.name);
    data.completed = true;
    GetSystemTimeAsFileTime(&data.end);
    return 0;
}

void DrawSaveTable(
    std::vector<std::string>& save_files,
    std::function<char *(const char *)> loadSaveFile,
    std::function<void (const std::string&)> deleteSaveFile,
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

    static ThreadData thread_data = {0, NULL, false, NULL, false, {0, 0}, {0, 0}};
    static std::string msg;

    if (thread_data.completed) {
        thread_data.started = false;
        thread_data.completed = false;
        if (thread_data.res) {
            *err = thread_data.res;
        } else {
            std::stringstream ss;
            ULONGLONG diff = GetFileTimeDiff(thread_data.end, thread_data.start);
            ss << "Save file loaded in " << TimeDiffToMs(diff) << " ms";
            msg = ss.str();
            *err = msg.c_str();
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
                    GetSystemTimeAsFileTime(&thread_data.start);
                    if (!CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CallLoadSaveFile, &thread_data, 0, NULL)) {
                        thread_data.started = false;
                        *err = "Failed to create thread";
                    }
                }

                ImGui::SameLine();

                // FIXME: should ask for confirmation
                if (ImGui::Button("Delete Game") && deleteSaveFile) {
                    deleteSaveFile(save_file);
                    save_files.erase(save_files.begin() + row_n);
                    ImGui::PopID();
                    goto endloop;
                }

                ImGui::PopID();
            }
        }
        endloop:
        ImGui::EndTable();
    }
}

void ShowSavesWindow(
    bool* p_open, std::vector<std::string>& save_files, char *saves_dir,
    std::function<char *(char *)> createSaveFile,
    std::function<void (const std::string&)> deleteSaveFile,
    std::function<char *(const char *)> loadSaveFile
) {
    ImGui::SetNextWindowSize(ImVec2(450,360), ImGuiCond_FirstUseEver);

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
        DrawSaveTable(save_files, loadSaveFile, deleteSaveFile, &err);
    }
    ImGui::EndChild();

    ImGui::End();
}

void DrawFunc::operator()(void) {
    auto& io = ImGui::GetIO();

    io.MouseDrawCursor = active;

    ImGui::NewFrame();

    if (active) {
        ImGui::SetNextWindowSize(ImVec2(300,320), ImGuiCond_FirstUseEver);
        if (ImGui::Begin("Tribe Nine Zero", &active, 0)) {
            ImGui::Text("Result: %s", result);

            ImGui::Checkbox("Show saves window", &showSavesWindow);
            ImGui::Checkbox("Show gacha rates window", &showGachaRates);

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

        if (showSavesWindow) {
            ShowSavesWindow(
                &showSavesWindow, save_files, saves_dir, createSaveFile, deleteSaveFile, loadSaveFile
            );
        }
    }

    ImGui::EndFrame();
    ImGui::Render();
}
