#include "../headers/gl_helper.h"
#include "../headers/screen.h"

#include <iostream>

using namespace RadTrack;

void GL::LoadOpenGL(bool gl_blending, bool gl_cull_face, bool gl_multisample,
                    bool gl_depth_test)
{
    GLADloadproc loadproc = (GLADloadproc) Screen::GetProcAddress();
    if (!gladLoadGLLoader(loadproc))
    {
        //ERROR("Failed to initialize GLAD");
        exit(-1);
    }

    int SCR_WIDTH = Screen::GetWidth();
    int SCR_HEIGHT = Screen::GetHeight();

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    glEnable(GL_DEPTH_TEST);
    //INFO("Enabled GL_DEPTH_TEST");

    if (gl_blending)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //INFO("Enabled GL_BLEND (transparency)");
    }

    if (gl_cull_face)
    {
        glEnable(GL_CULL_FACE);
        //INFO("Enabled GL_CULL_FACE (draw only visible triangles)");
    }

    if (gl_multisample)
    {
        glEnable(GL_MULTISAMPLE);
        //INFO("Enabled GL_MULTISAMPLE");
    }

    GLenum errcode = GL::glCheckError();
    //if (!errcode)
        //INFO("OpenGl loaded");
}

void GL::SetPoligonMode(GLboolean enable)
{
    if (enable)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        //INFO("Enabled GL_POLYGON_MODE (wireframe)");
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        //INFO("Disabled GL_POLYGON_MODE (fill)");
    }
}

void GL::SetViewport(int x, int y, int SCR_WIDTH, int SCR_HEIGHT)
{
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    //INFO("Set viewport: x = ", x, ", y = ", y, ", width = ", SCR_WIDTH, ", height = ", SCR_HEIGHT);
}

void GL::SetColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void GL::DrawArrays(GLenum mode, int first, int count)
{
    glDrawArrays(mode, first, count);
}

void GL::DrawElements(GLenum mode, int count, GLenum type, const void *indices)
{
    glDrawElements(mode, count, type, indices);
}

void GL::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GL::BindVertexArray(unsigned int n)
{
    glBindVertexArray(n);
}

GLenum GL::glCheckError_(const char *file, int line)
{
    GLenum errorCode;
    while ((errorCode = glGetError()) != GL_NO_ERROR)
    {
        std::string error;
        switch (errorCode)
        {
        case GL_INVALID_ENUM:
            error = "INVALID_ENUM";
            break;
        case GL_INVALID_VALUE:
            error = "INVALID_VALUE";
            break;
        case GL_INVALID_OPERATION:
            error = "INVALID_OPERATION";
            break;
        case GL_OUT_OF_MEMORY:
            error = "OUT_OF_MEMORY";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            error = "INVALID_FRAMEBUFFER_OPERATION";
            break;
        }

        error += " | " + std::string(file) + " (" + std::to_string(line) + ")";
        //ERROR(error);
    }
    return errorCode;
}
