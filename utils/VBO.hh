#ifndef VBO__HH
#define VBO__HH

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <vector>

struct Vertex
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 texUV;
};


class VBO{
    private:
    public:
        GLuint Id;
        VBO(std::vector<Vertex>& vertices);

        void Bind();
        void Unbind();
        void Delete();
};

#endif