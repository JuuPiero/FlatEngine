#pragma once
#include <iostream>

class Texture {

public:
    Texture(const char* path);
    ~Texture();
    void Bind() const;
    void Unbind() const;
private:
    unsigned int m_Id;
    std::string m_Path;
};


