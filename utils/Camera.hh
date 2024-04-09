#ifndef CAMERA__HH
#define CAMERA__HH

#define GLM_ENABLE_EXPERIMENTAL
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include "ShaderClass.hh"

class Camera
{
private:
public:
    glm::vec3 position;
    glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -0.1f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::mat4 cameraMatrix = glm::mat4(1.0f);

    int width;
    int height;
    
	bool firstClick = true;

    float speed = 0.05f;
    float sensitivity = 100.0f;

    Camera(int width, int height, glm::vec3 position);
    void updateMatrix(float fovDeg, float nearPlane, float farPlane);
    void matrix(Shader& shader, const char* uniform);
    void inputs(GLFWwindow* window);
};

#endif