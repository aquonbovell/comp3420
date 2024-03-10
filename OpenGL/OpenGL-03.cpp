//
//  OpenGL-03.cpp
//  OpenGL-03
//
//  Created by Aquon Bovell on 01/22/2024.

// ============================================================================
//  PROGRAM: Step 3 - Creates four windows, each in a different color.
//                    Windows are created and managed procedurely.
//                    When one window is closed, all the other windows close.
//==============================================================================

#include <GLFW/glfw3.h>
#include <stdlib.h>

// Captions for the windows
static const char *title1 = "Xiansee";
static const char *title2 = "Bonzai";
static const char *title3 = "Qweku";
static const char *title4 = "Ed";

int main(int argc, const char *argv[])
{
  GLboolean running = GL_TRUE;

  GLFWwindow *window1;
  GLFWwindow *window2;
  GLFWwindow *window3;
  GLFWwindow *window4;

  // Initialize GLFW
  if (!glfwInit())
    exit(EXIT_FAILURE);
  glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

  //====================================================//
  //        Set up the first window - Xiansee           //
  //====================================================//

  // Initialize window1
  window1 = glfwCreateWindow(300, 300, title1, NULL, NULL);

  // Test to see if window1 was initialized
  if (!window1)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Make window1 active
  glfwMakeContextCurrent(window1);

  // set the background colour to BLUE
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

  // Position the top-left corner of the window
  glfwSetWindowPos(window1, 100, 100);

  // Display Xiansee's window
  glfwShowWindow(window1);

  //====================================================//
  //        Set up the second window - Bonzai           //
  //====================================================//

  // Initialize window2
  window2 = glfwCreateWindow(300, 300, title2, NULL, NULL);

  // Test to see if window2 was initialized
  if (!window2)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Make window2 active
  glfwMakeContextCurrent(window2);

  // set the background colour to GREEN
  glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

  // Position the top-left corner of the window
  glfwSetWindowPos(window2, 450, 100);

  // Display Bonzai's window
  glfwShowWindow(window2);

  //====================================================//
  //        Set up the third window - Kweku             //
  //====================================================//

  // Initialize window3
  window3 = glfwCreateWindow(300, 300, title3, NULL, NULL);

  // Test to see if window3 was initialized
  if (!window3)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Make window3 active
  glfwMakeContextCurrent(window3);

  // set the back ground colour to RED
  glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

  // Position the top-left corner of the window
  glfwSetWindowPos(window3, 100, 450);

  // Display Kewku's window
  glfwShowWindow(window3);

  //====================================================//
  //        Set up the fourth window - Ed               //
  //====================================================//

  // Initialize window4
  window4 = glfwCreateWindow(300, 300, title4, NULL, NULL);

  // Test to see if window4 was initialized
  if (!window4)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Make window4 active
  glfwMakeContextCurrent(window4);

  // set the background colour to YELLOW
  glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

  // Position the top-left corner of the window
  glfwSetWindowPos(window4, 450, 450);

  // Display Ed's window
  glfwShowWindow(window4);

  //==================================================================//
  //      As long as the window are opened, keep doing stuff         //
  //==================================================================//
  while (running)
  {
    glfwMakeContextCurrent(window1);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window1);

    glfwMakeContextCurrent(window2);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window2);

    glfwMakeContextCurrent(window3);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window3);

    glfwMakeContextCurrent(window4);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window4);

    // Check if Xiansee was closed
    if (glfwWindowShouldClose(window1))
      running = GL_FALSE;

    // Check if Bonzai was closed
    if (glfwWindowShouldClose(window2))
      running = GL_FALSE;

    // Check if Kweku was closed
    if (glfwWindowShouldClose(window3))
      running = GL_FALSE;

    // Check if Ed was closed
    if (glfwWindowShouldClose(window4))
      running = GL_FALSE;

    glfwPollEvents();
  }

  // Once running becomes false, shut down the program
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
