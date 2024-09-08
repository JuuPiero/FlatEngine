#pragma once
#include "ECS/Component.h"
#include "Ultils/Ultils.h"
class SpriteRenderer : public Component {
public:
    SpriteRenderer(float r, float g, float b, float a);
    ~SpriteRenderer();

    void Update(float deltaTime) override;
    void Start() override;
public:
    glm::vec4 color;
};


