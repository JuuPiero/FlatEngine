#pragma once
#include "Camera.h"
#include "Ultils/Ultils.h"
#include "ECS/Entity.h"
#include <vector>
class Scene {


public:
    Scene() = default;
    virtual ~Scene() = default;
    virtual void Update(float deltaTime) = 0;
    virtual void Initialize() = 0;

    void Start();

    void AddEntity(Shared<Entity> entity);

    inline Shared<Camera> GetCamera() const {
        return m_Camera;
    }

protected:
    Shared<Camera> m_Camera;
public:
    bool isRunning = false;
    std::vector<Shared<Entity>> m_Entities;
};