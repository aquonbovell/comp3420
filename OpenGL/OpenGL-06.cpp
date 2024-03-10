//
//  OpenGL-06.cpp
//  OpenGL-06
//
//  Created by Aquon Bovell on 02/16/2024.
//

// ==============================================================================
//  PROGRAM: Implementing shaders to create and colour a single triangle, with
//           different colours at each of the vertices. Combining the vertex data
//           and vertex colours in a single vertex array.
//
//           Also grouping the tasks together in the renderScene() function.
// ==============================================================================
//
/*===============================================================================
Install the following in Package Manager:

Install-Package glew_dynamic
Install-Package glfw
Install-Package GLMathematics

==================================================================================*/

// Include standard headers
#include <iostream>
#include <stdlib.h>
using namespace std;

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

// Include our shader functions
#include "shader.h"

// ADD GLOBAL VARIABLES HERE
GLFWwindow *window;

void init_Resources()
{
	// Initialize the hardware resources - to set window, etc.
	if (!glfwInit())
	{
		cout << "\nFailed to Initialize GLFW...";
		exit(EXIT_FAILURE);
	}

	// Create the display window
	window = glfwCreateWindow(800, 600, "COMP3420 - Step 6 - Colour Shaded Triangle", NULL, NULL);

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
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
}

void renderScene()
{
	// Compile and create and  our GLSL program from the shaders
	Shader programShader("vertex06.glsl", "fragment06.glsl");

	GLuint vertexPositionID = glGetAttribLocation(programShader.Program, "vertexPosition");
	//===================================================================//
	//	Action: The data attribute, which is bringing in data into the   //
	//          vertex shader (i.e. vertexPosition), will be stored in a //
	//			    buffer on the graphics card. Return that buffer number   //
	//          so it can be stored in a RAM variable, vertexPositionID. //
	//			    That buffer location will be needed later.	             //
	//===================================================================//

	// Get a handle for our vertices colour buffer.
	// Then we'll pass "vertexColor" to the vertex shader
	GLuint vertexColorID = glGetAttribLocation(programShader.Program, "vertexColor");
	//==================================================================//
	//	Action: The color attribute, which is bringing in data into the //
	//          vertex shader (i.e. vertexColor), will be stored in a   //
	//			    buffer on the graphics card. Return that buffer number  //
	//          so it can be stored in a RAM variable, vertexColorID.   //
	//			    That buffer location will be needed later.	            //
	//==================================================================//

	// Define a single array to hold the vertices coordinates positions
	// and the vertices colour values
	static const GLfloat vertexCoordinates[] =
			{
					// X       Y      Z     R     G     B
					-0.6f,	-0.4f,	0.f,	
					0.6f,	-0.4f,	0.f,		
					0.f,	0.6f,	0.f,
			};
	static const GLfloat vertexColors[] =
	{
		// X       Y      Z     R     G     B
			1.f,	0.f,	0.f,
			0.f,	1.f,	0.f,
			0.f,	0.f,	1.f,
	};



	//======================================================================//
	//	Define the buffers for the VERTICES and COLORS which will be needed //
	//	Action: These are variables in RAM which will hold the buffer       //
	//          numbers from the graphics card where the data for the       //
	//          vertices and the colors will be stored in the graphics      //
	//          memory banks. 										                          //
	//======================================================================//
	GLuint vertexbuffer; // Buffer for vertices
	GLuint colorbuffer;	 // Buffer for colors to match vertices

	//=====================================================================//
	//	Generate the vertex and color buffers                              //
	//	Action: Request the buffers from the graphics card's memory and    //
	//          store the buffers' numbers in the variables in RAM.        //
	//          RAM variables (vertexbuffer and colorbuffer) were          //
	//          defined in the statements previously.                      //
	//=====================================================================//
	glGenBuffers(1, &vertexbuffer);
	glGenBuffers(1, &colorbuffer);

	//=====================================================================//
	//	Bind and load the data into the VERTEX buffer					             //
	//	Action:	glBindBuffer:												                       //
	//			  		Notify the GPU that the buffer number (stored in the     //
	//			  		variable vertexbuffer, is where the vertex data is to be //
	//			  		to be found.                       				          	   //
	//					glBufferData:						                    						   //
	//			  		The nature and purpose of the data.					             //
	//			   		i.e. Data is in an array, quantity of data, container    //
	//						holding the data, and the purpose of the data.           //
	//=====================================================================//
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexCoordinates), vertexCoordinates, GL_STATIC_DRAW);

	//=====================================================================//
	//	Bind and load the data into the COLOR buffer                       //
	//	Action:	glBindBuffer:												                       //
	//			  		Notify the GPU that the buffer number (stored in the     //
	//			  		variable colorbuffer, is where the vertex data is to be  //
	//			  		to be found.                       					             //
	//					glBufferData:												                       //
	//			  		The nature and purpose of the data.					             //
	//			   		i.e. Data is in an array, quantity of data, container    //
	//						holding the data, and the purpose of the data.           //
	//=====================================================================//
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColors), vertexColors, GL_STATIC_DRAW);

	while (glfwWindowShouldClose(window) == 0)
	{
		// Clear the frame buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Start using the shader which was defined previously
		glUseProgram(programShader.Program);

		// Set the **FIRST** attribute buffer : the vertices - first 3 values
		glEnableVertexAttribArray(vertexPositionID); // Declared in line 102
		//=====================================================================//
		//	Action: Enable the buffer containing the vertex data. It's address //
		//          is in vertexPositionID.  It was defined in in line 102.    //
		//=====================================================================//

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		//====================================================================//
		//	Action: Bind the buffer containing the vertex data. That buffer's //
		//          address ss in vertexbuffer. It was defined in line 135.   //
		//====================================================================//

		glVertexAttribPointer(
				vertexPositionID,		 // The attribute we want to configure
				3,									 // size
				GL_FLOAT,						 // type
				GL_FALSE,						 // normalized?
				0 * sizeof(GLfloat), // stride
				(void *)0						 // array buffer offset
		);
		//===================================================//
		//	Action: Define the fragment's vertex attributes. //
		//===================================================//

		// Set the **SECOND** attribute buffer : colors - second 3 values
		glEnableVertexAttribArray(vertexColorID); // Declared in line 99
		//===================================================================//
		//	Action: Enable the buffer containing the color data. It's address//
		//          is in vertexColorID. It was defined in in line 99.       //
		//===================================================================//

		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		//===================================================================//
		//	Action: Bind the buffer containing the color data. That buffer's //
		//          address ss in colorbuffer. It was defined in line 136.   //
		//===================================================================//

		glVertexAttribPointer(
				vertexColorID,								// The attribute we want to configure
				3,														// size
				GL_FLOAT,											// type
				GL_FALSE,											// normalized=false
				0 * sizeof(GLfloat),					// stride
				(void *)(0 * sizeof(GLfloat)) // array buffer offset
		);
		//=====================================================//
		//	Action: Define the fragment's color attributes.	   //
		//=====================================================//

		// Draw the triangle
		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(vertexPositionID);
		glDisableVertexAttribArray(vertexColorID);

		// Swap frame buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // End of while...

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &colorbuffer);
	glDeleteProgram(programShader.Program);
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
