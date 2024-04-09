/* Ask for an OpenGL Core Context */
#define GLFW_INCLUDE_GLCOREARB
#include <glad/gl.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

#include "./utils/ShaderClass.hh"
#include "./utils/VAO.hh"
#include "./utils/VBO.hh"
#include "./utils/EBO.hh"

int width = 800;
int height = 800;

// Vertices coordinates
GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	 0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 
	 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f
};



int main(){
    glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFWwindow object of 800 by 800 pixels, naming it "OTTO TESTING"
	GLFWwindow* window = glfwCreateWindow(width, height, "OTTO TESTING", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

    gladLoaderLoadGL();
    glViewport(0, 0, width, height);


	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("/Users/singhotto/Documents/3dVisualizer/shaders/default.vert", "/Users/singhotto/Documents/3dVisualizer/shaders/default.frag");

	VAO vao;

	vao.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO vbo(vertices, sizeof(vertices));


	// Links VBO attributes such as coordinates and colors to VAO
	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	
	// Unbind all to prevent accidentally modifying them
	vao.Unbind();
	vbo.Unbind();


	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.Id, "scale");


	// Main while loop
	while (!glfwWindowShouldClose(window))
	{


        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.activate();
		vao.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 8);

        glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
    }

	vao.Delete();
	vbo.Delete();
	shaderProgram.deleteShader();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();

    return 0;
}