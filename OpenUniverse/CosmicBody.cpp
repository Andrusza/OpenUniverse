#include  <glm\gtc\type_ptr.hpp>
#include "CosmicBody.hpp"
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "define.hpp"

using namespace std;
void CosmicBody::CreateVertices(unsigned int stacks, unsigned int slices, float size)
{
	float tStep = (PI) / (float)slices;
	float sStep = (PI) / (float)stacks;

	this->vertices=new Vertex[this->verticesSize];
    const float min=-PI/2.f+tStep;
	const float max= PI/2.f-tStep+0.001;

	int count=0;

	Vertex temp=Vertex();
	temp.xyz=glm::vec3(0.f,0.f,-size);
	temp.normals=glm::vec3(0,0,1);

	this->vertices[count++]=temp;


	for(float t = min ; t <= max ;t += tStep)
	{
		for(float s = -PI+0.001; s < PI; s += sStep)
		{
			Vertex temp=Vertex();
			temp.xyz=glm::vec3(size * cos(t) * cos(s),size * cos(t) * sin(s),size * sin(t));
			this->vertices[count++]=temp;
		}
	}
	temp=Vertex();
	temp.xyz=glm::vec3(0.f,0.f,size);
	temp.normals=glm::vec3(0,0,-1);

	this->vertices[count++]=temp;
}

void CosmicBody::CreateIndices(unsigned int stacks, unsigned int slices)
{
	this->indicesSize=(slices*2)*6*(stacks-1);
	this->indices=new unsigned int [indicesSize];

	int count=0;
	int i=1;

	for(int j=1;j<stacks-1;j++)
	{
		for(;i<verticesPerCircle*j;i++)
		{
			indices[count++]=i;
			indices[count++]=i+ verticesPerCircle+1;
			indices[count++]=i+ verticesPerCircle;

			indices[count++]=i;
			indices[count++]=i + 1;
			indices[count++]=i + verticesPerCircle + 1;
		}

		indices[count++]=i;
		indices[count++]=i + 1;
		indices[count++]=i + verticesPerCircle;

		indices[count++]= i;
		indices[count++]= i - (verticesPerCircle - 1);
		indices[count++]=(i - (verticesPerCircle - 1))+verticesPerCircle;

		i++;
	}
	
	for(;i<verticesSize-2;i++)
	{
		indices[count++]=i;
		indices[count++]=i+1;
		indices[count++]=verticesSize-1;	
	}

	indices[count++]=i;
	indices[count++]=i -  verticesPerCircle +1;
	indices[count++]=verticesSize - 1;
}

void CosmicBody::CreateTextureCoords()
{
	for(int i=0;i<this->verticesSize;i++)
	{
		this->vertices[i].u=glm::asin(this->vertices[i].normals.z)/PI + 0.5f;
		this->vertices[i].v=glm::asin(this->vertices[i].normals.y)/PI + 0.5f;
	}
}

void CosmicBody::CreateNormals()
{
	
	int i=1;
	{
		glm::vec3 sum;

		glm::vec3 v0=vertices[0].xyz-vertices[i].xyz;

		glm::vec3 v_minus= vertices[verticesPerCircle].xyz - vertices[i].xyz;
		glm::vec3 v_plus = vertices[i + 1].xyz - vertices[i].xyz;
		glm::vec3 v_next = vertices[i + verticesPerCircle].xyz - vertices[i].xyz;

		sum= sum + glm::normalize(glm::cross(v_minus,v0));
		sum= sum + glm::normalize(glm::cross(v_plus,v0));

		sum= sum + glm::normalize(glm::cross(v_next,v_minus));
		sum= sum + glm::normalize(glm::cross(v_next,v_plus));
		vertices[i].normals=glm::normalize(sum);
		
		i++;

		for(;i<verticesPerCircle;i++)
		{
			glm::vec3 sum;

			glm::vec3 v0=vertices[0].xyz-vertices[i].xyz;

			glm::vec3 v_minus= vertices[i-1].xyz - vertices[i].xyz;
			glm::vec3 v_plus = vertices[i+1].xyz - vertices[i].xyz;
			glm::vec3 v_next = vertices[i+verticesPerCircle].xyz - vertices[i].xyz;

			sum=sum + glm::normalize(glm::cross(v_minus,v0));
			sum=sum + glm::normalize(glm::cross(v_plus,v0));

			sum=sum + glm::normalize(glm::cross(v_next,v_minus));
			sum=sum + glm::normalize(glm::cross(v_next,v_plus));
			vertices[i].normals=glm::normalize(sum);
		}

		sum=glm::vec3(0,0,0);

		v0=vertices[0].xyz-vertices[i].xyz;

		v_minus=vertices[i - 1].xyz-vertices[i].xyz;
		v_plus= vertices[1].xyz - vertices[i].xyz;
		v_next= vertices[i + verticesPerCircle].xyz - vertices[i].xyz;

		sum=sum+ glm::normalize(glm::cross(v_minus,v0));
		sum=sum+ glm::normalize(glm::cross(v_plus,v0));

		sum= sum+ glm::normalize(glm::cross(v_next,v_minus));
		sum= sum+ glm::normalize(glm::cross(v_next,v_plus));
		vertices[i].normals=glm::normalize(sum);
		
		i++;
	}

	{
		for(;i<verticesSize-verticesPerCircle-1;i++)
		{
			glm::vec3 sum;

			glm::vec3 v_previous=vertices[i - verticesPerCircle].xyz - vertices[i].xyz;
			glm::vec3 v_minus=vertices[i - 1].xyz-vertices[i].xyz;
			glm::vec3 v_plus=vertices[i + 1].xyz-vertices[i].xyz;
			glm::vec3 v_next=vertices[i + verticesPerCircle].xyz - vertices[i].xyz;

			sum=sum+ glm::normalize(glm::cross(v_minus,v_previous));
			sum=sum+ glm::normalize(glm::cross(v_plus,v_previous));

			sum=sum+ glm::normalize(glm::cross(v_next,v_minus));
			sum=sum+ glm::normalize(glm::cross(v_next,v_plus));

			vertices[i].normals=glm::normalize(sum);
			
		}
	}

	for(int j=verticesSize-2;j>=i;j--)
	{
		vertices[j].normals=-vertices[j - i + 1].normals;	
	}
}

void CosmicBody::InitShape(unsigned int stacks, unsigned int slices, float size)
{
	this->verticesPerCircle=slices*2;
	CreateVertices(stacks,slices,size);
	CreateIndices(stacks,slices);
	CreateNormals();
	CreateTextureCoords();
	
	glGenVertexArrays(1, &VaoId);
	glBindVertexArray(VaoId);
	
	glGenBuffers(1, &VboId);
	glBindBuffer(GL_ARRAY_BUFFER, VboId);
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
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferId);

	delete[] this->vertices;
	delete[] this->indices;
}

void CosmicBody::InitPosition(float x,float y,float z)
{
	this->position=glm::vec3(x,y,z);
	Translate(this->position);
}