#version 120

// Interpolated values from the vertex shaders
varying vec3 fragmentColor;

void main()
{
    // Give the pixel(s) the fragment color from the vertex
    gl_FragColor = vec4(fragmentColor, 1);
}
