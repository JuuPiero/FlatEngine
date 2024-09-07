#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include "Ultils/Time.h"

#define PrintLn(mess) std::cout << mess << std::endl

inline std::string GetFileContents(const char* filePath) {
    std::ifstream ifs(filePath);
    std::string content( (std::istreambuf_iterator<char>(ifs)),
                       (std::istreambuf_iterator<char>()) );
    return content;
}

template <typename T> using Unique = std::unique_ptr<T>;
template <typename T> using Shared = std::shared_ptr<T>;
// template <typename T> using MakeShared = std::make_shared<T>;
