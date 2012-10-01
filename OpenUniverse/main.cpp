#include <Windows.h>
#include "GL\glew.h"
#include "GL\freeglut.h"

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);

	glutCreateWindow("OpenUniverse");

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glutMainLoop();
}