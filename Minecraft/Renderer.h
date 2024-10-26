#ifndef RENDERER_H
#define RENDERER_H

#include <glew.h>
#include <glfw3.h>
#include "Camera.h"

class Renderer {
public:
    Renderer();
    ~Renderer();
    void init();
    void clear();
    void drawCube();
    void swapBuffers();
    void cleanup();
    bool shouldClose() const;
    void processInput(float deltaTime); // Добавляем метод processInput

private:
    GLFWwindow* window;
    GLuint VAO, VBO;
    GLuint shaderProgram;
    Camera* camera; // Добавляем указатель на Camera

    void setupShaders();
    void setupCube();
};

#endif // RENDERER_H
