#ifndef RENDERER_H
#define RENDERER_H

#include <glew.h>
#include <glfw3.h>

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

private:
    GLFWwindow* window;
    GLuint VAO, VBO;
    GLuint shaderProgram;
    void setupShaders();
    void setupCube();
};

#endif // RENDERER_HH