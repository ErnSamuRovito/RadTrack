#pragma once

#include <glad/glad.h> // OpenGL driver

#define glCheckError() glCheckError_(__FILE__, __LINE__)

namespace RadTrack
{

class GL
{
public:
    static void LoadOpenGL(bool gl_blending = true, bool gl_cull_face = true,
                           bool gl_multisample = true, bool gl_depth_test = true);
    static void SetPoligonMode(GLboolean enable);
    static void SetViewport(int x, int y, int SCR_WIDTH, int SCR_HEIGHT);
    static void SetColor(float r, float g, float b, float a);
    static void DrawArrays(GLenum mode, int first, int count);
    static void DrawElements(GLenum mode, int count, GLenum type, const void *indices);
    static void Clear();
    static void BindVertexArray(unsigned int n);
    static GLenum glCheckError_(const char *file, int line);
};

}
