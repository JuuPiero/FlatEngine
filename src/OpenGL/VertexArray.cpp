#include "OpenGL/VertexArray.h"
#include <glad/gl.h>
#include <iostream>
VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_Id);
    glBindVertexArray(m_Id);
}
VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_Id);
}
void VertexArray::Bind() const {
    glBindVertexArray(m_Id);
}

void VertexArray::Unbind() const {
    glBindVertexArray(0);
}

void VertexArray::AddLayout(VertexBuffer& vertexBuffer, BufferLayout layout) {
    GLenum glType;
    switch(layout.type) {
        case Type::FLOAT:
            glType = GL_FLOAT;
            break;
        case Type::DOUBLE:
            glType = GL_DOUBLE;
            break;
        case Type::INT:
            glType = GL_INT;
            break;
        case Type::USIGN_INT:
            glType = GL_UNSIGNED_INT;
            break;
        default:
            break;
    }
    vertexBuffer.Bind();
    glVertexAttribPointer(layout.index, layout.count, glType, layout.normalized ? GL_TRUE : GL_FALSE, layout.size , (void*) (layout.offset));
    glEnableVertexAttribArray(layout.index);
    vertexBuffer.Unbind();

}