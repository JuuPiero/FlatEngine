#pragma once
#include "Ultils/Ultils.h"
// #include <GLFW/glfw3.h>
class KeyListener {

private:

public:
    KeyListener();

    static Shared<KeyListener> GetInstance();
    ~KeyListener();

    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    inline static bool IsKeyPressed(int keyCode) {
        return GetInstance()->m_KeysPressed[keyCode];
    }

private:
    static Shared<KeyListener> s_Instance;

    // std::vector<bool> m_KeysPressed = std::vector<bool>(350, false);
    bool m_KeysPressed[350] = {0};

};

