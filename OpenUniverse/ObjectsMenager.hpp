#include <vector>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include "ShaderMenager.hpp"
#include "Object.hpp"
#include "StarMesh.h"
#include "Clock.hpp"

#ifndef OBJECTMENAGER_H
#define OBJECTMENAGER_H
class ObjectsMenager
{
private:
	boost::random::mt19937 rng;
	Shader basic;
	std::vector<Object> listofObjects;
	ProgramClock clk_instance;
	

public:

	std::vector<glm::mat4> listofMatrices;
	StarMesh base;

	enum objectsTypes{STAR,PLANET,ASTEROID,NEBULA,STAR_CLUSTER,GALAXY};
	ObjectsMenager(){};

	void Add(Object &obj);

	void Init(unsigned int time);
	void Draw(unsigned int time,glm::mat4 VP);
	void CreateRandomModelMatrix(unsigned int minSize,unsigned int maxSize,int minPosition,int maxPosition,Object &obj);
	void CreateInstancedArray(Mesh &base,std::vector<glm::mat4> matrices);

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