#version 400

layout(location=0) in vec4 in_Position;
layout(location=3) in mat4 ModelMatrix;
out vec4 ex_Color;

uniform mat4 VP;
void main(void)
{
	gl_Position = (VP * ModelMatrix) * in_Position;
	ex_Color = vec4(normalize(in_Position));
}