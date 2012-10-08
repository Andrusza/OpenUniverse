#include <GL/glew.h>
#include <GL\freeglut.h>
#include "Vertex.hpp"

#ifndef MESH_H
#define MESH_H
class Mesh
{
public:
	Mesh(){}
	void Draw();
	void Bind();

	GLuint VaoId[2];
	GLuint VboId[2];

private:
	GLuint IndexBufferId;

	virtual void CreateIndices(){};
	virtual void CreateVertices(){};
	virtual void CreateTextureCoords(){};
	virtual void CreateNormals(){};

protected:
	unsigned int verticesSize;
	unsigned int indicesSize;

	Vertex *vertices;
	unsigned int *indices;

};
#endif