#include "CosmicBody.hpp"
#include <vector>
#include  <boost/random/mersenne_twister.hpp>
#include  <boost/random/uniform_int_distribution.hpp>
#include "ShaderMenager.hpp"

#ifndef OBJECTMENAGER_H
#define OBJECTMENAGER_H
class ObjectsMenager
{
private:
	std::vector<CosmicBody> listofObjects;
	boost::random::mt19937 rng;
	Shader basic;

public:
	ObjectsMenager(){};
	void Init(unsigned int time);
	void CreateRandomObjects(unsigned int quantity,CosmicBody &base);
	void CreateObject(unsigned int minSize,unsigned int maxSize,int minPosition,int maxPosition,unsigned int RingsAndSlices);
	void CreateGivenObject(unsigned int size,int x,int y,int z,unsigned int RingsAndSlices);
	void DelateObject();
	void Draw(unsigned int time,glm::mat4 VP);
	static ObjectsMenager& get()
	{
		static ObjectsMenager* gpSingleton = 0;
		if (gpSingleton == 0)
		{
			gpSingleton = new ObjectsMenager;
		}
		assert(gpSingleton);
		return *gpSingleton;
	}
};
#endif