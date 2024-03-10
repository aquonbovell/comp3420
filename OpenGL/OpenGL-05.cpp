//
//  OpenGL-05.cpp
//  OpenGL-05
//
//  Created by Aquon Bovell on 06/20/2024.
//

// ==============================================================================
//  PROGRAM: Implementing shaders to create single triangle - coloured RED all
//			 over.
//           Using a crude shader program called "simpleShader.h"
// ==============================================================================
/*===============================================================================
Install the following in Package Manager when running on Windows:

Install-Package glew_dynamic
Install-Package glfw
Install-Package GLMathematics

=================================================================================*/

// Include standard headers
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;

// Include GLEW
#include <GL\glew.h>

// Include GLFW
#include <GLFW\glfw3.h>

// Include GLM
#include <glm\glm.hpp>
using namespace glm;

// Include our shader functions
#include "simpleShader.h" // We'll start using "shader.h" instead very soon.

// ADD GLOBAL VARIABLES HERE
GLFWwindow *window;

void init_Resources()
{
	// Initialize the resources - set window, etc.
	if (!glfwInit())
	{
		cout << "\nFailed to Initialize GLFW...";
		exit(EXIT_FAILURE);
	}

	// Create the display window
	window = glfwCreateWindow(800, 600, "COMP3420 - Step 5 - Simple Red Triangle", NULL, NULL);

	// If window fails creation, then shut down the whole thing
	if (!window)
	{
		cout << "\nFailed to open display window...";
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// If window succeeded then make it active on the display device
	glfwMakeContextCurrent(window);

	// ******  ABSOLUTELY required otherwise glGenVertexArrays will FAIL! *************
	glewExperimental = GL_TRUE;

	// Initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		cout << "\nFailed to initialize GLEW...";
		exit(EXIT_FAILURE);
	}

	// Set the window's background colour (to GREY)
	glClearColor(0.85f, 0.85f, 0.85f, 1.0f);
}

void renderScene()
{
	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders("vertex05.glsl", "fragment05.glsl");

	// Get a handle for our vertices positions buffer.
	// Then we'll pass "vertexPosition" to the vertex shader
	GLuint vertexPositionID = glGetAttribLocation(programID, "vertexPosition");

	// Define an array to hold the vertices coordinates positions
	static const GLfloat vertexData[] =
		{
			// X      Y      Z
			-0.6f,	-0.4f,	0.f,
			0.6f,		-0.4f,	0.f,
			0.f,		 0.6f,	0.f,
		};

	// Load in the vertices coordinate data into a vertex buffer
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	while (glfwWindowShouldClose(window) == 0)
	{
		// Clear the frame buffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Start using the Program shader
		glUseProgram(programID);

		// Set the **FIRST** attribute buffer : The vertices data
		glEnableVertexAttribArray(vertexPositionID);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
				vertexPositionID, // The attribute we want to configure
				3,								// size
				GL_FLOAT,					// type
				GL_FALSE,					// normalized?
				0,								// stride
				(void *)0					// array buffer offset
		);

		// Draw the triangle
		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

		// Release the vertex buffer
		glDisableVertexAttribArray(vertexPositionID);

		// Swap the frame buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // End of while...

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteProgram(programID);
}

int main(int argc, char *argv[])
{

	// Initialize the required resources
	init_Resources();

	//==========================================================================//
	// At this stage... All systems are OK, poceed with window and view setup   //
	//==========================================================================//

	// Keep displaying the window until we have shut it down
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT); // Flush the color buffer

		renderScene(); // Create objects for the scene
	}

	// Close the display window
	glfwDestroyWindow(window);

	// Release ALL the other resources
	glfwTerminate();

	// Shut down the program gracefully
	exit(EXIT_SUCCESS);
}
