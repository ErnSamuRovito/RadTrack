#include "../headers/engine.h"

using namespace RadTrack;
using namespace RadTrack::Types;
using namespace RadTrack::Utils;

std::unordered_map<int, std::function<void()>> Input::keyboardCallbacks;
std::unordered_map<std::string, std::function<void(double, double)>> Input::mouseCallbacks;

void Input::Init()
{
    Screen::SetKeyCallback(Input::KeyCallback);
    Screen::SetMousePosCallback(Input::MousePosCallback);
}

void Input::AddKeyboardCallback(int key, std::function<void()> callback)
{
    Input::keyboardCallbacks[key] = callback;
}

void Input::RemoveKeyboardCallback(int key)
{
    if (Input::keyboardCallbacks.find(key) == Input::keyboardCallbacks.end())
    {
        return;
    }

    Input::keyboardCallbacks.erase(key);
}

void Input::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        if (Input::keyboardCallbacks.find(key) != Input::keyboardCallbacks.end())
        {
            Input::keyboardCallbacks.at(key)();
        }
    }
}

void Input::AddMousePosCallback(MouseCallbackName callback_name, std::function<void(double, double)> callback)
{
    Input::mouseCallbacks[callback_name] = callback;
}

void Input::RemoveMousePosCallback(MouseCallbackName callback_name)
{
    if (Input::mouseCallbacks.find(callback_name) == Input::mouseCallbacks.end())
    {
        return;
    }

    Input::mouseCallbacks.erase(callback_name);
}

void Input::MousePosCallback(GLFWwindow *window, double xpos, double ypos)
{
    for (auto &callback : Input::mouseCallbacks)
    {
        callback.second(xpos, ypos);
    }
}
