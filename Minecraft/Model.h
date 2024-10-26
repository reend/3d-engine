#ifndef MODEL_H
#define MODEL_H

#include <glew.h>
#include <glm.hpp>
#include <string>
#include <vector>
#include "Mesh.h"

class Model {
public:
    Model(const std::string& path);
    void draw(GLuint shaderProgram);

private:
    std::vector<Mesh> meshes;
    std::string directory;

    void loadModel(const std::string& path);
    Mesh processMesh(const std::vector<glm::vec3>& positions,
                     const std::vector<glm::vec3>& normals,
                     const std::vector<glm::vec2>& texCoords,
                     const std::vector<GLuint>& indices);
};

#endif // MODEL_H
