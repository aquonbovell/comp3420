#version 120

// The "shared" variable from the vertex shader which contains the vertex color
varying vec3 fragmentColor;

void main()
	{
		// Give the pixel(s) the fragment color from the vertex
		gl_FragColor = vec4(fragmentColor, 1);
	}
