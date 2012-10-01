#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H
class FpsCounter
{
private:
	int frameCount;
	float previousTime;
	

public:
	FpsCalc();
	void calculateFPS(unsigned int currentTime);
	char fps[5];
	~FpsCalc(){};
};
#endif