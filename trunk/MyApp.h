#ifndef MY_APP_H
#define MY_APP_H

#include "wx/wx.h"
class MyApp : public wxApp
{
	public:
		virtual bool OnInit() ;
};

IMPLEMENT_APP(MyApp)
#endif