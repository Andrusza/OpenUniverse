#version 400

layout(location=0) in vec4 in_Position;
out vec4 ex_Color;

uniform mat4 MVP;

void main(void)
{
	gl_Position = MVP * in_Position;
	ex_Color = vec4(normalize(in_Position));
}