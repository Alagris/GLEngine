#version 330

layout(location=0) in vec3 position;
layout(location=1) in vec4 color;

out vec4 colorV;
uniform mat4 MVP;

void main()
{
//	colorV = color;
    colorV=vec4(1.0,0.0,1.0,1.0);
    gl_Position = MVP*vec4(position, 1.0);
}
