#ifndef SHADER_H
#define SHADER_H

#include <glew.h>
#include <string>

class Shader {
public:
    static GLuint createShaderProgram();
private:
    static void checkCompileErrors(GLuint shader, std::string type);
};

#endif // SHADER_H