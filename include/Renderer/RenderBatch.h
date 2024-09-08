#pragma once
#include "Components/SpriteRenderer.h"
#include "Ultils/Ultils.h"
#include "OpenGL/Shader.h"
#include "OpenGL/Buffer.h"
#include "OpenGL/VertexArray.h"

#include <vector>

class RenderBatch {
public:
    RenderBatch(int maxBatchSize);
    ~RenderBatch();
    void Start();
public:
    int positionCount = 2;
    int colorCount = 4;

    int positionOffset = 0;
    int colorOffset =  (positionCount + positionOffset) * sizeof(float);
    
    int vertexCount = 6;
    int vertexSize = vertexCount * sizeof(float);
    
    std::vector<Shared<SpriteRenderer>> sprites;
    int numSprites;
    bool hasRoom;
    // float* vertices;
    std::vector<float> vertices;
    int maxBatchSize;

    Shared<Shader> shader;
    Shared<VertexBuffer> vbo;
    Shared<VertexArray> vao;

};


