#ifndef SAVES_WINDOW_H_MAR_14_20_11
#define SAVES_WINDOW_H_MAR_14_20_11

#include "SaveFileRow.h"

#include <string>
#include <functional>
#include <future>
#include <array>
#include <utility>
  
enum SavesWindowState {
    SAVES_WINDOW_STATE_START,
    SAVES_WINDOW_STATE_LOADING,
    SAVES_WINDOW_STATE_INITIALIZED,
    SAVES_WINDOW_STATE_ERROR,
};

class SavesWindow {
    public:

    SavesWindowState state;
    std::function<std::pair<int, std::string>()> onStart;

    std::string msg;
    std::future<std::pair<int, std::string>> currentOperation;
    std::function<void()> onCurrentOperationSuccess;

    std::array<char, 1024> inputFilename;

    char *saves_dir;

    std::vector<SaveFileRow> saveFileRows;

    std::function<std::pair<int, std::string>(const char*)> createSaveFile;
    std::function<std::pair<int, std::string>(const char*)> loadSaveFile;
    std::function<std::pair<int, std::string>(const char*)> deleteSaveFile;

    SavesWindow();
    void DrawSaveTable();
    void HandleStartState();
    void HandleLoadingState();
    void HandleErrorState();
    void HandleInitializedState();

    void Show(bool* p_open);
};

#endif
