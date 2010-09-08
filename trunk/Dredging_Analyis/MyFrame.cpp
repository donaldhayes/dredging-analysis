/*#include "MyFrame.h"

enum
{
	OUTER_NOTEBOOK = 11, 
	INNER_NOTEBOOK, 
	FRAME_PANEL, 
	NB_SPORTS_PANEL,
	NB_INDOOR_PANEL,
	NB_OUTDOOR_PANEL,
	INDOOR_SPORTS,
	OUTDOOR_SPORTS,
	SPORTS
};

MyFrame ::	MyFrame()
		:	wxFrame( NULL, wxID_ANY, _T("Extra Curicular Activities"), wxDefaultPosition, wxSize(500,700), wxDEFAULT_FRAME_STYLE, wxString(_T("Frame")) )
			
{
	
	
	//paintNow() ;

}
/*
void
MyFrame	:: addSportsNotebook()
{

	
	mSports->AddPage( mIndoor_Sports_Panel,  _T(" Indoor "), true, 0  ) ;
	mSports->AddPage( mOutdoor_Sports_Panel, _T("Outdoor "), false, 1 ) ;

}

void
MyFrame	:: addIndoorSportsNotebook()
{
	
	mIndoor_Sports->AddPage( mChess_Panel, _T("Chess"),true, 2 ) ;
	mIndoor_Sports->AddPage( mTable_Tennis_Panel, _T("Table Tennis"), false, 3 ) ;

}

void
MyFrame	:: addOutdoorSportsNotebook()
{
		
	mOutdoor_Sports->AddPage( mCricket_Panel	, _T("Cricket"), false, 4 ) ;
	mOutdoor_Sports->AddPage( mBasket_Ball_Panel, _T("Basket Ball"), true, 5 ) ;

}

void 
MyFrame	::	paintEvent( wxPaintEvent & evt )
{
	if( mIndoor_Sports->GetSelection() == 0 )
	{
		mIndoor_Sports->Show(true) ;
		wxPaintDC dc( this );
		render(dc);
	}
	else
	{
		
	}
}
 
void 
MyFrame	::	paintNow()
{
	if( mIndoor_Sports->GetSelection() == 0 )
	{
		mIndoor_Sports->Show(true) ;
		wxClientDC dc( this );
		render(dc);
	}
	else
	{
		//Refresh() ;
	}
}
 
void 
MyFrame	::	render(wxDC&  dc)
{
	//   int neww, newh;
    /*dc.GetSize( &neww, &newh );
    
    if( neww != mWidth || newh != mHeight )
    {
        mResized = wxBitmap( mImage.Scale( neww, newh ) );
        mWidth = neww;
        mHeight = newh;
        dc.DrawBitmap( mResized, 0, 0, false );
    }
	else
	{
        dc.DrawBitmap( mImage, 0, 0, false );
    }
	/*dc.DrawBitmap( mImage, 0, 0, false );

}

void 
MyFrame	::	OnSize(wxSizeEvent& event)
{
	/*Refresh();
    event.Skip();*/
/*}

BEGIN_EVENT_TABLE( MyFrame, wxFrame )

	EVT_PAINT( MyFrame :: paintEvent )
	/*EVT_SIZE ( MyFrame :: OnSize )
	EVT_NOTEBOOK_PAGE_CHANGED( SPORTS, MyFrame :: paintNow )
	//EVT_CLOSE( MyFrame :: onClose )

END_EVENT_TABLE()*/