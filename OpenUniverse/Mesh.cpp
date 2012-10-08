#include "Mesh.h"

void Mesh::Bind()
{
	glGenVertexArrays(2, &VaoId[0]);
	glBindVertexArray(VaoId[0]);

	glGenBuffers(2, &VboId[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VboId[0]);
	glBufferData(GL_ARRAY_BUFFER, 32*verticesSize, this->vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 32, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 32, (void*)12);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 32, (void*)24);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glGenBuffers(1, &IndexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indicesSize*4, this->indices, GL_STATIC_DRAW);

	delete[] this->vertices;
	delete[] this->indices;
}

void Mesh::Draw()
{
glBindVertexArray(this->VaoId[0]);
	//glDrawElements(GL_TRIANGLES, this->indicesSize, GL_UNSIGNED_INT, NULL);
	glDrawElementsInstanced(GL_TRIANGLES, this->indicesSize, GL_UNSIGNED_INT, NULL,1000);
glBindVertexArray(0);
}