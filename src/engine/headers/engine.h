#pragma once

#include "engine_input.h"
#include "../../utils/headers/engine_logger.h"
#include "engine_time.h"
#include "gl_helper.h"  // Include this first among OpenGL-related headers
#include "screen.h"

namespace RadTrack
{
    class Engine
    {
    public:
        bool uses_screen;

        Engine(bool uses_screen, int screen_width, int screen_height,
               bool screen_is_mouse_captured, bool screen_msaa,
               bool screen_vsync, const char *screen_title, bool gl_blending,
               bool gl_cull_face, bool gl_multisample, bool gl_depth_test);
        ~Engine();

        class Builder;
    };

    class Engine::Builder
    {
    public:
        bool uses_screen = false;
        int screen_width = 1280;
        int screen_height = 720;
        bool screen_is_mouse_captured = false;
        bool screen_msaa = false;
        bool screen_vsync = false;
        const char *screen_title = "";
        bool gl_blending = true;
        bool gl_cull_face = true;
        bool gl_multisample = true;
        bool gl_depth_test = true;

        Builder &use_screen(bool uses_screen);
        Builder &use_audio(bool uses_audio);
        Builder &use_input(bool uses_input);
        Builder &use_logger(bool uses_logger);
        Builder &use_text(bool uses_text);
        Builder &use_ecs(bool uses_ecs);
        Builder &set_screen_width(int screen_width);
        Builder &set_screen_height(int screen_height);
        Builder &set_screen_is_mouse_captured(bool screen_is_mouse_captured);
        Builder &set_screen_title(const char *screen_title);
        Builder &set_screen_msaa(bool screen_msaa);
        Builder &set_screen_vsync(bool screen_vsync);

        Builder &set_gl_blending(bool gl_blending);
        Builder &set_gl_cull_face(bool gl_cull_face);
        Builder &set_gl_multisample(bool gl_multisample);
        Builder &set_gl_depth_test(bool gl_depth_test);

        Engine build();
    };
}
