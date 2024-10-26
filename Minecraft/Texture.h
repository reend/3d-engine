#ifndef TEXTURE_H
#define TEXTURE_H

#include <glew.h>

class Texture {
public:
    GLuint id;  // Add this line
    static GLuint loadTexture(const char* path);
};

#endif // TEXTURE_H
