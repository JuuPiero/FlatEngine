#pragma once
#include "Scene.h"
class LevelScene : public Scene {
public:
    LevelScene(/* args */);
    ~LevelScene();
    void Update(float deltaTime) override;
    void Initialize() override;

};


