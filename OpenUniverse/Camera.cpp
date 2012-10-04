#include "Camera.h"
#include <GL\freeglut.h>
namespace Camera
{
	
		boost::function<void(unsigned char, int, int)> onProcessNormalKeysCB = 0;
		boost::function<void(int,int)> onMotionCB=0;
		boost::function<void(int,int,int,int)> onMouseCB=0;
		boost::function<void(int,int,int,int)> onWheelCB=0;
		boost::function<void(unsigned char, int, int)> onProcessUpNormalKeysCB = 0;
		
		void processNormalKeys(boost::function<void(unsigned char, int, int)> cb)
		{
			onProcessNormalKeysCB = cb;
		}

		void NormalKeyDown(unsigned char key, int x, int y)
		{
			onProcessNormalKeysCB(key,x,y);
		}

		void MouseMotion(int x,int y)
		{
			onMotionCB(x,y);
		}

		void onMotion(boost::function<void(int,int)> cb)
		{
			onMotionCB = cb;
		}

		void onMouse(boost::function<void(int,int,int,int)> cb)
		{
			onMouseCB = cb;
		}

		void MouseClick(int button,int state,int x,int y)
		{
			onMouseCB(button,state,x,y);
		}

		void processUpNormalKeys(boost::function<void(unsigned char, int, int)> cb)
		{
			onProcessUpNormalKeysCB = cb;
		}

		void NormalKeyUp(unsigned char key, int x, int y)
		{
			onProcessUpNormalKeysCB(key,x,y);
		}

		void onWheel(boost::function<void(int,int,int,int)> cb)
		{
			onWheelCB = cb;
		}

		void WheelMove(int button,int dir, int x, int y)
		{
			onWheelCB(button,dir,x,y);
		}

		void SetEvents()
		{
			glutKeyboardFunc(NormalKeyDown);
			glutKeyboardUpFunc(NormalKeyUp);

			glutMotionFunc(MouseMotion);
			glutMouseFunc(MouseClick);
			glutMouseWheelFunc(WheelMove);
		}

	


}
