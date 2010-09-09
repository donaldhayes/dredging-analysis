#ifndef MY_APP_H
#define MY_APP_H

#include <wx/wx.h>

	class DrawImages ;
	class BottomPanel ;

	class MyApp : public wxApp
	{
		public:
			
			MyApp() ;
			bool OnInit() ;
			void escapeKeyBoardEvent( wxKeyEvent& eve ) ;

		private:
			wxFrame		*mFrameObject ;
			DrawImages	*mDrawImagesObject ;
			BottomPanel	*mBottomPanelReference ;

			DECLARE_EVENT_TABLE() 
	} ;

	IMPLEMENT_APP( MyApp ) 

#endif