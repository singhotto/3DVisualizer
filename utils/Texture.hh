#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/gl.h>
#include "ShaderClass.hh"

class Texture
{
public:
	GLuint Id;
	GLenum type;
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	// Assigns a texture unit to a texture
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	// Binds a texture
	void Bind();
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
};
#endif