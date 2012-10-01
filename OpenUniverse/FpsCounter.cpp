#include "FpsCounter.hpp"
#include <iostream>

FpsCounter::FpsCounter()
{
	frameCount=0;
	previousTime=0;
}

void FpsCounter::calculateFPS(unsigned int currentTime)
{

	frameCount++;
	unsigned int timeInterval = currentTime - previousTime;

	if(timeInterval > 1000)
	{
		float fps = frameCount / (timeInterval / 1000.0f);
		previousTime = currentTime;
		frameCount = 0;
		sprintf(this->fps,"%.2f",fps); 
	}
}