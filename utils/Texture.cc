#include "Texture.hh"
#include <opencv2/opencv.hpp>

Texture::Texture(const char *image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
    // Assigns the type of the texture ot the texture object
    type = texType;

    // Reads the image using OpenCV
    cv::Mat img = cv::imread(image);

    // Check if the image was loaded successfully
    if (img.empty())
    {
        std::cerr << "Error: Unable to load image: " << image << std::endl;
        return;
    }
    // Flip the image vertically to match OpenGL's coordinate system
    cv::flip(img, img, 0); // 0 for flipping around the x-axis
    // cv::flip(img, img, 1); // 0 for flipping around the y-axis
    // Generate OpenGL texture object
    glGenTextures(1, &Id);
    // Assign the texture to a Texture Unit
    glActiveTexture(slot);
    glBindTexture(texType, Id);

    // Configure texture parameters
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Assign the image data to the OpenGL Texture object
    glTexImage2D(texType, 0, GL_RGB, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());

    // glTexImage2D(texType, 0, GL_RGB, img.cols, img.rows, 0, GL_BGR, GL_FLOAT, dd);
    // Generate MipMaps
    glGenerateMipmap(texType);
}

void Texture::texUnit(Shader &shader, const char *uniform, GLuint unit)
{
    // Gets the location of the uniform
    GLuint texUni = glGetUniformLocation(shader.Id, uniform);
    // Shader needs to be activated before changing the value of a uniform
    shader.activate();
    // Sets the value of the uniform
    glUniform1i(texUni, unit);
}

void Texture::Bind()
{
    glBindTexture(type, Id);
}

void Texture::Unbind()
{
    glBindTexture(type, 0);
}

void Texture::Delete()
{
    glDeleteTextures(1, &Id);
}