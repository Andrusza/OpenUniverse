#include "Object.hpp"
#include <glm/gtc/matrix_transform.hpp>

void Object::Scale(glm::vec3 v)
{
	this->ScaleMatrix=glm::scale(identity,v);
	this->UpdateModelMatrix();
}

void Object::Rotate(float angle,glm::vec3 v)
{
	this->RotationMatrix=glm::rotate(identity,angle,v);
	this->UpdateModelMatrix();
}

void Object::Translate(glm::vec3 v)
{
	this->TranslationMatrix=glm::translate(identity,v);
	this->UpdateModelMatrix();
}

void Object::UpdateModelMatrix()
{
	this->ModelMatrix=this->TranslationMatrix*this->RotationMatrix*this->ScaleMatrix;
}