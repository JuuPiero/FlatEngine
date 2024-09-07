#include "Input/MouseListener.h"

Shared<MouseListener> MouseListener::s_Instance = nullptr;

MouseListener::MouseListener() {
}

MouseListener::~MouseListener() {

}

Shared<MouseListener> MouseListener::GetInstance() {
    if (s_Instance == nullptr) {
        s_Instance = std::make_shared<MouseListener>();
    }
    return s_Instance;
}

void MouseListener::MousePositionCallback(GLFWwindow* window, double x, double y) {
    GetInstance()->m_LastX = GetInstance()->m_X;
    GetInstance()->m_LastY = GetInstance()->m_Y;
    GetInstance()->m_X = x;
    GetInstance()->m_Y = y;
    GetInstance()->m_IsDragging = GetInstance()->m_MouseButtonsPressed[0] || GetInstance()->m_MouseButtonsPressed[1] || GetInstance()->m_MouseButtonsPressed[2];
    // PrintLn(GetInstance()->m_X << "," << GetInstance()->m_Y);

}

void MouseListener::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if(action == GLFW_PRESS) {
        if(button < GetInstance()->m_MouseButtonsPressed.size()) {
            GetInstance()->m_MouseButtonsPressed[button] = true;
        }
    }
    else if(action == GLFW_RELEASE) {
        if(button < GetInstance()->m_MouseButtonsPressed.size()) {
            GetInstance()->m_MouseButtonsPressed[button] = false;
            GetInstance()->m_IsDragging = false;
        }
    }
}

void MouseListener::MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
    GetInstance()->m_ScrollX = xOffset; 
    GetInstance()->m_ScrollY = yOffset;    
}
