#include "StarMesh.h"
#include <glm\glm.hpp>
#include "define.hpp"

void StarMesh::CreateVertices()
{
	float tStep = (PI) / (float)this->slices;
	float sStep = (PI) / (float)this->stacks;

	this->verticesSize=(slices*2)*(stacks-1)+2;
	this->vertices=new Vertex[this->verticesSize];
    const float min=-PI/2.f+tStep;
	const float max= PI/2.f-tStep+0.001;

	int count=0;
	Vertex temp=Vertex();
	temp.xyz=glm::vec3(0.f,0.f,-this->size);
	temp.normals=glm::vec3(0,0,1);

	this->vertices[count++]=temp;


	for(float t = min ; t <= max ;t += tStep)
	{
		for(float s = -PI+0.001; s < PI; s += sStep)
		{
			Vertex temp=Vertex();
			temp.xyz=glm::vec3(this->size * cos(t) * cos(s),size * cos(t) * sin(s),size * sin(t));
			this->vertices[count++]=temp;
		}
	}
	temp=Vertex();
	temp.xyz=glm::vec3(0.f,0.f,size);
	temp.normals=glm::vec3(0,0,-1);

	this->vertices[count++]=temp;
}

void StarMesh::CreateIndices()
{
	this->indicesSize=(this->slices*2)*6*(this->stacks-1);
	this->indices=new unsigned int [indicesSize];

	int count=0;
	int i=1;

	for(int j=1;j<stacks-1;j++)
	{
		for(;i<this->verticesPerCircle*j;i++)
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

	for(int i=1;i<verticesPerCircle;i++)
	{
		indices[count++]=0;
		indices[count++]=i+1;
		indices[count++]=i;
		
	}
	indices[count++]=0;
	indices[count++]=1;
	indices[count++]=verticesPerCircle;
}

void StarMesh::CreateTextureCoords()
{
	for(int i=0;i<this->verticesSize;i++)
	{
		this->vertices[i].u=glm::asin(this->vertices[i].normals.z)/PI + 0.5f;
		this->vertices[i].v=glm::asin(this->vertices[i].normals.y)/PI + 0.5f;
	}
}

void StarMesh::CreateNormals()
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

void StarMesh::InitShape()
{
	
	CreateVertices();
	CreateIndices();
	CreateNormals();
	CreateTextureCoords();
}