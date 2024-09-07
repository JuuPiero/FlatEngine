#pragma once
#include <vector>

class Buffer {
public:
    Buffer(void* data): m_Data(data) {}
    ~Buffer() = default;
    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;
protected:
    void* m_Data;
    unsigned int m_Id;
};

class VertexBuffer : public Buffer {

public:
    VertexBuffer(void* data, unsigned int size);
    ~VertexBuffer();
    void Bind() const override;
    void Unbind() const override;

private:
    // unsigned int m_Id;
    void* m_Data;
    unsigned int m_Size;
    unsigned int m_Length; 
    unsigned int m_Count;
};

class ElementBuffer: public Buffer {
public:
    ElementBuffer(unsigned int* indices, unsigned int count);
    ~ElementBuffer();
    void Bind() const override;
    void Unbind() const override;
    inline unsigned int Count() const { return m_Count; }
private:
    // unsigned int m_Id;
    unsigned int m_Count;
    std::vector<unsigned int> m_Indices;
};
