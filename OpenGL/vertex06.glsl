#version 120

// Input vertex data, different for all executions of this shader.
// i.e. Every vertex will come in with it's own position and it's own colour
attribute vec3 vertexPosition;
attribute vec3 vertexColor;


// The color of the vertex will be "shared" with the fragment shader
varying vec3 fragmentColor;

void main()
	{
		// Output position of the vertex
		gl_Position =  vec4(vertexPosition, 1);
		
		// Copy the vertex color to be passed to the fragment shader via fragmentColor
		fragmentColor = vertexColor;
	}
