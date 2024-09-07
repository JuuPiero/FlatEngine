#include "Camera.h"
#include "Ultils/Ultils.h"
#include "Application.h"
Camera::Camera(glm::vec2 position) {
    m_ProjectionMatrix = glm::mat4(1.0f);
    m_ViewMatrix = glm::mat4(1.0f);
    m_Position = position;
    AdjustProjection();
}

Camera::~Camera() {}

void Camera::AdjustProjection() {
    m_ProjectionMatrix = glm::ortho(0.0f, 1080.0f, 0.0f, 960.0f, 0.0f, 100.0f);    
}

glm::mat4 Camera::GetViewMatrix() {
    glm::vec3 cameraFront(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);
    m_ViewMatrix = glm::lookAt(glm::vec3(m_Position.x, m_Position.y, 20.0f), cameraFront + glm::vec3(m_Position.x, m_Position.y, 0.0f), cameraUp);
    return m_ViewMatrix;
}
