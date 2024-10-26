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
    void drawCube();
    void processInput(float deltaTime);
    void clear();
    void swapBuffers();
    void cleanup();
    bool shouldClose() const;
    Camera* getCamera() const;

private:
    GLFWwindow* window;
    GLuint VAO, VBO;
    GLuint groundVAO, groundVBO; // Ensure these are declared
    GLuint shaderProgram;
    Camera* camera;

    void setupShaders();
    void setupCube();
    void setupGround(); // Ensure this is declared
    void drawGround();  // Ensure this is declared
};

#endif // RENDERER_H
