#pragma once

#include "OpenGL/Buffer.h"

enum Type {
    INT,
    FLOAT,
    DOUBLE,
    USIGN_INT
};

struct BufferLayout {
    unsigned int index;
    unsigned int count;
    Type type;
    bool normalized;
    int size;
    int offset; // offset 
};

class VertexArray {
public:
    VertexArray();
    ~VertexArray();
    void Bind() const;
    void Unbind() const;

    void AddLayout(VertexBuffer& vertexBuffer, BufferLayout layout);
    
private:
    unsigned int m_Id;
};

