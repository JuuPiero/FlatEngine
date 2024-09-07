#include "Ultils/Time.h"
#include "Ultils/Ultils.h"

float Time::timeStarted = (float)glfwGetTime();

float Time::GetTime() {
    return (float)glfwGetTime() - timeStarted;
}
