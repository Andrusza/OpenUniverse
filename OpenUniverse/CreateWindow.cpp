#include "CreateWindow.hpp"
#include <GL\freeglut.h>

void CreateGlutWindow(int height,int width,const char* name)
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(height,width);

	glutCreateWindow(name);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}