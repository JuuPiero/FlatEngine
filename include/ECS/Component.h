#pragma once

#include "Ultils/Ultils.h"

class Entity;

class Component {
public:
    Component() = default;
    virtual ~Component() = default;
    virtual void Update(float deltaTime) = 0;
    virtual void Start() = 0;
public:
    Weak<Entity> entity;
};
