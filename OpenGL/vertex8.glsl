#version 120

// Input vertex data, different for all executions of this shader.
attribute vec3 vertexPosition;
attribute vec3 vertexColor;

// Output data to be shared with the fragment shader.
varying vec3 fragmentColor;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

void main()
{

	// Output position of the vertex, in clip space : i.e. MVP * position
	gl_Position =  MVP * vec4(vertexPosition, 1);

    // Copy the vertex color to be passed to the fragment shader via fragmentColor
	fragmentColor = vertexColor;
}

