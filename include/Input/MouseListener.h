#pragma once
#include "Ultils/Ultils.h"
// #include <GLFW/glfw3.h>
class MouseListener {
private:
public:
    MouseListener();
    ~MouseListener();
    static Shared<MouseListener> GetInstance();
    static void MousePositionCallback(GLFWwindow* window, double x, double y);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
    inline void EndFrame() {
        m_ScrollX = 0.0f; 
        m_ScrollY = 0.0f;
        m_LastX = m_X;
        m_LastY = m_Y;
    }
    inline static const double GetX() { return GetInstance()->m_X; }
    inline static const double GetY() { return GetInstance()->m_Y; }

    inline const double GetDX() const { return (m_LastX - m_X); }
    inline const double GetDY() const { return (m_LastY - m_Y); }
    inline const double GetScrollX() const { return m_ScrollX; }
    inline const double GetScrollY() const { return m_ScrollY; }
    inline const bool IsDragging() const { return m_IsDragging; }
    
    inline bool MouseButtonDown(int button) {
        return m_MouseButtonsPressed[button];
    }


private:
    static Shared<MouseListener> s_Instance;

    double m_ScrollX, m_ScrollY = 0.0;
    double m_X, m_Y, m_LastX, m_LastY = 0.0;
    std::vector<bool> m_MouseButtonsPressed = std::vector<bool>(3, false);
    bool m_IsDragging;
};


