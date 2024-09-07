#pragma once

#include <glm/glm.hpp>

class Shader {
public:
    Shader(const char* vertextShaderPath, const char* fragmentShaderPath);
    ~Shader();
    void Use();

    void SetMatrix4(const char* name, glm::mat4 matrix);
    void SetFloat(const char* name, float value);
    void SetVec4(const char* name, glm::vec4 value);
    void SetTexture(const char* name, int slot);
    inline unsigned int GetProgram() const { return m_Id; }
private:
    unsigned int m_Id;
    std::string m_vertexShaderPath;
    std::string m_fragmentShaderPath;
};