#include <GL/glew.h>
#include "Object.hpp"
#include "define.hpp"
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

void Object::SetModelMatrix(glm::vec3 t,glm::mat4 rotationMatrix,glm::vec3 s)
{
	this->TranslationMatrix=glm::translate(identity,t);
	this->RotationMatrix=rotationMatrix;
	this->ScaleMatrix=glm::scale(identity,s);
	this->UpdateModelMatrix();
}

