#include "Renderer/RenderBatch.h"

RenderBatch::RenderBatch(int maxBatchSize): maxBatchSize(maxBatchSize), numSprites(0), hasRoom(true) {
    
    // vbo = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
    // vertices 

}

RenderBatch::~RenderBatch() {}

void RenderBatch::Start() {
    vao = std::make_shared<VertexArray>();
    shader = std::make_shared<Shader>("../shaders/default.vert", "../shaders/default.frag");
    vbo = std::make_shared<VertexBuffer>(vertices.data(), vertices.size() * sizeof(float));
    // auto ebo = std::make_shared<ElementBuffer>(); 
}
