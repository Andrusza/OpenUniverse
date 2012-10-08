#include "Vertex.hpp"
#include <GL\freeglut.h>

#ifndef OBJECT_H
#define OBJECT_H
class Object
{

private:
	glm::mat4 ScaleMatrix;
	glm::mat4 RotationMatrix;
	glm::mat4 TranslationMatrix;

	void UpdateModelMatrix();
	
public:
	glm::mat4 ModelMatrix;

	Object(){};
	~Object(){};

	void Scale(glm::vec3 v);
	void Rotate(float angle,glm::vec3 v);
	void Translate(glm::vec3 v);

	void SetModelMatrix(glm::vec3 transalte,glm::mat4 rotationMatrix,glm::vec3 scale);
};
#endif