#include "OpenGL/Buffer.h"
#include <glad/gl.h>
ElementBuffer::ElementBuffer(unsigned int* indices, unsigned int count): m_Count(count), Buffer(indices) {
    glGenBuffers(1, &m_Id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

ElementBuffer::~ElementBuffer() {
    glDeleteBuffers(1, &m_Id);
}
void ElementBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
}
void ElementBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}