
#include "main.h"
#include <Windows.h>
#include "CheckOpenGL.hpp"
#include <glm\gtc\matrix_transform.hpp>
#include  "FirstPersonCamera.hpp"
#include  "TextRender.hpp"
#include  "ShaderMenager.hpp"
#include  "Clock.hpp"
#include  "FpsCounter.hpp"

glm::mat4 projectionMatrix;
FpsCounter fps;
ProgramClock clk;

void changeSize(int w, int h) 
{
	glViewport(0, 0, w, h);
	projectionMatrix = glm::perspective(45.0f, (float)w / (float)h, 0.1f, 9000.f);
}

void renderScene(void)
{
	clk.getElapsedTime();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	display("1","2");
	
	fps.calculateFPS(clk.elapsedTime);
	glutSwapBuffers();
}


void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);

	glutCreateWindow("OpenUniverse");
	CheckOpenGLVersion();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glutReshapeFunc(changeSize);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);


	init_resources();
	glutMainLoop();
}