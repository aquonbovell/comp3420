    //
    //  OpenGL-09.cpp
    //  OpenGL-03
    //
    //  Created by Dr. John Charlery on 03/07/2024.
    //  Copyright (c) 2024 University of the West Indies. All rights reserved.
    //



// ==============================================================================
//  PROGRAM:
//  Instancing: Animated Textured Sphere - Spinning Earth.
// ==============================================================================


// ==============================================================================
//  Steps to create the MVP:
//    1.  Setup and compile our shaders as an object of the Shader class.
//    2.  Load the geometrical model objects.
//    3.  Create the projection matrix.
//    4.  Create the view matrix
//    5.  Create the model matrix – initially as an identity matrix and
//        then modify with scaling, translation, rotation, etc, if required.
//    6.  Pass the model, view and projection matrices to the shaders.
//    7.  Draw the object.
//
// ==============================================================================
/*============================================================================= =
Install the following in Package Manager :

Install-Package glew_dynamic
Install-Package glfw
Install-Package GLMathematics
Install-Package freeimage -version 3.16.0
Install-Package nupengl.core
Install-Package Soil
Install-Package Assimp -version 3.0.0

=================================================================================*/


// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

    // GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// GL includes
#include "shader.h"
#include "camera.h"
#include "model.h"



// Active window
GLFWwindow* window;

// Properties
GLuint sWidth = 800, sHeight = 800;


// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 1500.0f));


GLfloat planetAngle = 0.0;


void init_Resources()
    {
        // Init GLFW
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        
        // Define the window
        window = glfwCreateWindow(sWidth, sHeight, "COMP3420 - Animating, Textured Sphere", 0, 0);
        glfwMakeContextCurrent(window);
        
       
        // Initialize GLEW to setup the OpenGL Function pointers
        glewExperimental = GL_TRUE;
        glewInit();
    
    
        // Define the viewport dimensions
        glViewport(0, 0, sWidth, sHeight);
        
        // Setup OpenGL options
        glEnable(GL_DEPTH_TEST);
    
    }



// The MAIN function, from here we start our application and run the loop
int main()
{
    init_Resources();
    
    GLfloat newX = 0.0f;
    GLfloat xinc = 0.1f;
    
    // ==============================================
    // ====== Set up the stuff for our sphere =======
    // ==============================================
    
    
    // =======================================================================
    // Step 1. Setup and compile our shaders as an object of the Shader class
    // =======================================================================
    Shader planetShader("planetVertex.glsl", "planetFragment.glsl");

    
    
    
    
    // =======================================================================
    // Step 2. Load the geometrical model objects
    // =======================================================================
    Model planet((GLchar*)"planet.obj");        // ... Earth
    
    
    
    
    
    // =======================================================================
    // Step 3. Set the projection matrix
    // =======================================================================
    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)sWidth/(GLfloat)sHeight,
                                            1.0f, 10000.0f);
    planetShader.Use();
    glUniformMatrix4fv(glGetUniformLocation(planetShader.Program, "projection"),
                       1, GL_FALSE, glm::value_ptr(projection));

    
    

    // Iterate this block while the window is open
    while(!glfwWindowShouldClose(window))
    {

        // Check and call events
        glfwPollEvents();

        // Clear buffers
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        
        // Add transformation matrices
    
    
        // =======================================================================
        // Step 4. create the View matrix
        // =======================================================================
        planetShader.Use();
        glUniformMatrix4fv(glGetUniformLocation(planetShader.Program, "view"), 1,
                           GL_FALSE, glm::value_ptr(camera.GetViewMatrix()));
    
    
    

        // =======================================================================
        // Step 5. Create the model matrix (We'll call it "planetModel" in this case)
        // =======================================================================
        planetShader.Use();
        glm::mat4 planetModel = glm::mat4(1);
    
        //Modify the model matrix with scaling, translation, rotation, etc
        planetModel = glm::scale(planetModel, glm::vec3(100.0f));
        planetModel = glm::translate(planetModel, glm::vec3(newX, newX, 0.0f));
        
        if (newX > 10.0 || newX < -10.0)
            xinc *= -1.0;
        newX += xinc;
        
        
        // Make it rotate around the y-axis
        planetAngle += 0.1;
        1;
        if (planetAngle > 360) planetAngle = 0.01;
        planetModel = glm::rotate(planetModel, planetAngle, glm::vec3(0.0f, 1.0f, 0.0f));
    
    
    
    
    
        // =======================================================================
        // Step 6. Pass the Model matrix, "planetModel", to the shader as "model"
        // =======================================================================
        glUniformMatrix4fv(glGetUniformLocation(planetShader.Program, "model"), 1,
                           GL_FALSE, glm::value_ptr(planetModel));
    
    
    
    
        // =======================================================================
        // Step 7.  Draw the object.
        // =======================================================================
        planet.Draw(planetShader);

    
    
        
        // Swap the buffers
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return 0;
}
