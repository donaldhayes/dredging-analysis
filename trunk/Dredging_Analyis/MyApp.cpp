#include "MyApp.h"
#include "DrawImages.h"
#include "BottomPanel.h"


MyApp	::	MyApp()
		:	mFrameObject( NULL ),
			mDrawImagesObject( NULL )

{
	wxInitAllImageHandlers() ;
	loadImageListToVector() ;
}


void
MyApp	::	loadImageListToVector()
{
	
	///	Programmer must push back the names of all images names to mImageVector to be loaded on to notebook pages.

	mImageVector.push_back( _T("FrontView.jpg") ) ;
	mImageVector.push_back( _T("Right.jpg") ) ;

}

bool
MyApp	:: OnInit()
{
	if( !( wxApp::OnInit() ) )
		return false ;
	
	mFrameObject			= new wxFrame( NULL, wxID_ANY, _T("Extra Curicular Activities"), wxPoint(50,50), wxSize(500,700), ( wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX ), _T("Frame") ) ;

	mDrawImagesObject		= new DrawImages( mFrameObject, mImageVector, wxBITMAP_TYPE_JPEG );
	mBottomPanelReference	= new BottomPanel( mFrameObject ) ;

	mBottomPanelReference -> setDrawImagesFriendReference( mDrawImagesObject ) ;

	mFrameObject -> Show(true) ;
	mFrameObject -> SetFocus() ;
	
	return true ;

}


void
MyApp	::	escapeKeyBoardEvent( wxKeyEvent &eve )
{
	if( eve.GetKeyCode() == WXK_ESCAPE )
	{
		mFrameObject -> Close() ;
	}

	else
		eve.Skip() ;
}

BEGIN_EVENT_TABLE( MyApp, wxApp )

	EVT_CHAR( MyApp::escapeKeyBoardEvent )

END_EVENT_TABLE()