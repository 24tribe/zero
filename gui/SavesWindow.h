#ifndef SAVES_WINDOW_H_MAR_14_20_11
#define SAVES_WINDOW_H_MAR_14_20_11

#include <vector>
#include <string>
#include <functional>

#define LINE_BUFFER_SIZE 1024
    
class SavesWindow {
    public:

    char line_buffer[LINE_BUFFER_SIZE];
    const char *err;
    
    char *saves_dir;

    std::vector<std::string> save_files;

    std::function<char*(char*)> createSaveFile;
    std::function<char*(const char*)> loadSaveFile;
    std::function<void(const std::string&)> deleteSaveFile;

    SavesWindow();
    void DrawSaveTable();

    void Show(bool* p_open);
};

#endif