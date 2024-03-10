//
//  OpenGL-04.cpp
//  OpenGL-04
//
//  Created by Aquon Bovell on 01/22/2024.
//  Copyright (c) 2024 University of the West Indies. All rights reserved.

// ==========================================================================
//  PROGRAM: Step 4 - Creates four windows, each in a different color.
//                    Windows are created and managed as a group.
//                    When one window is closed, all the other windows close.
//============================================================================

#include <GLFW/glfw3.h>
#include <stdlib.h>

// Group the titles together in an array
static const char *titles[4] =
		{
				"Xiansee",
				"Bonzai",
				"Qweku",
				"Ed"};

int main(int argc, const char *argv[])
{
	int i;
	int left, top, right, bottom;
	GLboolean running = GL_TRUE;

	// Group the windows together in an array
	GLFWwindow *windows[4];

	// Initialize GLFW
	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

	//====================================================//
	//        Set up the windows through a loop           //
	//====================================================//

	for (i = 0; i < 4; i++)
	{
		// Initialize windows[i]
		windows[i] = glfwCreateWindow(300, 300, titles[i], NULL, NULL);

		// Test to see if windows[i] was initialized
		if (!windows[i])
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		// Make windows[i] active
		glfwMakeContextCurrent(windows[i]);

		// set the background colour for windows[i]
		glClearColor((GLclampf)(i & 1), (GLclampf)(i >> 1), i ? 0.f : 1.f, 1.f);

		// retrieve sizes, in screen coordinates, of each edge of the frame
		glfwGetWindowFrameSize(windows[i], &left, &top, &right, &bottom);

		// Position the top-left corner of the windows[i]
		glfwSetWindowPos(windows[i],
										 100 + (i & 1) * (300 + left + right) + (i % 2) * 50,
										 100 + (i >> 1) * (300 + top + bottom) + (i >> 1) * 50);
	}

	// Display each of the windows
	for (i = 0; i < 4; i++)
		glfwShowWindow(windows[i]);

	//==================================================================//
	//      As long as the windows are opened, keep doing stuff         //
	//==================================================================//

	int closedWindows = 0;

	while (running)
	{
		for (i = 0; i < 4; i++)
		{
			if (windows[i])
			{
				glfwMakeContextCurrent(windows[i]);
				glClear(GL_COLOR_BUFFER_BIT);
				glfwSwapBuffers(windows[i]);

				// Check if windows[i] was closed
				if (glfwWindowShouldClose(windows[i]))
				{
					glfwDestroyWindow(windows[i]);
					windows[i] = nullptr;
					closedWindows++;

					if (closedWindows > 3)
						running = GL_FALSE;
				}
			}
		}

		glfwPollEvents();
	}

	//        while (running)
	//        {
	//            for (i = 0;  i < 4;  i++)
	//            {
	//                glfwMakeContextCurrent(windows[i]);
	//                glClear(GL_COLOR_BUFFER_BIT);
	//                glfwSwapBuffers(windows[i]);
	//
	//                // Check if any of the windows was closed
	//                if (glfwWindowShouldClose(windows[i]))
	//                    running = GL_FALSE;
	//            }
	//
	//            glfwPollEvents();
	//        }

	// Once running becomes false, shut down the program
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
