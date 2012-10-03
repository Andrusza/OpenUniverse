#include <glm\gtc\quaternion.hpp>

#ifndef FIRSTPERSON_H
#define FIRSTPERSON_H

class FirstPerson
{
private:
	
	bool keys[256];
	glm::quat orientation;
	bool mouse_pressed;
	float last_x;
	float last_y;

	float current_x;
	float current_y;

	glm::vec3 eye;
	glm::vec3 dir;

	glm::vec3 xAxis;
	glm::vec3 yAxis;
	glm::vec3 zAxis;
	glm::vec3 WORLDY;
	glm::vec3 WORLDX;

	int speed;

	static const int KEY_FORWARD;
	static const int KEY_BACK;
	static const int KEY_LEFT;
	static const int KEY_RIGHT;
	static const float MOUSE_SENSITIVE;

public:
	float x,y,z;
	char stringSpeed[5];
	glm::mat4x4 view;
	FirstPerson(){};

	FirstPerson(float x,float y,float z);
	
	void GetviewMatrix();
	void Move();
	void Move(glm::vec3);

	void onMouse(int button, int state, int x, int y);
	void onMotion(int x, int y);
	void onWheel(int button, int dir, int x, int y);
	void processNormalKeys(unsigned char key, int x, int y);
	void processUpNormalKeys(unsigned char key, int x, int y);

};
#endif