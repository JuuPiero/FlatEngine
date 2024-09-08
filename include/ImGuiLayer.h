#pragma once
#include "Ultils/Ultils.h"
#include "Window.h"
class ImGuiLayer {

public:
    ImGuiLayer(Shared<Window> window);
    ~ImGuiLayer();
    
    void Initialize();
    void StartFrame();
    void EndFrame();
    void Update(float deltaTime);
private:
    Shared<Window> m_Window;

};


