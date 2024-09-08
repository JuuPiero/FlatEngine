#include "Scene.h"

void Scene::Start() {
    for (const auto &e : m_Entities) {
        e->Start();
    }
    isRunning = true;
}

void Scene::AddEntity(Shared<Entity> entity) {
    if(isRunning) {
        m_Entities.push_back(entity);
    }
    else {
        m_Entities.push_back(entity);
        entity->Start();
    }
}