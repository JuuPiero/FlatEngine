#include "ImGuiLayer.h"

ImGuiLayer::ImGuiLayer(Shared<Window> window): m_Window(window) {
    Initialize();
}

ImGuiLayer::~ImGuiLayer() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiLayer::Initialize() {
    // create ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Thiết lập style của ImGui
    ImGui::StyleColorsDark();
     // Thiết lập backends
    ImGui_ImplGlfw_InitForOpenGL(m_Window->GetWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 330");

}
void ImGuiLayer::StartFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}
void ImGuiLayer::EndFrame() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void ImGuiLayer::Update(float deltaTime) {
    StartFrame();
    ImGui::ShowDemoWindow();
    EndFrame();
}
