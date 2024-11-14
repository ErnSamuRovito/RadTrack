#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <functional>
#include <string>
#include <unordered_map>

namespace RadTrack
{

namespace Types
{
typedef std::string MouseCallbackName;
} // namespace Types

class Input
{
  public:
    Input() = delete;
    
    static void Init();
    static void AddKeyboardCallback(int key, std::function<void()> callback);
    static void RemoveKeyboardCallback(int key);
    static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void AddMousePosCallback(Types::MouseCallbackName name, std::function<void(double, double)> callback);
    static void RemoveMousePosCallback(Types::MouseCallbackName callback_name);
    static void MousePosCallback(GLFWwindow *window, double xpos, double ypos);

  private:
    static std::unordered_map<int, std::function<void()>> keyboardCallbacks;
    static std::unordered_map<std::string, std::function<void(double, double)>> mouseCallbacks;
};

}
