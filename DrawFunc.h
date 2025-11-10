#ifndef DRAW_FUNC_H_10_11_2025_09_40_AM
#define DRAW_FUNC_H_10_11_2025_09_40_AM

#include <functional>

class DrawFunc {
    public:

    bool active;
    bool showDemo;
    bool gamePtrsReady;
    const char* result;

    std::function<void()> runCommand;

    DrawFunc(bool active);
    void operator()(void);
};

#endif