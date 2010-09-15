#ifndef MY_APP_H
#define MY_APP_H

#include <wx/wx.h>
#include <vector>

	class DrawImages ;
	class BottomPanel ;

	class MyApp : public wxApp
	{
		public:
			
			MyApp() ;
			bool OnInit() ;
			void escapeKeyBoardEvent( wxKeyEvent& eve ) ;
			void loadImageListToVector() ;

		private:
			wxFrame		*mFrameObject ;
			DrawImages	*mDrawImagesObject ;
			BottomPanel	*mBottomPanelReference ;
			
			std::vector < wxString > mImageVector ;

			DECLARE_EVENT_TABLE() 
	} ;

	IMPLEMENT_APP( MyApp ) 

#endif