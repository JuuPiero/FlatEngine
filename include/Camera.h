#pragma once
#include <glm/glm.hpp>

class Camera {
public:
    Camera(glm::vec2 position);
    ~Camera();
    void AdjustProjection();
    glm::mat4 GetViewMatrix();
    inline glm::mat4 GetProjectionMatrix() { return m_ProjectionMatrix; }
private:
    glm::mat4 m_ProjectionMatrix;
    glm::mat4 m_ViewMatrix;
    glm::vec2 m_Position;
};