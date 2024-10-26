#ifndef TEXTURE_H
#define TEXTURE_H

#include <glew.h>

class Texture {
public:
    static GLuint loadTexture(const char* path);
};

#endif // TEXTURE_H