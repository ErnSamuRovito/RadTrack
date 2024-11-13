#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace RadTrack {
    class Screen {
    public:
        static int WIDTH;
        static int HEIGHT;
        static GLFWwindow* window;

        Screen() = delete;

        static void Init(int SCR_WIDTH, int SCR_HEIGHT,
                         bool isMouseCaptured = false, const char* title = "OpenGL",
                         bool msaa = false, bool vsync = false);

        static int GetWidth();
        static int GetHeight();
        static bool isWindowClosed();
        static bool isKeyPressed(int key);
        static float GetTime();
        static GLFWwindow* GetWindow();
        static GLFWglproc GetProcAddress();

        static void SetMouseCallback(GLFWcursorposfun callback);
        static void SetSizeCallback(GLFWframebuffersizefun callback);
        static void SetMousePosCallback(GLFWcursorposfun callback);
        static void SetKeyCallback(GLFWkeyfun callback);
        static void SetMouseCapture(bool isCaptured);
        static void SetClose();

        static void SwapBuffers();
        static void PollEvents();
        static void Terminate();

    private:
        static void SetContextVersion(int major, int minor);
        static void UseCoreProfile();
        static void SetHintsApple();
        static void CreateWindow(int SCR_WIDTH, int SCR_HEIGHT, const char *title);
        static void MakeContextCurrent();
        static void Framebuffer_size_callback(GLFWwindow *window, int width,
                                            int height);
    };
}
