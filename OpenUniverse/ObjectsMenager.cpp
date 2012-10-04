#include "ObjectsMenager.hpp"
ObjectsMenager::ObjectsMenager(unsigned int time)
{
	rng=boost::random::mt19937(static_cast<unsigned int>(time));
}

void ObjectsMenager::CreateObject(unsigned int minSize,unsigned int maxSize,int minPosition,int maxPosition,unsigned int RingsAndSlices)
{
	boost::random::uniform_int_distribution<> randomSize(minSize,maxSize);
	boost::random::uniform_int_distribution<> randomPosition(minPosition,maxPosition);
	float s = randomSize(rng);
	float x = randomPosition(rng);
	float y = randomPosition(rng);
	float z = randomPosition(rng);

	CosmicBody temp;
	temp.InitShape(RingsAndSlices,RingsAndSlices,s);
	temp.InitPosition(x,y,z);
	this->listofObjects.push_back(temp);
}

void ObjectsMenager::CreateGivenObject(unsigned int size,int x,int y,int z,unsigned int RingsAndSlices)
{
	CosmicBody temp;
	temp.InitShape(RingsAndSlices,RingsAndSlices,size);
	temp.InitPosition(x,y,z);
	this->listofObjects.push_back(temp);
}
