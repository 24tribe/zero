#include "UserInterface.h"

#include "Backend.h"

#include "imgui.h"

#include <windows.h>
#include <synchapi.h>

bool active = false;

static bool KeyPressed(int vKey) {
	return (GetAsyncKeyState(vKey) & 1) != 0;
}

void MyDrawFunc(void) {
    auto& io = ImGui::GetIO();

    io.MouseDrawCursor = active;

    ImGui::NewFrame();

    if (active) {
        ImGui::ShowDemoWindow(&active);
    }

	ImGui::EndFrame();
	ImGui::Render();
}

extern "C" int UIMainThread(LPVOID _1) {
    (void)_1;

    Backend_Load(MyDrawFunc);

	while (1) {
        if (KeyPressed(VK_INSERT)) {
            active = !active;
        }

        Sleep(100);
    }

	return 0;
}