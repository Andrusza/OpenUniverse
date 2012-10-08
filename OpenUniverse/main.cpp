
#include "main.h"
#include <Windows.h>
#include "CheckOpenGL.hpp"
#include <glm\gtc\matrix_transform.hpp>
#include "RenderManager.h"
#include "ObjectsMenager.hpp"
#include "Clock.hpp"

RenderManager gRenderManager;
ProgramClock clk;

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	
	gRenderManager.StartUp();

	glutMainLoop();

	gRenderManager.ShutDown();
}