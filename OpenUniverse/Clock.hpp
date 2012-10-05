#include <assert.h>
#ifndef PROGRAMCLOCK_H
#define PROGRAMCLOCK_H
class ProgramClock
{
public:
	unsigned int elapsedTime;
	ProgramClock();
	void getElapsedTime();
	unsigned int CurrentTime();
	static ProgramClock& get()
	{
		static ProgramClock* gpSingleton = 0;
		if (gpSingleton == 0)
		{
			gpSingleton = new ProgramClock;
		}
		assert(gpSingleton);
		return *gpSingleton;
	}
};
#endif