#include <boost/function.hpp>

#ifndef RENDER_H
#define RENDER_H
namespace Render 
{
	void ChangeSize(boost::function<void(int,int)>);
	void Render(boost::function<void()>);
	void SetEvents();
};
#endif 