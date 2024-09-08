#pragma once
#include "Scene.h"
#include "OpenGL/Shader.h"
#include "OpenGL/Buffer.h"
#include "OpenGL/VertexArray.h"
#include "OpenGL/Texture.h"
#include "Ultils/Ultils.h"
#include "ECS/Entity.h"

class LevelEditorScene : public Scene {

public:
    LevelEditorScene();
    ~LevelEditorScene();

    void Update(float deltaTime) override;
    void Initialize() override;

private:
    bool m_ChangingScene = false;
    float m_TimeToChangeScene = 2.0f;

    Shared<Shader> m_Shader;
    Shared<VertexBuffer> m_VertexBuffer;
    Shared<ElementBuffer> m_ElementBuffer; 
    Shared<VertexArray> m_VertexArray;
    Shared<Texture> m_Texture;
    Shared<Entity> test;
};


