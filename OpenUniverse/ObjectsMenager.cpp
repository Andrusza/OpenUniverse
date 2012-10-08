#include "ObjectsMenager.hpp"
#include <vector>
#include <glm/gtx/euler_angles.hpp>

void ObjectsMenager::Init(unsigned int time)
{
	rng=boost::random::mt19937(static_cast<unsigned int>(time));
	basic.init("Shaders//MVP.vert","Shaders//basic.frag");
	base.InitShape();
	base.Bind();
}
void ObjectsMenager::Add(Object &temp)
{
	this->listofObjects.push_back(temp);
	this->listofMatrices.push_back(temp.ModelMatrix);
}

void ObjectsMenager::CreateRandomModelMatrix(unsigned int minSize,unsigned int maxSize,int minPosition,int maxPosition,Object &obj)
{
	boost::random::uniform_int_distribution<> randomSize(minSize,maxSize);
	boost::random::uniform_int_distribution<> randomPosition(minPosition,maxPosition);
	boost::random::uniform_int_distribution<> randomRotation(-360,360);
	float s = randomSize(rng);
	glm::vec3 scale(s,s,s);

	float x = randomPosition(rng);
	float y = randomPosition(rng);
	float z = randomPosition(rng);
	glm::vec3 position(x,y,z);

	float rotateX=randomRotation(rng);
	float rotateY=randomRotation(rng);
	float rotateZ=randomRotation(rng);
	glm::mat4 rotationMatrix=glm::eulerAngleYXZ(rotateY,rotateX,rotateZ);

	obj.SetModelMatrix(position,rotationMatrix,scale);
}

void ObjectsMenager::CreateInstancedArray(Mesh &base,std::vector<glm::mat4> matrices)
{
	int pos = 3;
	glBindVertexArray(base.VaoId[0]);
	glBindBuffer(GL_ARRAY_BUFFER, base.VboId[1]);
	int size=matrices.size();

	glBufferData(GL_ARRAY_BUFFER, 64*size, &matrices[0], GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(pos);
	glEnableVertexAttribArray(pos+1);
	glEnableVertexAttribArray(pos+2);
	glEnableVertexAttribArray(pos+3);

	glVertexAttribPointer(pos, 4, GL_FLOAT, GL_FALSE, 64, (void*)0);
	glVertexAttribPointer(pos+1, 4, GL_FLOAT, GL_FALSE, 64, (void*)16);
	glVertexAttribPointer(pos+2, 4, GL_FLOAT, GL_FALSE, 64, (void*)32);
	glVertexAttribPointer(pos+3, 4, GL_FLOAT, GL_FALSE, 64, (void*)48);

	glVertexAttribDivisor(pos, 1);
	glVertexAttribDivisor(pos+1, 1);
	glVertexAttribDivisor(pos+2, 1);
	glVertexAttribDivisor(pos+3, 1);

}

void ObjectsMenager::Draw(unsigned int time,glm::mat4 VP)
{
	//unsigned int size=this->listofObjects.size();
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	basic.bind();
	
		//listofObjects[i].Rotate(time*0.01,glm::vec3(0,1,0));
		//glm::mat4 MVP=VP;
		basic.SetUniform("VP",VP);
		base.Draw();
	
	basic.unbind();
	glDisable(GL_CULL_FACE);
}