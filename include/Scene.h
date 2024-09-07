#pragma once
#include "Camera.h"
#include "Ultils/Ultils.h"
class Scene {
protected:
    Shared<Camera> m_Camera;

public:
    Scene() = default;
    virtual ~Scene() = default;
    virtual void Update(float deltaTime) = 0;
    virtual void Initialize() = 0;
};