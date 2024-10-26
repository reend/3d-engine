#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <glm.hpp>
#include <vector>
#include <string>
#include "Texture.h"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

class Mesh {
public:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;

    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
    void draw(GLuint shaderProgram);

private:
    GLuint VAO, VBO, EBO;
    void setupMesh();
};

#endif // MESH_H
