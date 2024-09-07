#pragma once
#include "Ultils/Ultils.h"

struct GLFWwindow;

struct WindowProperties {
    const char* Title = "Flat Engine";
    int Width = 1920;
    int Height = 1080;
    WindowProperties(const char* title, int width, int height): Title(title), Width(width), Height(height) {} 
};

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

    void Update();
    void PollEvents();
    bool ShouldClose();

    void Initialize();

    GLFWwindow* GetWindow() { return m_Window; }
    inline WindowProperties GetProps() { return *m_Props; }
    inline const float GetWidth() const { return (float)m_Props->Width; }
    inline const float GetHeight() const { return (float)m_Props->Height; }

private:
    static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
private:
    GLFWwindow* m_Window;
    Shared<WindowProperties> m_Props = nullptr;
};
