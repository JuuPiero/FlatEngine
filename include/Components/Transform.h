#pragma once

#include "ECS/Component.h"
#include "Ultils/Ultils.h"
class Transform : public Component {
public:
    Transform(const glm::vec2& position, const glm::vec2& scale): position(position), scale(scale) {}
    Transform(): position(glm::vec2(0, 0)), scale(glm::vec2(1.0f, 1.0f)) {}
    void Update(float deltaTime) override;

    void Start() override;
public:
    glm::vec2 position;
    glm::vec2 scale;
};