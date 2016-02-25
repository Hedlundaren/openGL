#include <iostream>
#include "include/Tester.hpp"

#define GLEW_STATIC
// #include <external/glew/include/GL/glew.h>
// #include <external/glfw-3.1.2/include/GLFW/glfw3.h>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"



int main() {
    GLFWwindow *window;

    if(!glfwInit()){
        exit(EXIT_FAILURE);
    }
    std::cout << "Hej " << Tester::hej << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(800,600, "OPENGL OR DIE", nullptr, nullptr);
    if(window == nullptr){
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glDepthFunc(GL_GREATER);

    glfwMakeContextCurrent(window);
    std::cout << glGetString(GL_VERSION) << '\n';

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glViewport(0,0,800,600);

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}