#include <GL/glew.h>
#include <GL/glut.h>
#include <glm\glm.hpp>
#include "Object.hpp"

#ifndef COSMICBODY_H
#define COSMICBODY_H
class CosmicBody: public Object
{
private:
	void CreateIndices();
	void CreateVertices();
	void CreateTextureCoords();
	void CreateNormals();

public:
	unsigned int verticesSize;
	unsigned int indicesSize;
	glm::vec3 position;

	GLuint VaoId;
	GLuint VboId;
	GLuint IndexBufferId;

	CosmicBody(int x)
	{
		this->verticesSize=0;
		this->VaoId=x;
		this->VboId=x;
		this->indicesSize=0;
	};
	~CosmicBody(){};

	void InitShape(unsigned int stacks, unsigned int slices, float size);
	void InitPosition(float x,float y,float z);
	void InitOrbit(float radiusX, float radiusY);
	void Draw();
};
#endif