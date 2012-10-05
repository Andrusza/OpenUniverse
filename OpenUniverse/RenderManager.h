#include <assert.h>
#include "FirstPersonCamera.hpp"
#include "Clock.hpp"
#include "FpsCounter.hpp"
#include "ObjectsMenager.hpp"
#include <glm\glm.hpp>

#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H
class RenderManager
{

private:
	glm::mat4 projectionMatrix;

	FpsCounter fps;
	ProgramClock clk_instance;

	FirstPerson firstPersonCamera;
	ObjectsMenager objects;

	void ChangeSize(int w, int h);
	void Render(void);


public:
	RenderManager(){};
	~RenderManager(){};
	void StartUp();
	void ShutDown();
	static RenderManager& get()
	{
		static RenderManager* gpSingleton = 0;
		if (gpSingleton == 0)
		{
			gpSingleton = new RenderManager;
		}
		assert(gpSingleton);
		return *gpSingleton;
	}
};
#endif