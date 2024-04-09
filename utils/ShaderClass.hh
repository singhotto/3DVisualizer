#ifndef SHADER_CLASS_HH
#define SHADER_CLASS_HH

#include <glad/gl.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string getFileContent(const char* fileName);

class Shader{
private:
public:
    GLuint Id;
    Shader(const char* vertexFile, const char* fragmentFile);

    void activate();
    void deleteShader();
};

#endif