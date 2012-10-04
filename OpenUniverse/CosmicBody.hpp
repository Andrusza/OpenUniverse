#include <GL/glew.h>
#include <GL/glut.h>
#include <glm\glm.hpp>
#include "Object.hpp"
#include "Vertex.hpp"

#ifndef COSMICBODY_H
#define COSMICBODY_H
class CosmicBody: public Object
{
private:
	void CreateIndices(unsigned int stacks, unsigned int slices);
	void CreateVertices(unsigned int stacks, unsigned int slices, float size);
	void CreateTextureCoords();
	void CreateNormals();
	unsigned int verticesPerCircle;
	Vertex *vertices;
	unsigned int *indices;

public:
	unsigned int verticesSize;
	unsigned int indicesSize;
	glm::vec3 position;

	GLuint VaoId;
	GLuint VboId;
	GLuint IndexBufferId;

	CosmicBody()
	{
		this->verticesSize=0;
		//this->VaoId=x;
		//this->VboId=x;
		this->indicesSize=0;
	};
	~CosmicBody(){};

	void InitShape(unsigned int stacks, unsigned int slices, float size);
	void InitPosition(float x,float y,float z);
	void InitOrbit(float radiusX, float radiusY);
	void Draw();
};
#endif