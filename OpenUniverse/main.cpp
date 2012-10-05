
#include "main.h"
#include <Windows.h>
#include "CheckOpenGL.hpp"
#include <glm\gtc\matrix_transform.hpp>
#include  "FirstPersonCamera.hpp"
#include "RenderManager.h"

RenderManager gRenderManager;
ProgramClock clk;

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	
	gRenderManager.StartUp();

	glutMainLoop();

	gRenderManager.ShutDown();
}