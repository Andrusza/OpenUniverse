#include "main.h"

glm::mat4 projectionMatrix;
void changeSize(int w, int h) 
{
	glViewport(0, 0, w, h);
	projectionMatrix = glm::perspective(45.0f, (float)w / (float)h, 0.1f, 9000.f);
}


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