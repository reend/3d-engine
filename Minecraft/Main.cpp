#include "Renderer.h"
#include <glfw3.h>

int main() {
    Renderer renderer;
    renderer.init();

    float lastFrame = 0.0f;

    while (!renderer.shouldClose()) {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        renderer.processInput(deltaTime); // Убедитесь, что метод processInput вызывается
        renderer.clear();
        renderer.drawCube();
        renderer.swapBuffers();
    }

    renderer.cleanup();
    return 0;
}
