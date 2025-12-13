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

    char *saves_dir;

    std::vector<std::string> save_files;

    std::function<void()> togglePausePos;
    std::function<void()> runCommand;

    DrawFunc(bool active);
    void operator()(void);
};

#endif