//
//  OpenGL-08.cpp
//  OpenGL-08
//
//  Created by Dr. John Charlery on 02/22/2024.
//  Copyright (c) 2024 University of the West Indies. All rights reserved.

// ==========================================================================
//  PROGRAM:
//          Introducing Animation...
//          Implementing ROTATION and TRANSLATION of a cube, constructed
//          from 12 coloured triangles, and using the Model-View-Projection
//          matrix (MVP) with data from different vertex and color arrays.
// ==============================================================================

// Include standard headers
#include <iostream>
#include <stdlib.h>


// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>


// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;
using namespace std;

#include "shader.h"



GLFWwindow* window;



void init_Resources()
    {
            // Initialize the resources - set window, etc.
        if (!glfwInit())
            {
                cout << "\nFailed to Initialize GLFW...";
                exit(EXIT_FAILURE);
            }
        
        
            // Create the display window
        window = glfwCreateWindow(800, 600, "COMP3420 - Step 8 - Rotating and Translating Cube Shaded Triangles", NULL, NULL);
        
        
            //If window fails creation, then shut down the whole thing
        if (!window)
            {
                cout << "\nFailed to open display window...";
                glfwTerminate();
                exit(EXIT_FAILURE);
            }
        
        
            //If window succeeded then make it active on the display device
        glfwMakeContextCurrent(window);
        
        
            // ******  ABSOLUTELY required otherwise glGenVertexArrays will FAIL! ******
        glewExperimental = GL_TRUE;
        
        
            // Initialize GLEW
        if (glewInit() != GLEW_OK)
            {
                cout << "\nFailed to initialize GLEW...";
                exit(EXIT_FAILURE);
            }
    
            //Set the window's background colour (to GREY)
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
        
    }



void renderScene()
    {
        //--- Some NEW stuff ----------------------------------------------------//
        //  Define variables to be used for the animation                        //
        //------------------ ----------------------------------------------------//
        static GLfloat angle = 0.0;
        static GLfloat newX  = 0.0;
        GLfloat xInc = 0.01;

    

            // Create and compile our GLSL program from the shaders
        Shader programShader( "vertex8.glsl", "fragment8.glsl" );

            // Get a handle for our vertices positions buffer.
            // Then we'll pass "vertexPosition" to the vertex shader
        GLuint vertexPositionID = glGetAttribLocation(programShader.Program, "vertexPosition");
    
            // Get a handle for our vertices colour buffer.
            // Then we'll pass "vertexColor" to the vertex shader
        GLuint vertexColorID = glGetAttribLocation(programShader.Program, "vertexColor");
    
    
        
            // Our vertices. 3 consecutive floats give a 3D vertex;
            // Three consecutive vertices give a triangle.
            // A cube has 6 faces with 2 triangles each.
            // So this makes 6*2 = 12 triangles, and 12*3 vertices
        static const GLfloat vertexData[] =
            { //  X     Y     Z       X     Y     Z        X     Y     Z
                -1.0f,-1.0f,-1.0f,  -1.0f,-1.0f, 1.0f,  -1.0f, 1.0f, 1.0f,
                 1.0f, 1.0f,-1.0f,  -1.0f,-1.0f,-1.0f,  -1.0f, 1.0f,-1.0f,
                 1.0f,-1.0f, 1.0f,  -1.0f,-1.0f,-1.0f,   1.0f,-1.0f,-1.0f,
                 1.0f, 1.0f,-1.0f,   1.0f,-1.0f,-1.0f,  -1.0f,-1.0f,-1.0f,
                -1.0f,-1.0f,-1.0f,  -1.0f, 1.0f, 1.0f,  -1.0f, 1.0f,-1.0f,
                 1.0f,-1.0f, 1.0f,  -1.0f,-1.0f, 1.0f,  -1.0f,-1.0f,-1.0f,
                -1.0f, 1.0f, 1.0f,  -1.0f,-1.0f, 1.0f,   1.0f,-1.0f, 1.0f,
                 1.0f, 1.0f, 1.0f,   1.0f,-1.0f,-1.0f,   1.0f, 1.0f,-1.0f,
                 1.0f,-1.0f,-1.0f,   1.0f, 1.0f, 1.0f,   1.0f,-1.0f, 1.0f,
                 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,-1.0f,  -1.0f, 1.0f,-1.0f,
                 1.0f, 1.0f, 1.0f,  -1.0f, 1.0f,-1.0f,  -1.0f, 1.0f, 1.0f,
                 1.0f, 1.0f, 1.0f,  -1.0f, 1.0f, 1.0f,   1.0f,-1.0f, 1.0f
            };

        
            // One color for each vertex. 3 consecutive floats (RGB) give a vertex colour
        static const GLfloat vertexColour[] =
            { // R     G     B       R     G     B       R     G     B
                0.5f, 0.7f, 0.0f,   0.6f, 0.1f, 0.4f,   0.3f, 0.4f, 0.8f,
                0.8f, 0.5f, 0.2f,   0.4f, 0.6f, 0.2f,   0.3f, 0.7f, 0.1f,
                0.5f, 0.7f, 0.7f,   0.5f, 0.4f, 0.7f,   0.3f, 0.5f, 0.1f,
                0.4f, 0.5f, 0.7f,   0.5f, 0.8f, 0.6f,   0.1f, 0.5f, 0.8f,
                0.0f, 0.1f, 0.5f,   0.7f, 0.3f, 0.9f,   0.4f, 0.6f, 0.1f,
                0.6f, 0.9f, 0.1f,   0.9f, 0.5f, 0.8f,   0.1f, 0.6f, 0.4f,
                0.9f, 0.5f, 0.0f,   0.9f, 0.7f, 0.5f,   0.5f, 0.0f, 0.9f,
                0.2f, 0.3f, 0.5f,   0.1f, 0.6f, 0.0f,   0.3f, 0.8f, 0.1f,
                0.0f, 0.9f, 0.0f,   0.7f, 0.5f, 0.3f,   0.7f, 0.2f, 0.7f,
                0.7f, 0.6f, 0.1f,   0.3f, 0.4f, 0.8f,   0.2f, 0.5f, 0.0f,
                0.5f, 0.7f, 0.3f,   0.0f, 0.9f, 0.1f,   0.3f, 0.6f, 0.3f,
                0.6f, 0.2f, 0.4f,   0.8f, 0.8f, 0.3f,   0.9f, 0.1f, 0.8f
            };

       
        
        
        //=====================================================================//
        // What we added in OpenGL-09.cpp...                                   //
        //=====================================================================//
        
        glEnable(GL_DEPTH_TEST);    // Enable depth test
        glDepthFunc(GL_LESS);       // Accept fragment if it is closer to the
                                    // camera than the former one

    
    
        //--- Step 1 ---------------------------------------------------------//
        // Define a handle for our "MVP" uniform and then we'll pass "MVP"    //
        //  to the vertex shader                                              //
        //--------------------------------------------------------------------//
        GLuint MatrixID = glGetUniformLocation(programShader.Program, "MVP");

    
    
    
        //--- Step 2 ---------------------------------------------------------//
        // Define a "Projection" matrix:                                      //
        //--------------------------------------------------------------------//
        glm::mat4 Projection = glm::perspective
                                    (
                                       45.0f,          // 45° Field of View
                                       4.0f / 3.0f,    // 4:3 Aspect ratio
                                       0.1f,           // Z-near - Near clipping plane
                                       100.0f          // Zfar - Far clipping plane
                                    );
    
//        OR... In world coordinates...
//        glm::mat4 Projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
//                  i.e.         glm::ortho(xLeft, xRight, yBottom, yTop, zNear, zFar)
  
    
    
        //--- Step 3 ---------------------------------------------------------//
        // Define the Camera OR View matrix:                                  //
        // Position the camera to set our VIEW perspective.                   //
        //--------------------------------------------------------------------//
        glm::mat4 View = glm::lookAt
                               (
                                   glm::vec3(0,3,-10), // Camera is at (0,3,-10), in World Space
                                   glm::vec3(0,0,0),  // and looking at the origin
                                   glm::vec3(0,1,0)   // Head is up (set to 0,-1,0 to look upside-down)
                               );
 
    
    
        //--- Step 4 ---------------------------------------------------------//
        // Define the Model matrix : an identity matrix:                      //
        //      (model will be at the origin)                                 //
        //--------------------------------------------------------------------//
        glm::mat4 Model = glm::mat4(1.0f);
    
    
    
        // --- Shifting Step 5 -----------------------------------------------//
        //   Our ModelViewProjection (or MVP) matrix will be constantly       //
        //   updated, so we'll declare it in the iteration a little later in  //
        //   the function as Step 7.                                          //
        //--------------------------------------------------------------------//

    
        
        //=====================================================================//
        // Define the buffers for the VERTICES and COLORS which will be needed //
        //=====================================================================//
        GLuint vertexbuffer;           // Buffer for vertices
        GLuint colorbuffer;            // Buffer for colors to match vertices
        
        
        //=====================================================================//
        // Generate the vertex and color buffers                               //
        //=====================================================================//
        glGenBuffers(1, &vertexbuffer);
        glGenBuffers(1, &colorbuffer);
        
        
        //=====================================================================//
        // Bind and load the data into the VERTEX buffer                       //
        //=====================================================================//
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
        
        
        //=====================================================================//
        // Bind and load the data into the COLOR buffer                        //
        //=====================================================================//
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColour), vertexColour, GL_STATIC_DRAW);
        
        
        
     
        while (!glfwWindowShouldClose(window))
            {
                // Clear the frame buffer
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                // Start using the shader which was defined previously
                glUseProgram(programShader.Program);
            
 
            
            
                //=====================================================================//
                // Adding some new stuff for the ANIMATION now...                      //
                //=====================================================================//
    
            
                //--- Step 5 ---------------------------------------------------------//
                // Updating the matrix for ROTATION                                   //
                //--------------------------------------------------------------------//
                angle += 0.025;
                if (angle > 360.0) angle = 0.01;
                
                glm::mat4 Rotation =  glm::rotate( glm::mat4(1), angle, vec3(1,0,0) );

            
            
                //--- Step 6 ---------------------------------------------------------//
                //  Updating the matrix for Translation                               //
                //--------------------------------------------------------------------//
                if (newX > 5 || newX < -5)
                    xInc *= -1;
            
                newX += xInc;
            
                glm::mat4 Translation  =  glm::translate( glm::mat4(1), vec3(newX,0,0) );
            
            
            
            
                //--- Step 7 (Previously Step 5 from OpenGL-09) ----------------------//
                //--------------------------------------------------------------------//
                // Now create the ModelViewProjection as the product of the 4 matrices//
                //--------------------------------------------------------------------//
                glm::mat4 MVP = Projection * View * Model * Rotation * Translation;
            
            
            
            
            
            
                // Set the **FIRST** attribute buffer : the vertices - 3 values
                glEnableVertexAttribArray(vertexPositionID);
                glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
                glVertexAttribPointer(
                                       vertexPositionID, // The attribute we want to configure
                                       3,                // size
                                       GL_FLOAT,         // type
                                       GL_FALSE,         // normalized?
                                       0,                // stride
                                       (void*)0          // array buffer offset
                                    );

            
            
                // Set the **SECOND** attribute buffer : colors - 3 values
                glEnableVertexAttribArray(vertexColorID);
                glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
                glVertexAttribPointer(
                                       vertexColorID,    // The attribute we want to configure
                                       3,                // size
                                       GL_FLOAT,         // type
                                       GL_FALSE,         // normalized?
                                       0,                // stride
                                       (void*)0          // array buffer offset
                                    );
                
            
            
            
                //--------------------------------------------------------------------//
                // Send our transformations to the currently bound shader,in the      //
                // "MVP" uniform                                                      //
                //--------------------------------------------------------------------//
                glUniformMatrix4fv(
                                    MatrixID,       // matrix location
                                    1,              // count
                                    GL_FALSE,       // transpose matrix?
                                    &MVP[0][0]      // starting value
                                   );


            
                //--------------------------------------------------------------------//
                // Draw the 12 triangles, each of 3 vertices:                         //
                //      12*3 indices starting at 0 -> 12 triangles                    //
                //--------------------------------------------------------------------//
                glDrawArrays(GL_TRIANGLES, 0, 12*3);

            
            
                // Release the buffer resources
                glDisableVertexAttribArray(vertexPositionID);
                glDisableVertexAttribArray(vertexColorID);

            

                // Swap the frame buffers
                glfwSwapBuffers(window);
                glfwPollEvents();

            } // End While...
        
        
        // Cleanup VBO and shader
        glDeleteBuffers(1, &vertexbuffer);
        glDeleteBuffers(1, &colorbuffer);
        glDeleteProgram(programShader.Program);

    }




int main(int argc, char* argv[])
    {
        
            // Initialize the required resources
        init_Resources();
        
        
        //==========================================================================//
        // At this stage... All systems are OK, poceed with window and view setup   //
        //==========================================================================//
        
            //Keep displaying the window until we have shut it down
        while (!glfwWindowShouldClose(window))
            {
                glClear(GL_COLOR_BUFFER_BIT);       // Flush the color buffer
            
                renderScene();                      // Create objects for the scene

            }
        
        
            //Close the display window
        glfwDestroyWindow(window);
        
            //Release ALL the other resources
        glfwTerminate();
        
            // Shut down the program gracefully
        exit(EXIT_SUCCESS);
    }




