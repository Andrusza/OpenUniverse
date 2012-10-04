
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
#include "CosmicBody.hpp"
#include "CreateWindow.hpp"
#include "Camera.h"
#include <boost\bind\bind.hpp>

glm::mat4 projectionMatrix;
FpsCounter fps;
ProgramClock clk;
FirstPerson firstPersonCamera;


void changeSize(int w, int h) 
{
	glViewport(0, 0, w, h);
	projectionMatrix = glm::perspective(45.0f, (float)w / (float)h, 0.1f, 9000.f);
}

void onMouse(int button, int state, int x, int y)
{
	firstPersonCamera.onMouse(button,state,x,y);
}

void onMotion(int x, int y)
{
	firstPersonCamera.onMotion(x,y);
}

void onWheel(int button, int dir, int x, int y)
{
	firstPersonCamera.onWheel(button,dir,x,y);
}

void processNormalKeys(unsigned char key, int x, int y) 
{
	firstPersonCamera.processNormalKeys(key,x,y);
}

void processUpNormalKeys(unsigned char key, int x, int y) 
{
	firstPersonCamera.processUpNormalKeys(key,x,y);	
}

void renderScene(void)
{
	clk.getElapsedTime();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	firstPersonCamera.Move();

	display(fps.fps,firstPersonCamera.stringSpeed);
	
	fps.calculateFPS(clk.elapsedTime);
	glutSwapBuffers();
}


void main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	CreateGlutWindow(800,600,"OpenUniverse");
	CheckOpenGLVersion();

	glutReshapeFunc(changeSize);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);

	firstPersonCamera=FirstPerson(0,0,1000);
	
	InitTextResources();
	glutMainLoop();
}