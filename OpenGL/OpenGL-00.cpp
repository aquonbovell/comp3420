//
//  OpenGL-00.cpp
//  OpenGL-00
//
//  Created by Aquon Bovell on 02/07/2024.
//

// ==============================================================================
//  PROGRAM: Testing OpenGL hardware and software system
// ==============================================================================

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cstdlib>
#include <iostream>

// FreeImage headers, for digital image format support.
// #include "FreeImage.h"

using namespace std;

// ADD GLOBAL VARIABLES HERE
GLFWwindow* window;

void init_Resources()
{
  // Initialize the resources - set window, etc.
  if (!glfwInit())
  {
    cout << "\nFailed to Initialize GLFW...";
    exit(EXIT_FAILURE);
  }

  // Grab the OpenGL hardware and software stuff
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  // Create the display window
  window = glfwCreateWindow(800, 600, "COMP3420 - Step 0 - System Versions", NULL, NULL);

  //If window fails creation, then shut down the whole thing
  if (!window)
  {
    cout << "\nFailed to open display window...";
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  //If window succeeded then make it active on the display device
  glfwMakeContextCurrent(window);

  // ******  ABSOLUTELY required otherwise glGenVertexArrays will FAIL! *************
  glewExperimental = GL_TRUE;

  // Initialize GLEW
  if (glewInit() != GLEW_OK)
  {
    cout << "\nFailed to initialize GLEW...";
    exit(EXIT_FAILURE);
  }

  // Initializing FreeImage:
  // FreeImage_Initialise(TRUE); // only load local plugins.

  //Set the window's background colour (to GREY)
  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

}

int main(int argc, char* argv[])
{

  // Initialize the required resources
  init_Resources();

  //==========================================================================//
  // At this stage... All systems are OK, poceed with window and view setup   //
  //==========================================================================//

  // Get the information for the GLFW3
  int major;
  int minor;
  int rev;
  glfwGetVersion(&major, &minor, &rev);

  // Now print out some info about the graphics drivers
  cout << "OpenGL version    : " << glGetString(GL_VERSION) << endl;
  cout << "GLFW version      : " << major << "." << minor << "." << rev << "\n";
  cout << "GLSL version      : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
  cout << "GLM version       : " << GLM_VERSION_MAJOR << "." << GLM_VERSION_MINOR
    << "." << GLM_VERSION_PATCH << "."
    << GLM_VERSION_REVISION << "\n";
  //cout << "FreeImage version : " << FreeImage_GetVersion() << "\n";
  cout << "Graphics Engine   : " << glGetString(GL_RENDERER) << endl;
  cout << "Vendor            : " << glGetString(GL_VENDOR) << "\n\n";

  //Close the display window
  glfwDestroyWindow(window);

  //Release ALL the other resources
  glfwTerminate();

  // Shut down the program gracefully
  exit(EXIT_SUCCESS);
}