#ifndef SAVES_WINDOW_H_MAR_14_20_11
#define SAVES_WINDOW_H_MAR_14_20_11

#include <vector>
#include <string>
#include <functional>
#include <future>
#include <array>
#include <utility>
  
class SavesWindow {
    public:

    std::string msg;
    std::future<std::pair<int, std::string>> currentOperation;
    std::function<void()> onCurrentOperationSuccess;

    std::array<char, 1024> inputFilename;

    char *saves_dir;

    std::vector<std::string> save_files;

    std::function<std::pair<int, std::string>(const char*)> createSaveFile;
    std::function<std::pair<int, std::string>(const char*)> loadSaveFile;
    std::function<std::pair<int, std::string>(const char*)> deleteSaveFile;

    SavesWindow();
    void DrawSaveTable();

    void Show(bool* p_open);
};

#endif