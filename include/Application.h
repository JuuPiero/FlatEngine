#pragma once
#include "Window.h"
#include "Ultils/Ultils.h"
#include "Scene.h"

class Application {
private:
    Application();

public:
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
    ~Application();
    void Run();
    static Shared<Application> GetInstance();
    
    static void ChangeScene(int newScene);
    inline WindowProperties GetWindowProps() { return m_Window->GetProps(); }
    
    inline Shared<Window> GetWindow() { return m_Window; }

private:
    Shared<Window> m_Window;
    static Shared<Scene> m_CurrentScene;

public:
    float r, g ,b , a;
};

