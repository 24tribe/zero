#include "SavesWindow.h"

#include "FuzzyMatcher.h"
#include "HighlightCharacters.hpp"

extern "C" {
#include "../TimeUtil.h"
}

#include <imgui.h>

#include <processthreadsapi.h>

#include <algorithm>
#include <sstream>
#include <chrono>

SavesWindow::SavesWindow() :
    state(SAVES_WINDOW_STATE_START),
    onStart(),
    msg(),
    currentOperation(),
    onCurrentOperationSuccess(),
    inputFilename{{0}},
    saves_dir(nullptr),
    saveFileRows(),
    createSaveFile(),
    loadSaveFile(),
    deleteSaveFile()
{
}

void SavesWindow::DrawSaveTable() {
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
        clipper.Begin(saveFileRows.size());

        while (clipper.Step()) {
            for (int row_n = clipper.DisplayStart; row_n < clipper.DisplayEnd; ++row_n) {
                const SaveFileRow& row = saveFileRows[row_n];

                ImGui::PushID(row.name.c_str());
                ImGui::TableNextRow(ImGuiTableRowFlags_None, 0);

                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%s", HighlightCharacters(row.name, row.positions).c_str());

                ImGui::TableSetColumnIndex(1);

                if (ImGui::Button("Load Game") && loadSaveFile) {
                    msg = "Loading game...";
                    currentOperation = std::async(std::launch::async, [this](std::string save_file){
                        uint64_t startTime = TimeUtil_GetTimeInMs();
                        auto res = loadSaveFile(save_file.c_str());
                        uint64_t endTime = TimeUtil_GetTimeInMs();
                        if (res.first < 0) {
                            return res;
                        }
                        std::stringstream ss;
                        ss << "Save file loaded in " << endTime - startTime << " ms";
                        res.second = ss.str();
                        return res;
                    }, row.name);
                }

                ImGui::SameLine();

                // FIXME: should ask for confirmation
                if (ImGui::Button("Delete Game") && deleteSaveFile) {
                    msg = "Deleting save...";
                    currentOperation = std::async(std::launch::async, [this](std::string save_file){
                        return deleteSaveFile(save_file.c_str());
                    }, row.name);
                    onCurrentOperationSuccess = [this, row_n]() {
                        saveFileRows.erase(saveFileRows.begin() + row_n);
                    };
                }

                ImGui::PopID();
            }
        }

        ImGui::EndTable();
    }
}

void SavesWindow::HandleStartState() {
    if (onStart) {
        currentOperation = std::async(std::launch::async, [this]() {
            auto res = onStart();

            std::sort(saveFileRows.begin(), saveFileRows.end(), [](const SaveFileRow& a, const SaveFileRow& b) {
                return a.name < b.name;              
            });

            return res;
        });
        state = SAVES_WINDOW_STATE_LOADING;
        return;
    }

    ImGui::Text("Waiting for onStart to be set...");
}

void SavesWindow::HandleLoadingState() {
    if (auto status = currentOperation.wait_for(std::chrono::milliseconds(0)); status == std::future_status::ready) {
        auto result = currentOperation.get();
        if (!result.first) {
            state = SAVES_WINDOW_STATE_INITIALIZED;
        } else {
            state = SAVES_WINDOW_STATE_ERROR;
            msg = result.second;
        }
    }

    ImGui::Text("Loading SavesWindow...");
}

void SavesWindow::HandleErrorState() {
    ImGui::Text("Error: %s", msg.c_str());
}

void SavesWindow::HandleInitializedState() {
    if (currentOperation.valid()) {
        if (auto status = currentOperation.wait_for(std::chrono::milliseconds(0)); status == std::future_status::ready) {
            auto res = currentOperation.get();
            msg = res.second;
            if (!res.first && onCurrentOperationSuccess) {
                onCurrentOperationSuccess();
                onCurrentOperationSuccess = std::function<void()>();
            }
        }
    }

    ImGui::Text("Saves Directory Path: %s", saves_dir ? saves_dir : "(null)");

    ImGui::BeginDisabled(currentOperation.valid());

    if (ImGui::InputText("File Name", &(inputFilename[0]), inputFilename.size())) {
        FuzzyMatcher matcher(&inputFilename[0]);
        std::for_each(saveFileRows.begin(), saveFileRows.end(), [&matcher](SaveFileRow &row) {
            row.fuzzyScore = matcher.ScoreMatch(row.name, &row.positions);
        });

        std::sort(saveFileRows.begin(), saveFileRows.end(), [](const SaveFileRow& a, const SaveFileRow &b) {
            return (b.fuzzyScore < a.fuzzyScore) || ((a.fuzzyScore == b.fuzzyScore) && (a.name < b.name));
        });
    }

    if (ImGui::Button("Save Game") && createSaveFile && inputFilename[0] != '\0') {
        const char *name = &(inputFilename[0]);

        if (std::find_if(saveFileRows.begin(), saveFileRows.end(), [name](const SaveFileRow& row) {
            return row.name == name;
        }) != saveFileRows.end()) {
            msg = "error: can't overwrite save files yet";
        } else {
            msg = "Saving game...";
            currentOperation = std::async(std::launch::async, [this, name]() {
                return createSaveFile(name);
            });
            onCurrentOperationSuccess = [this, name]() {
                saveFileRows.push_back({name, 0, {}});
            };
        }
    }

    ImGui::SameLine();
    ImGui::Text("%s", msg.c_str());

    if (ImGui::BeginChild("saves_child",
        ImVec2(-FLT_MIN, ImGui::GetFontSize() * 20),
        ImGuiChildFlags_ResizeY)
    ) {
        DrawSaveTable();
    }
    ImGui::EndChild();

    ImGui::EndDisabled();
}

void SavesWindow::Show(bool* p_open) {
    ImGui::SetNextWindowSize(ImVec2(450,360), ImGuiCond_FirstUseEver);

    if (!ImGui::Begin("Saves", p_open)) {
        ImGui::End();
        return;
    }

    switch (state) {
    case SAVES_WINDOW_STATE_START:
        HandleStartState();
        break;
    case SAVES_WINDOW_STATE_LOADING:
        HandleLoadingState();
        break;
    case SAVES_WINDOW_STATE_INITIALIZED:
        HandleInitializedState();
        break;
    case SAVES_WINDOW_STATE_ERROR:
        HandleErrorState();
        break;
    }

    ImGui::End();
}
