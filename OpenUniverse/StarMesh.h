#include "Mesh.h"

#ifndef STARMESH_H
#define STARMESH_H
class StarMesh: public Mesh
{
private:
	void CreateIndices();
	void CreateVertices();
	void CreateTextureCoords();
	void CreateNormals();

public:
	int stacks;
	int slices;
	int size;
	int verticesPerCircle;

	StarMesh()
	{
		this->stacks=100;
		this->slices=100;
		this->size=1;
		this->verticesPerCircle=this->slices*2;
	}
	void InitShape();
};
#endif