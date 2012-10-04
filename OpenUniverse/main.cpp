
#include "main.h"
#include <Windows.h>
#include "CheckOpenGL.hpp"
#include <glm\gtc\matrix_transform.hpp>
#include  "FirstPersonCamera.hpp"
#include  "TextRender.hpp"
#include  "ShaderMenager.hpp"
#include  "Clock.hpp"
#include  "FpsCounter.hpp"
#include "FirstPersonCamera.hpp"
#include "CreateWindow.hpp"
#include "Camera.hpp"
#include <boost\bind\bind.hpp>
#include "ObjectsMenager.hpp"

glm::mat4 projectionMatrix;
FpsCounter fps;
ProgramClock clk;
FirstPerson firstPersonCamera;
ObjectsMenager objects;


void changeSize(int w, int h) 
{
	glViewport(0, 0, w, h);
	projectionMatrix = glm::perspective(45.0f, (float)w / (float)h, 0.1f, 9000.f);
}

void renderScene(void)
{
	clk.getElapsedTime();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	firstPersonCamera.Move();

	glm::mat4 VP=projectionMatrix*firstPersonCamera.view;
	objects.Draw(clk.elapsedTime,VP);

	display(fps.fps,firstPersonCamera.stringSpeed);

	fps.calculateFPS(clk.elapsedTime);
	glutSwapBuffers();
}


void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	CreateGlutWindow(800,600,"OpenUniverse");
	CheckOpenGLVersion();
	firstPersonCamera.Init(0,0,100);



	glutReshapeFunc(changeSize);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);

	objects.Init(clk.CurrentTime());
	for(int i=0;i<500;i++)
	{
		objects.CreateObject(1,30,-1000,1000,50);
	}

	InitTextResources();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glutMainLoop();
}