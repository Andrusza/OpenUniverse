#include "Clock.hpp"
#include <GL\freeglut.h>
#include <ctime>

ProgramClock::ProgramClock(){};

void ProgramClock::getElapsedTime()
{
	this->elapsedTime= glutGet(GLUT_ELAPSED_TIME);
}

unsigned int ProgramClock::CurrentTime()
{
	unsigned int x=(unsigned int)time(0);
	return x;
}