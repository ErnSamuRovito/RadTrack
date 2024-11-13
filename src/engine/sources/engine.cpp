#include "../headers/engine.h"
#include "../headers/screen.h"
#include "../headers/gl_helper.h"

using namespace RadTrack;

Engine::Engine(bool uses_screen, int screen_width, int screen_height,
               bool screen_is_mouse_captured, bool screen_msaa,
               bool screen_vsync, const char *screen_title, bool gl_blending,
               bool gl_cull_face, bool gl_multisample, bool gl_depth_test)
{
    if (uses_screen)
    {
        Screen::Init(screen_width, screen_height, screen_is_mouse_captured,
                     screen_title, screen_msaa, screen_vsync);
        GL::LoadOpenGL(gl_blending, gl_cull_face, gl_multisample, gl_depth_test);
    }
}

Engine::~Engine()
{
    if (uses_screen)
    {
        Screen::Terminate();
    }
}


Engine::Builder &Engine::Builder::use_screen(bool uses_screen)
{
    this->uses_screen = uses_screen;
    return *this;
}

Engine::Builder &Engine::Builder::set_screen_width(int screen_width)
{
    this->screen_width = screen_width;
    return *this;
}

Engine::Builder &Engine::Builder::set_screen_height(int screen_height)
{
    this->screen_height = screen_height;
    return *this;
}

Engine::Builder &
Engine::Builder::set_screen_is_mouse_captured(bool screen_is_mouse_captured)
{
    this->screen_is_mouse_captured = screen_is_mouse_captured;
    return *this;
}

Engine::Builder &Engine::Builder::set_screen_title(const char *screen_title)
{
    this->screen_title = screen_title;
    return *this;
}

Engine::Builder &Engine::Builder::set_screen_msaa(bool screen_msaa)
{
    this->screen_msaa = screen_msaa;
    return *this;
}

Engine::Builder &Engine::Builder::set_screen_vsync(bool screen_vsync)
{
    this->screen_vsync = screen_vsync;
    return *this;
}

Engine::Builder &Engine::Builder::set_gl_blending(bool gl_blending)
{
    this->gl_blending = gl_blending;
    return *this;
}

Engine::Builder &Engine::Builder::set_gl_cull_face(bool gl_cull_face)
{
    this->gl_cull_face = gl_cull_face;
    return *this;
}

Engine::Builder &Engine::Builder::set_gl_multisample(bool gl_multisample)
{
    this->gl_multisample = gl_multisample;
    return *this;
}

Engine::Builder &Engine::Builder::set_gl_depth_test(bool gl_depth_test)
{
    this->gl_depth_test = gl_depth_test;
    return *this;
}

Engine Engine::Builder::build()
{
    return Engine(uses_screen, screen_width, screen_height,
                  screen_is_mouse_captured, screen_msaa, screen_vsync,
                  screen_title, gl_blending, gl_cull_face, gl_multisample,
                   gl_depth_test);
}
