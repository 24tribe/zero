#ifndef DRAW_FUNC_H_10_11_2025_09_40_AM
#define DRAW_FUNC_H_10_11_2025_09_40_AM

#include <functional>
#include <string>

class DrawFunc {
    public:

    bool active;
    bool showSavesWindow;
    bool showDemo;
    bool gamePtrsReady;
    const char* result;

    float* pos;
    float* rotation;
    float* fov_scale;
    bool* customFovFlag;
    bool* pausePositionPtr;

    char *saves_dir;

    int zone_area_id;

    std::vector<std::string> save_files;

    std::function<void(int)> on_move_to_zone_area;
    std::function<char*(char*)> createSaveFile;
    std::function<char*(const char*)> loadSaveFile;
    std::function<void(const std::string&)> deleteSaveFile;
    std::function<void()> runCommand;

    DrawFunc(bool active);
    void operator()(void);
};

#endif