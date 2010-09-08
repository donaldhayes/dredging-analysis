
#include "DrawImages.h"

int DrawImages::mCount = 0 ;
bool gTextSet = false ;

int gValue = 0 ;

DrawImages	::	DrawImages( wxFrame* aParent, wxString aFile, wxBitmapType aFormat )
			:	wxPanel( aParent, wxID_ANY, wxDefaultPosition, wxSize(500,500), wxBORDER_NONE, _T("Top Panel") ),
				mFile( aFile ),
				mPaintEventCallCount( _T("") )
{			
	mImage.LoadFile( aFile, aFormat ) ;

	mSports					= new wxNotebook( this, SPORTS, wxDefaultPosition, wxSize(500,500) ) ;
	mIndoor_Sports_Panel	= new wxPanel( mSports, NB_INDOOR_PANEL, wxDefaultPosition, wxSize(500,500) ) ;
	mOutdoor_Sports_Panel	= new wxPanel( mSports, NB_OUTDOOR_PANEL, wxDefaultPosition, wxSize(500,500) ) ;
	mMedia_Panel			= new wxPanel( mSports, MEDIA_PANEL, wxDefaultPosition, wxSize(500,500) ) ;

	mIndoor_Sports			= new wxNotebook( mIndoor_Sports_Panel, INDOOR_SPORTS, wxDefaultPosition, wxSize(500,500) ) ;

	mChess_Panel			= new wxPanel( mIndoor_Sports, wxID_ANY, wxDefaultPosition, wxSize(500,500) ) ;
	mTable_Tennis_Panel		= new wxPanel( mIndoor_Sports, wxID_ANY, wxDefaultPosition, wxSize(500,500) ) ;

	mOutdoor_Sports			= new wxNotebook( mOutdoor_Sports_Panel, OUTDOOR_SPORTS, wxDefaultPosition, wxSize(500,500) ) ;

	mCricket_Panel			= new wxPanel( mOutdoor_Sports, wxID_ANY, wxDefaultPosition, wxSize(500,500) ) ;
	mBasket_Ball_Panel		= new wxPanel( mOutdoor_Sports, wxID_ANY, wxDefaultPosition, wxSize(500,500) ) ;

	mTextBox1				= new wxTextCtrl( mCricket_Panel, TEXT_CTRL_1, _T(""), wxPoint(200,200), wxDefaultSize, wxTE_PROCESS_ENTER ) ;
	mStaticText				= new wxStaticText( mChess_Panel, -1,_T(""), wxPoint(50,50) ) ;
	
	mMediaPlayer			= new wxMediaCtrl( mMedia_Panel, MEDIA_PLAYER, wxEmptyString, wxDefaultPosition, wxSize(490,400), 0, wxMEDIABACKEND_WMP10 ) ;
	
	addSportsNotebook() ;
	addIndoorSportsNotebook() ;
	addOutdoorSportsNotebook() ;
	
	
	mMediaPlayer -> ShowPlayerControls(wxMEDIACTRLPLAYERCONTROLS_DEFAULT ) ;
	mMediaPlayer -> GetBestSize() ;

	mVedioLabel.Add(_T("One") );
	mVedioLabel.Add(_T("Two") ) ;

	mVedioSelection	= new wxComboBox( mMedia_Panel, wxID_ANY, _T("One") ,wxPoint( 150,420 ), wxDefaultSize, mVedioLabel, wxCB_DROPDOWN ) ;

}

DrawImages	::	~DrawImages()
{
	if( mMediaPlayer != NULL )
	{
		mMediaPlayer -> Stop() ;
		delete mMediaPlayer ;
	}
}

void
DrawImages	:: addSportsNotebook()
{
	
	mSports->AddPage( mIndoor_Sports_Panel,  _T(" Indoor "), true ) ;
	mSports->AddPage( mOutdoor_Sports_Panel, _T("Outdoor "), false ) ;
	mSports->AddPage( mMedia_Panel, _T("Video"), false ) ;

}

void
DrawImages	:: addIndoorSportsNotebook()
{
	
	mIndoor_Sports->AddPage( mChess_Panel, _T("Chess"),true ) ;
	mIndoor_Sports->AddPage( mTable_Tennis_Panel, _T("Table Tennis"), false ) ;

}

void
DrawImages	:: addOutdoorSportsNotebook()
{
		
	mOutdoor_Sports->AddPage( mCricket_Panel	, _T("Cricket"), false ) ;
	mOutdoor_Sports->AddPage( mBasket_Ball_Panel, _T("Basket Ball"), true ) ;

}

void 
DrawImages	::	paintEvent( wxPaintEvent & evt )
{
	mCount++ ;
	mPaintEventCallCount = wxString::Format(wxT("%d"), mCount );
	mStaticText->SetLabel( mPaintEventCallCount ) ;

	wxPaintDC lPaintDC( this );
	wxClientDC lClientDC( mChess_Panel );
	lClientDC.DrawBitmap( mImage, 0, 0, false ) ;

}

void
DrawImages	::	indoorImages( wxNotebookEvent& eve )
{
	if( mIndoor_Sports->GetSelection() == 0 )
	{
		wxClientDC dc2( mChess_Panel ) ;
		dc2.DrawBitmap( mImage, 0, 0, false ) ;		
	}
}

void
DrawImages	::	helpFunction( wxNotebookEvent &eve )
{
	indoorImages( eve ) ;
}

void
DrawImages	::	playVideoFile( wxCommandEvent &eve )
{
	if( mVedioSelection->GetCurrentSelection() == 0 )
	{	
		mMediaPlayer -> Load(_T("CableArm.avi") ) ;
		mMediaPlayer->Play() ;
	}

	else if( mVedioSelection -> GetCurrentSelection() == 1 )
	{
		mMediaPlayer -> Load(_T("CableArm.avi") ) ;
		mMediaPlayer -> Play() ;
	}
}


bool
DrawImages	::	isAlphaNumeric( std::string aReceivedString )
{

	int lLength( aReceivedString.length() ) ;
	std::string lPeriodString(".") ;

	for( int i=0 ; i<lLength; i++ )
	{
		std::string lStr ;
		lStr = aReceivedString[i]  ;

		if( lStr.compare(lPeriodString) == 0)
		{
		}
		else if( ! (isdigit(aReceivedString[i]) ) )
		{
			gValue = i ;
			return false ;
		}
	}

	return true ;
}

void
DrawImages	::	enteredWXString( wxCommandEvent& eve )
{
	std::string lString = std::string( (mTextBox1->GetValue()).mb_str() ) ;
	
	if ( isAlphaNumeric( lString ) )
	{
	}

	else
	{
		mTextBox1->Remove( gValue, gValue+1 ) ;
		Beep(400, 100) ;	// Definitely MSW specific function
	}
}

void
DrawImages	::	resetGlobalValue( wxCommandEvent& eve )
{
	gValue = 0 ;
}

BEGIN_EVENT_TABLE( DrawImages, wxPanel )

	EVT_PAINT( DrawImages :: paintEvent )
	EVT_NOTEBOOK_PAGE_CHANGED( INDOOR_SPORTS, indoorImages ) 
	EVT_NOTEBOOK_PAGE_CHANGED( SPORTS, helpFunction )
	EVT_COMBOBOX( wxID_ANY, playVideoFile )
	EVT_TEXT( TEXT_CTRL_1, enteredWXString )
	EVT_TEXT_ENTER( wxID_ANY, resetGlobalValue )

END_EVENT_TABLE()
