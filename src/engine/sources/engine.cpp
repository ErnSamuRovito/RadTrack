#include "../headers/engine.h"
#include "../headers/screen.h"
#include "../../utils/headers/engine_logger.h"
#include "../headers/gl_helper.h"

using namespace RadTrack;
using namespace RadTrack::Utils;

Engine::Engine(bool uses_screen,  bool uses_input,
               bool uses_logger,
               int screen_width, int screen_height,
               bool screen_is_mouse_captured, bool screen_msaa,
               bool screen_vsync, const char *screen_title,
               Types::LogLevel log_level, std::string log_file,
               bool gl_blending,
               bool gl_cull_face, bool gl_multisample, bool gl_depth_test)
{
    if (uses_screen)
    {
        Screen::Init(screen_width, screen_height, screen_is_mouse_captured,
                     screen_title, screen_msaa, screen_vsync);
        GL::LoadOpenGL(gl_blending, gl_cull_face, gl_multisample,
                       gl_depth_test);
    }

    if (uses_input)
    {
        Input::Init();
    }

    if (uses_logger)
    {
        Logger::Init();
        Logger::SetLogLevel(log_level);
        Logger::SetLogFile(log_file);
    }
}

Engine::~Engine()
{
    if (uses_screen)
    {
        Screen::Terminate();
    }

    if (uses_logger)
    {
        Logger::Close();
    }
}

Engine::Builder &Engine::Builder::use_screen(bool uses_screen)
{
    this->uses_screen = uses_screen;
    return *this;
}

Engine::Builder &Engine::Builder::use_input(bool uses_input)
{
    this->uses_input = uses_input;
    return *this;
}

Engine::Builder &Engine::Builder::use_logger(bool uses_logger)
{
    this->uses_logger = uses_logger;
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

Engine::Builder &Engine::Builder::set_log_level(Types::LogLevel log_level)
{
    this->log_level = log_level;
    return *this;
}

Engine::Builder &Engine::Builder::set_log_file(std::string log_file)
{
    this->log_file = log_file;
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
    return Engine(uses_screen, uses_input, uses_logger,
                  screen_width, screen_height,
                  screen_is_mouse_captured, screen_msaa, screen_vsync,
                  screen_title, log_level, log_file,
                  gl_blending, gl_cull_face, gl_multisample, gl_depth_test);
}
