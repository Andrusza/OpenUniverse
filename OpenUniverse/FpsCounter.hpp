#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H
class FpsCounter
{
private:
	int frameCount;
	unsigned int previousTime;
	

public:
	FpsCounter();
	void calculateFPS(unsigned int currentTime);
	char fps[5];
	~FpsCounter(){};
};
#endif