#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "engine/headers/screen.h"
#include "engine/headers/engine.h"
#include "engine/headers/gl_helper.h"
#include "engine/headers/engine_time.h"

// Callbacks
#include "close_window_callback.h"

// Default resolution
const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

using namespace RadTrack; 

int main(int argc, char *argv[]) {
    Engine engine = Engine::Builder()
                        .use_screen(true)
                        .set_screen_width(SCR_WIDTH)
                        .set_screen_height(SCR_HEIGHT)
                        .set_screen_is_mouse_captured(false)
                        .set_screen_msaa(true)
                        .set_screen_vsync(true)
                        .set_screen_title("RadTrack")
                        .set_gl_blending(true)
                        .set_gl_cull_face(true)
                        .set_gl_multisample(true)
                        .set_gl_depth_test(true)
                        .build();

    Input::Init();

    InitCloseWindowCallback();

    Time::Update(Screen::GetTime());
    while (!Screen::isWindowClosed())
    {
        GL::SetColor(0.7f, 0.4f, 0.5f, 1.0f);
        GL::Clear();

        Time::Update(Screen::GetTime());

        //std::cout << Time::GetDeltaTime() << std::endl;

        Screen::PollEvents();
        Screen::SwapBuffers();
    }

    return 0;
}

