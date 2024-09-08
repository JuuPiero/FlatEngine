#include "Ultils/Ultils.h"
#include "Application.h"
#include "ECS/Entity.h"

int main(int argc, char **argv) {
    // auto entity = std::make_shared<Entity>();
    // entity->transform->scale.x 
    // entity->AddComponent(std::make_shared<Transform>());
    // entity->Update(0.0f);
    
    auto app = Application::GetInstance();
    app->Run();
    // PrintLn("end");
    return 0;
}