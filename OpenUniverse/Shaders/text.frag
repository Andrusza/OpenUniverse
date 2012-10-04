#version 400
in vec2 texpos;
out vec4 out_Color;

uniform sampler2D tex;
uniform vec4 color;

void main(void) 
{
	out_Color = vec4(1, 1, 1, texture2D(tex, texpos).a) * color;
}
