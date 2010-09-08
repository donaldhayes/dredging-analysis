#ifndef MY_APP_H
#define MY_APP_H

#include <wx/wx.h>

	class DrawImages ;
	class MyApp : public wxApp
	{
		public:
			
			MyApp() ;
			bool OnInit() ;

		private:
			wxFrame* mFrameObject ;
			DrawImages* mDrawImagesObject ;
	} ;

	IMPLEMENT_APP( MyApp ) 

#endif