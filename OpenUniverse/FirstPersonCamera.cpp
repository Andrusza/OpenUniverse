#include <iostream>
#include "FirstPersonCamera.hpp"
#include "main.h"
#include <glm\gtx\quaternion.hpp>
#include "Camera.hpp"
#include <boost\bind\bind.hpp>

using namespace std;


const int FirstPerson::KEY_FORWARD=119;
const int FirstPerson::KEY_BACK=115;
const int FirstPerson::KEY_LEFT=97;
const int FirstPerson::KEY_RIGHT=100;
const float FirstPerson::MOUSE_SENSITIVE=0.1f;


void FirstPerson::Init(float x,float y,float z)
{
	this->mouse_pressed=false;
	this->WORLDX=glm::vec3(1,0,0);
	this->WORLDY=glm::vec3(0,1,0);
	this->dir=glm::vec3(0,0,1);
	this->speed=1;
	sprintf(this->stringSpeed,"%i",speed);

	(this->keys,false,sizeof(this->keys));
	this->Move(glm::vec3(x,y,z));

	SetEvents();
}

void FirstPerson::onMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouse_pressed=true;
		last_x=current_x=(float)x;
		last_y=current_y=(float)y;	
	}
	else
	{
		mouse_pressed=false;
	}
}

void FirstPerson::onMotion(int x, int y)
{
	if (mouse_pressed==true)
	{

		float pitch = -float(y-last_y);
		float yaw =  float(x-last_x);

		last_y=(float)y;
		last_x=(float)x;

		pitch*=MOUSE_SENSITIVE;
		yaw*=MOUSE_SENSITIVE;

		if(pitch !=0)
		{
			this->orientation= glm::angleAxis(-pitch, WORLDX)*this->orientation;
		}

		if(yaw !=0)
		{
			this->orientation= this->orientation*glm::angleAxis(yaw, WORLDY);
		}

		view=glm::mat4_cast(this->orientation);
		GetviewMatrix();

	}
}

void FirstPerson::onWheel(int button, int dir, int x, int y)
{
	if (dir > 0)
	{
		this->speed+=10;
		sprintf(stringSpeed,"%i",speed);
	}
	else
	{
		if(speed>30)
		{
			sprintf(stringSpeed,"%i",speed);
			this->speed-=10;

		}
	}
}

void FirstPerson::Move(glm::vec3 direction)
{
	eye+=xAxis*direction.x;
	eye+=WORLDY*direction.y;
	eye+=dir*direction.z;

	this->x=eye[0];
	this->y=eye[1];
	this->z=eye[2];

	GetviewMatrix();
}

void FirstPerson::GetviewMatrix()
{

	xAxis[0]=view[0][0];
	xAxis[1]=view[1][0];
	xAxis[2]=view[2][0];

	yAxis[0]=view[0][1];
	yAxis[1]=view[1][1];
	yAxis[2]=view[2][1];

	zAxis[0]=view[0][2];
	zAxis[1]=view[1][2];
	zAxis[2]=view[2][2];

	dir=-zAxis;

	view[3][0] =  - glm::dot(xAxis,eye);
	view[3][1] =  - glm::dot(yAxis,eye);
	view[3][2] =  - glm::dot(zAxis,eye);


}




void FirstPerson::processNormalKeys(unsigned char key, int x, int y) 
{
	keys[(int)key]=true;
}

void FirstPerson::processUpNormalKeys(unsigned char key, int x, int y) 
{
	keys[(int)key]=false;
}

void FirstPerson::Move()
{

	glm::vec3 direction(0,0,0);

	if(keys[KEY_FORWARD])
	{
		direction.z+=20*this->speed;
	}

	if(keys[KEY_BACK])
	{
		direction.z-=20*this->speed;
	}

	if(keys[KEY_LEFT])
	{
		direction.x-=20*this->speed;
	}

	if(keys[KEY_RIGHT])
	{
		direction.x+=20*this->speed;
	}

	Move(direction);

}

void FirstPerson::SetEvents()
{
	Camera::processNormalKeys(boost::bind(&FirstPerson::processNormalKeys,this,_1,_2,_3));
	Camera::processUpNormalKeys(boost::bind(&FirstPerson::processUpNormalKeys,this,_1,_2,_3));
	Camera::onMotion(boost::bind(&FirstPerson::onMotion,this,_1,_2));
	Camera::onMouse(boost::bind(&FirstPerson::onMouse,this,_1,_2,_3,_4));
	Camera::onWheel(boost::bind(&FirstPerson::onWheel,this,_1,_2,_3,_4));
	Camera::SetEvents();
}