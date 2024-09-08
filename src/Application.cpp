#include "Application.h"
#include "Input/KeyListener.h"
#include "Input/MouseListener.h"
#include "LevelEditorScene.h"
#include "LevelScene.h"
#include "Ultils/Ultils.h"

Shared<Scene> Application::m_CurrentScene = nullptr;

Application::Application() {
    m_Window = std::make_shared<Window>("Flat Engine", 1080, 960);
    m_ImGuiLayer = std::make_shared<ImGuiLayer>(m_Window);
    ChangeScene(0);
   
}

Application::~Application() {}

Shared<Application> Application::GetInstance() {
    static Shared<Application> instance(new Application());
    return instance;
}

void Application::Run() {
    float beginTime = Time::GetTime();
    float deltaTime = -1.0f;
   
    while (!m_Window->ShouldClose()) {
        
        glClearColor(0.4, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        

        if(deltaTime > 0.0f) {
            m_CurrentScene->Update(deltaTime);
        }
        m_ImGuiLayer->Update(deltaTime);
        m_Window->Update(); // swap buffers, poll events

        float endTime = Time::GetTime();
        deltaTime = endTime - beginTime;
        beginTime = endTime;
    }
}

void Application::ChangeScene(int newScene) {
    switch(newScene) {
        case 0:
            m_CurrentScene = std::make_shared<LevelEditorScene>();
            m_CurrentScene->Start();
            break;
        case 1:
            m_CurrentScene = std::make_shared<LevelScene>();
            m_CurrentScene->Start();
            break;
        default:
            throw "Invalid scene";
            break;
    }
}
