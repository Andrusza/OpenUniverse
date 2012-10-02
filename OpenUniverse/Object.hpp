#include <glm\glm.hpp>

#ifndef OBJECT_H
#define OBJECT_H
class Object
{

private:
	glm::mat4 ScaleMatrix;
	glm::mat4 RotationMatrix;
	glm::mat4 TranslationMatrix;
    void UpdateModelMatrix();

	const glm::mat4 identity;

public:
	Object(){};
	glm::mat4 ModelMatrix;

	void Scale(glm::vec3 v);
	void Rotate(float angle,glm::vec3 v);
	void Translate(glm::vec3 v);

};
#endif