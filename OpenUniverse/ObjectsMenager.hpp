#include "CosmicBody.hpp"
#include <vector>
#include  <boost/random/mersenne_twister.hpp>
#include  <boost/random/uniform_int_distribution.hpp>

#ifndef OBJECTMENAGER_H
#define OBJECTMENAGER_H
class ObjectsMenager
{
private:
	std::vector<CosmicBody> listofObjects;
	boost::random::mt19937 rng;

public:
	ObjectsMenager(unsigned int time);
	void CreateObject(unsigned int minSize,unsigned int maxSize,int minPosition,int maxPosition,unsigned int RingsAndSlices);
	void CreateGivenObject(unsigned int size,int x,int y,int z,unsigned int RingsAndSlices);
	void DelateObject();
	void Draw();
};
#endif