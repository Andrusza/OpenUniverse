#ifndef PROGRAMCLOCK_H
#define PROGRAMCLOCK_H
class ProgramClock
{
public:
	unsigned int elapsedTime;
	ProgramClock();
	void getElapsedTime();
	unsigned int CurrentTime();
};
#endif