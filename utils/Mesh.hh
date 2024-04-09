#ifndef MESH_HH
#define MESH_HH

#define GLFW_INCLUDE_GLCOREARB
#include <string>
#include <vector>
#include"VAO.hh"
#include"EBO.hh"
#include"Camera.hh"
#include"Texture.hh"

class Mesh{
private:
public:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;

    VAO vao;

    Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures);
    void draw(Shader& shader, Camera& camera);

};

#endif