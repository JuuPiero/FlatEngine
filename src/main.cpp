#include "Ultils/Ultils.h"
#include "Application.h"

int main(int argc, char **argv) {
    auto app = Application::GetInstance();
    app->Run();
    return 0;
}