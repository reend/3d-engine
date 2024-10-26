#include "Renderer.h"

int main() {
    Renderer renderer;
    renderer.init();
    while (!renderer.shouldClose()) {
        renderer.clear();
        renderer.drawCube();
        renderer.swapBuffers();
    }
    renderer.cleanup();
    return 0;
}