#include "Model.h"
#include "Mesh.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

Model::Model(const std::string& path) {
    loadModel(path);
}

void Model::draw(GLuint shaderProgram) {
    for (Mesh& mesh : meshes) {
        mesh.draw(shaderProgram);
    }
}

void Model::loadModel(const std::string& path) {
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> texCoords;
    std::vector<GLuint> indices;

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open OBJ file: " << path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            glm::vec3 position;
            iss >> position.x >> position.y >> position.z;
            positions.push_back(position);
        } else if (prefix == "vn") {
            glm::vec3 normal;
            iss >> normal.x >> normal.y >> normal.z;
            normals.push_back(normal);
        } else if (prefix == "vt") {
            glm::vec2 texCoord;
            iss >> texCoord.x >> texCoord.y;
            texCoords.push_back(texCoord);
        } else if (prefix == "f") {
            std::string vertexData;
            for (int i = 0; i < 3; i++) {
                iss >> vertexData;
                std::replace(vertexData.begin(), vertexData.end(), '/', ' ');

                std::istringstream vertexStream(vertexData);
                GLuint vertexIndex, texCoordIndex, normalIndex;
                vertexStream >> vertexIndex >> texCoordIndex >> normalIndex;

                // Adjust for 0-based indexing
                if (vertexIndex > 0) vertexIndex--;
                if (texCoordIndex > 0) texCoordIndex--;
                if (normalIndex > 0) normalIndex--;

                // Check bounds and push indices
                if (vertexIndex < positions.size()) {
                    indices.push_back(vertexIndex);
                } else {
                    std::cerr << "Vertex index out of range: " << vertexIndex << std::endl;
                }
            }
        }
    }

    file.close();

    meshes.push_back(processMesh(positions, normals, texCoords, indices));
}

Mesh Model::processMesh(const std::vector<glm::vec3>& positions,
                        const std::vector<glm::vec3>& normals,
                        const std::vector<glm::vec2>& texCoords,
                        const std::vector<GLuint>& indices) {
    std::vector<Vertex> vertices;

    for (size_t i = 0; i < positions.size(); i++) {
        Vertex vertex;
        vertex.Position = positions[i];
        vertex.Normal = i < normals.size() ? normals[i] : glm::vec3(0.0f);
        vertex.TexCoords = i < texCoords.size() ? texCoords[i] : glm::vec2(0.0f);
        vertices.push_back(vertex);
    }

    return Mesh(vertices, indices, {});
}
