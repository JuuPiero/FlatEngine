#include "OpenGL/Shader.h"
#include "Ultils/Ultils.h"

#include <glad/gl.h>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

Shader::Shader(const char* vertextShaderPath, const char* fragmentShaderPath): m_vertexShaderPath(vertextShaderPath), m_fragmentShaderPath(fragmentShaderPath) {
    
    const char* vertexShaderSource = GetFileContents(vertextShaderPath).c_str();
    uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    const char* fragmentShaderSource = GetFileContents(fragmentShaderPath).c_str();
    uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    m_Id = glCreateProgram();
    glAttachShader(m_Id, vertexShader);
    glAttachShader(m_Id, fragmentShader);
    glLinkProgram(m_Id);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  
}

Shader::~Shader() {
    glDeleteProgram(m_Id);
}

void Shader::Use() {
    glUseProgram(m_Id);
}

void Shader::SetMatrix4(const char* name, glm::mat4 matrix) {
    glUniformMatrix4fv(glGetUniformLocation(m_Id, name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::SetFloat(const char* name, float value) {
    glUniform1f(glGetUniformLocation(m_Id, name), value);
}
void Shader::SetVec4(const char* name, glm::vec4 value) {
    glUniform4f(glGetUniformLocation(m_Id, name), value.x, value.y, value.z, value.w);
}

void Shader::SetTexture(const char* name, int slot) {
    glUniform1i(glGetUniformLocation(m_Id, name), slot);
}
