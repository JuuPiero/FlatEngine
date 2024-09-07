#include "Window.h"
#include <glad/gl.h>
#include "LevelEditorScene.h"
#include "Input/MouseListener.h"
#include "Input/KeyListener.h"


// #include <iostream>
// int Window::m_CurrentScene = -1;
Window::Window(const char* title, int width, int height) {
    Initialize();
    m_Props = std::make_shared<WindowProperties>(title, width, height);
    m_Window = glfwCreateWindow(m_Props->Width, m_Props->Height, m_Props->Title, nullptr, nullptr);
    if(m_Window == nullptr) {
        glfwTerminate();
        std::cerr << "fail to create window" << std::endl;
        return;
    }
    glfwSetWindowUserPointer(m_Window, this); 

    glfwMakeContextCurrent(m_Window);
    glfwSwapInterval(1);

    if (!gladLoadGL(static_cast<GLADloadfunc>(glfwGetProcAddress))) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }
    glfwSetCursorPosCallback(m_Window, MouseListener::MousePositionCallback);
    glfwSetMouseButtonCallback(m_Window, MouseListener::MouseButtonCallback);
    glfwSetScrollCallback(m_Window, MouseListener::MouseScrollCallback);
    glfwSetKeyCallback(m_Window, KeyListener::KeyCallback);
    glfwSetFramebufferSizeCallback(m_Window, Window::FrameBufferSizeCallback);
    
    glEnable(GL_DEPTH_TEST);
}
void Window::FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));
    win->m_Props->Width = width;
    win->m_Props->Height = height;
}

Window::~Window() {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
    glfwSetErrorCallback(nullptr);
}

void Window::Initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        throw std::runtime_error("Failed to initialize GLFW");
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(m_Window);
}

void Window::Update() {

    glfwSwapBuffers(m_Window);
    PollEvents();
}
void Window::PollEvents() {
    glfwPollEvents();
}