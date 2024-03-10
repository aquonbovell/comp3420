//
//  OpenGL-02.cpp
//  OpenGL-02
//
//  Created by Aquon Bovell on 01/22/2024.

// ==============================================================================
//  PROGRAM: Step 2 - Creates An Empty Red Window Using Modularized Function
//==============================================================================

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

using namespace std;

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
	window = glfwCreateWindow(640, 480, "COMP3420 - Step 2 - Empty Red Window", NULL, NULL);

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

	// Set the window's background colour (to RED)
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

//...And now the main function - The traffic master.
int main(int argc, char *argv[])
{

	init_Resources();

	//==========================================================================//
	// At this stage... All systems are OK, poceed with window and view setup   //
	//==========================================================================//

	// Keep displaying the window until we have shut it down
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT); // Flush the color buffer
		glfwSwapBuffers(window);			// Swap the front and back buffers
		glfwPollEvents();							// Listen for other events
	}

	// Close the display window
	glfwDestroyWindow(window);

	// Release ALL the other resources
	glfwTerminate();

	// Shut down the program gracefully
	exit(EXIT_SUCCESS);
}
