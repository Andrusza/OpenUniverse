#include  <glm\glm.hpp>

#ifndef VERTEX_H
#define VERTEX_H
struct Vertex
{
	glm::vec3 xyz;
	glm::vec3 normals;
	float	u, v;
};
#endif