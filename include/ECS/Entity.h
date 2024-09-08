#pragma once
#include <iostream>
#include "ECS/Component.h"
#include "Components/Transform.h"
#include "Ultils/Ultils.h"
#include <vector>
class Entity : public std::enable_shared_from_this<Entity> {
public:
    Entity(const char* name = "Empty Entity");
    ~Entity();
    
    template <typename T>
    Shared<T> GetComponent();

    template <typename T>
    Shared<T> RemoveComponent();

    void AddComponent(Shared<Component> component);

    virtual void Start();
    virtual void Update(float deltaTime);

private:
    std::string m_Name;
    std::vector<Shared<Component>> m_Components;
public:
    Shared<Transform> transform;
};

inline Shared<Entity> CreateEntity(const char* name = "Empty Entity") {
    return std::make_shared<Entity>(name);
}