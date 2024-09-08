#include "ECS/Entity.h"
#include "Components/Transform.h"
Entity::Entity(const char* name): m_Name(name) {
    PrintLn(name << " Created");
    m_Components.push_back(std::make_shared<Transform>());
    transform = GetComponent<Transform>();
}

Entity::~Entity() {
    std::cout << m_Name << " Destroyed" << std::endl;

}

template <typename T>
Shared<T> Entity::GetComponent() {
    for (auto& component : m_Components) {
        if (auto casted = std::dynamic_pointer_cast<T>(component)) {
            return casted;
        }
    }
    return nullptr;
}


template <typename T>
Shared<T> Entity::RemoveComponent() {
    for (auto it = m_Components.begin(); it!= m_Components.end(); ++it) {
        if (auto casted = std::dynamic_pointer_cast<T>(*it)) {
            m_Components.erase(it);
            return casted;
        }
    }
    return nullptr;
}

void Entity::AddComponent(Shared<Component> component) {
    m_Components.push_back(component);
    component->entity = weak_from_this();
}

void Entity::Start() {

}

void Entity::Update(float deltaTime) {

    for (auto& component : m_Components) {
        component->Update(deltaTime);
    }
}
