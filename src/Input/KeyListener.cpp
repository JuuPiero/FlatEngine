#include "Input/KeyListener.h"

Shared<KeyListener> KeyListener::s_Instance = nullptr;

KeyListener::KeyListener() {}

KeyListener::~KeyListener() {}

Shared<KeyListener> KeyListener::GetInstance() {
    // static Shared<KeyListener> instance(new KeyListener());
    // return instance;
    if (s_Instance == nullptr) {
        s_Instance = std::make_shared<KeyListener>();
    }
    return s_Instance;
}

void KeyListener::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    if(action == GLFW_PRESS) {
        GetInstance()->m_KeysPressed[key] = true;
    }
    else if (action == GLFW_RELEASE) {
        GetInstance()->m_KeysPressed[key] = false;
    }

}
