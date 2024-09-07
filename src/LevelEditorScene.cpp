#include "LevelEditorScene.h"
#include "Input/KeyListener.h"
#include "Application.h"

LevelEditorScene::LevelEditorScene() {
    PrintLn("Inside levelEditorScene");
    Initialize();
}

LevelEditorScene::~LevelEditorScene() {}

void LevelEditorScene::Update(float deltaTime) {

    m_Shader->SetMatrix4("projection", m_Camera->GetProjectionMatrix());
    m_Shader->SetMatrix4("view", m_Camera->GetViewMatrix());
    m_Shader->Use();
    glDrawElements(GL_TRIANGLES, m_ElementBuffer->Count(), GL_UNSIGNED_INT, 0);

}

void LevelEditorScene::Initialize()  {
    m_Camera = std::make_shared<Camera>(glm::vec2(0.0f, 0.));
    float vertices[] = {
        100.0f, 0.0f, 0.0f,     1.0f, 0.0f, 0.0f,  1.0f, 0.0f, // Đỉnh 0: Đỏ
        0.0f, 100.0f, 0.0f,     0.0f, 1.0f, 0.0f,  0.0f, 1.0f, // Đỉnh 1: Xanh lục
        100.0f, 100.0f, 0.0f,   0.0f, 0.0f, 1.0f,  1.0f, 1.0f, // Đỉnh 2: Xanh lam
        0.f,  0.0f, 0.0f,       1.0f, 1.0f, 0.0f,  0.0f, 0.0f  // Đỉnh 3: Vàng
    };
    uint32_t indices[] = { 2, 1, 0,     0, 1, 3};

    m_VertexArray = std::make_shared<VertexArray>();
    m_Shader = std::make_shared<Shader>("../shaders/default.vert", "../shaders/default.frag");
    m_VertexBuffer = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
    m_ElementBuffer = std::make_shared<ElementBuffer>(indices, sizeof(indices));
    m_Texture = std::make_shared<Texture>("../assets/abc.jpg");
    m_VertexArray->AddLayout(*m_VertexBuffer, {0, 3, Type::FLOAT, false, 8 * sizeof(float) ,  0});
    m_VertexArray->AddLayout(*m_VertexBuffer, {1, 3, Type::FLOAT, false, 8 * sizeof(float) ,  (3 * sizeof(float))});
    m_VertexArray->AddLayout(*m_VertexBuffer, {2, 2, Type::FLOAT, false, 8 * sizeof(float) ,  (6 * sizeof(float))});
    m_Shader->SetTexture("uTexture", 0);
    glActiveTexture(GL_TEXTURE0);
    m_Texture->Bind();
}