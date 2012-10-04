#include "ObjectsMenager.hpp"
void ObjectsMenager::Init(unsigned int time)
{
	rng=boost::random::mt19937(static_cast<unsigned int>(time));
	basic.init("Shaders//MVP.vert","Shaders//basic.frag");
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

void ObjectsMenager::Draw(unsigned int time,glm::mat4 VP)
{
	unsigned int size=this->listofObjects.size();

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	basic.bind();
	for(int i=0;i<size;i++)
	{
		//listofObjects[i].Rotate(time,glm::vec3(0,1,0));
		glm::mat4 MVP=VP*listofObjects[i].ModelMatrix;
		basic.SetUniform("MVP",MVP);
		listofObjects[i].Draw();
	}
	basic.unbind();
	glDisable(GL_CULL_FACE);
}