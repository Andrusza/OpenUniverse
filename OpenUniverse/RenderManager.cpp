#include "RenderManager.h"
#include "Render.h"
#include <boost\bind.hpp>
#include <GL\freeglut.h>
#include "TextRender.hpp"
#include "CreateWindow.hpp"
#include "CheckOpenGL.hpp"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

void RenderManager::ChangeSize(int w, int h) 
{
	glViewport(0, 0, w, h);
	projectionMatrix = glm::perspective(45.0f, (float)w / (float)h, 0.1f, 9000.f);
}

void RenderManager::Render()
{
	clk_instance.getElapsedTime();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	firstPersonCamera.Move();

	glm::mat4 VP=projectionMatrix*firstPersonCamera.view;
	objects.Draw(clk_instance.elapsedTime,VP);

	display(fps.fps,firstPersonCamera.stringSpeed);

	fps.calculateFPS(clk_instance.elapsedTime);
	glutSwapBuffers();
}


void RenderManager::StartUp()
{
	CreateGlutWindow(800,600,"OpenUniverse");
	CheckOpenGLVersion();

	firstPersonCamera.Init(0,0,1000);
	clk_instance=ProgramClock::get();

	objects.Init(clk_instance.CurrentTime());
	for(int i=0;i<1000;i++)
	{
		objects.CreateObject(1,100,-1000,1000,50);
	}

	InitTextResources();

	//glutFullScreen();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	Render::ChangeSize(boost::bind(&RenderManager::ChangeSize,this,_1,_2));
	Render::Render(boost::bind(&RenderManager::Render,this));
	Render::SetEvents();

}

void RenderManager::ShutDown()
{

}