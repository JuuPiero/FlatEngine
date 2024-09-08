#pragma once
#include "Window.h"
#include "Ultils/Ultils.h"
#include "Scene.h"
#include "ImGuiLayer.h"
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

    inline static Shared<Scene> GetScene() { return m_CurrentScene; }
private:
    Shared<Window> m_Window;
    Shared<ImGuiLayer> m_ImGuiLayer;
    static Shared<Scene> m_CurrentScene;

public:
    // float r, g ,b , a;
};

