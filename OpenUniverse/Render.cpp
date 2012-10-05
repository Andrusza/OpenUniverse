#include "Render.h"
#include <GL\freeglut.h>
namespace Render
{
	boost::function<void(int,int)> ChangeSizeCB=0;
	boost::function<void()> RenderCB=0;

	void Render(boost::function<void()> cb)
	{
		RenderCB=cb;
	}

	void Render()
	{
		RenderCB();
	}

	void ChangeSize(boost::function<void(int,int)> cb)
	{
		ChangeSizeCB=cb;
	}

	void ChangeSize(int h,int w)
	{
		ChangeSizeCB(h,w);
	}

    void SetEvents()
	{
		glutReshapeFunc(ChangeSize);
	    glutDisplayFunc(Render);
	    glutIdleFunc(Render);
	}
}