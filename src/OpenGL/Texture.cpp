#include "OpenGL/Texture.h"
#include "Ultils/Ultils.h"

Texture::Texture(const char* path): m_Path(path) {
    glGenTextures(1, &m_Id);
    glBindTexture(GL_TEXTURE_2D, m_Id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    // bytes images
    unsigned char *data = stbi_load(path, &width, &height, &channels, 0);
    
    if (data) {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

Texture::~Texture() {
    // glDeleteTextures(1, &m_Id);
}

void Texture::Bind() const {
    glBindTexture(GL_TEXTURE_2D, m_Id);
}
void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}