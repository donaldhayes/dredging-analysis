#ifndef MY_APP_H
#define MY_APP_H

#include "wx/wx.h"
#include "FormInputs.h"
#ifdef __WXMSW__
    #include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif 



class MyApp : public wxApp
{
	public:
		
		FormInputs *frame;
		virtual bool OnInit() ;
};

IMPLEMENT_APP( MyApp )

#endif