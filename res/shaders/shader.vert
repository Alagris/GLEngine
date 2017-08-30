#version 130

in vec3 position;

in vec4 color;
out vec4 colorV;
uniform mat4 MVP;

void main()
{

	colorV = color;
    gl_Position = MVP*vec4(position, 1.0);
}
