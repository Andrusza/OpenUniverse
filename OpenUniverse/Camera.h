#include <boost/function.hpp>

#ifndef CAMERA_H
#define CAMERA_H
namespace Camera 
{
    void processNormalKeys(boost::function<void(unsigned char, int, int)>);
	void processUpNormalKeys(boost::function<void(unsigned char, int, int)>);
    void onMouse(boost::function<void(int,int,int,int)>);
	void onMotion(boost::function<void(int,int)>);
	void onWheel(boost::function<void(int,int,int,int)>);
};
#endif 