#include "close_window_callback.h"
#include "engine/headers/engine.h"

using namespace RadTrack;

void InitCloseWindowCallback() {
    auto close_window_callback = []() { Screen::SetClose(); };
    Input::AddKeyboardCallback(GLFW_KEY_ESCAPE, close_window_callback);
}

