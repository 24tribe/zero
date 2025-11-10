#include "UserInterface.h"

#include "Backend.h"
#include "DrawFunc.h"

#include <windows.h>
#include <synchapi.h>

static bool KeyPressed(int vKey) {
	return (GetAsyncKeyState(vKey) & 1) != 0;
}

extern "C" int UIMainThread(LPVOID _1) {
    (void)_1;

    DrawFunc draw_func{false};

    Backend_Load(draw_func);

	while (1) {
        if (KeyPressed(VK_INSERT)) {
            draw_func.active = !draw_func.active;
        }

        Sleep(100);
    }

	return 0;
}