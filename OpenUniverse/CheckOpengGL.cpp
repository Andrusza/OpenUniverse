#include "CheckOpenGL.hpp"
#include "main.h"

void CheckOpenGLVersion()
{
	GLenum err = glewInit();
	if( GLEW_OK != err )
	{
		fprintf(stderr, "Error initializing GLEW: %s\n",
			glewGetErrorString(err) );
	}
	else
	{
		std::cout<<"GLEW OK"<<std::endl;
	}

	const GLubyte *renderer = glGetString( GL_RENDERER );
	const GLubyte *vendor = glGetString( GL_VENDOR );
	const GLubyte *version = glGetString( GL_VERSION );
	const GLubyte *glslVersion =
		glGetString( GL_SHADING_LANGUAGE_VERSION );
	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);
	printf("GL Vendor : %s\n", vendor);
	printf("GL Renderer : %s\n", renderer);
	printf("GL Version (string) : %s\n", version);
	printf("GL Version (integer) : %d.%d\n", major, minor);
	printf("GLSL Version : %s\n", glslVersion);

	if(GL_ARB_vertex_buffer_object)
	{
		std::cout<<"VBO supported"<<std::endl;
	}
	else std::cout<<"VBO not supported";
}