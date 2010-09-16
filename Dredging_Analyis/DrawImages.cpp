
#include "DrawImages.h"

int DrawImages::mCount = 0 ;
bool gTextSet = false ;

int gValue = 0 ;

DrawImages	::	DrawImages( wxFrame* aParent, std::vector< wxString > aImageVector, wxBitmapType aFormat )
			:	wxPanel( aParent, wxID_ANY, wxDefaultPosition, wxSize(500,500), wxBORDER_NONE, _T("Top Panel") ),
				mPaintEventCallCount( _T("") ),
				mImageVector( aImageVector ),
				mTextBox1( NULL ),
				mTextBox2( NULL ),
				mTextBox3( NULL )
{			

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
	
	mSports->AddPage( mIndoor_Sports_Panel,  _T("Input"), true ) ;		/*Indoor*/
	mSports->AddPage( mOutdoor_Sports_Panel, _T("Results"), false ) ;	/*Outdoor*/
	mSports->AddPage( mMedia_Panel, _T("Media"), false ) ;				/*Video*/

}

void
DrawImages	:: addIndoorSportsNotebook()
{
	
	mIndoor_Sports->AddPage( mChess_Panel, _T("Image_1"),true ) ;			/*Chess, Table Tennis*/
	mTextBox1	= new wxTextCtrl( mChess_Panel, TEXT_CTRL_1, _T(""), wxPoint(200,310), wxSize(50,20), wxTE_PROCESS_ENTER ) ;
	mTextBox2	= new wxTextCtrl( mChess_Panel, TEXT_CTRL_2, _T(""), wxPoint(0,250), wxSize(50,20), wxTE_PROCESS_ENTER ) ;

	mIndoor_Sports->AddPage( mTable_Tennis_Panel, _T("Image_2"), false ) ;
	mTextBox3 = new wxTextCtrl( mTable_Tennis_Panel, TEXT_CTRL_3, _T(""), wxPoint(220,290), wxSize(50,20), wxTE_PROCESS_ENTER ) ;

}

void
DrawImages	:: addOutdoorSportsNotebook()
{
		
	mOutdoor_Sports->AddPage( mCricket_Panel	, _T("Calculations"), false ) ;	/*Cricket, Basket Ball*/
	mOutdoor_Sports->AddPage( mBasket_Ball_Panel, _T("Graphs"), true ) ;

}

void
DrawImages	:: drawHelper()
{
	if( mIndoor_Sports->GetSelection() == 0 )
	{
		wxClientDC lClientDC( mChess_Panel ) ;
		mImage.LoadFile( mImageVector[0], wxBITMAP_TYPE_JPEG ) ;
		lClientDC.Clear() ;
		mChess_Panel->SetBackgroundColour( wxColour(_T("wxWHITE")) );
		lClientDC.DrawBitmap( mImage, 0, 0, false ) ;
	}

	else
	{
		wxClientDC lClientDC( mTable_Tennis_Panel ) ;
		mImage.LoadFile( mImageVector[1], wxBITMAP_TYPE_JPEG ) ;
		lClientDC.Clear() ;
		mChess_Panel->SetBackgroundColour( wxColour(_T("wxWHITE")) );
		lClientDC.DrawBitmap( mImage, 0, 0, false ) ;
	}
}

void 
DrawImages	::	paintEvent( wxPaintEvent & evt )
{
	mCount++ ;
	mPaintEventCallCount = wxString::Format(wxT("%d"), mCount );
	mStaticText->SetLabel( mPaintEventCallCount ) ;

	wxPaintDC lPaintDC( this );
	
	if( mIndoor_Sports->GetSelection() == 0 )
	{
		wxClientDC lClientDC( mChess_Panel ) ;
		mImage.LoadFile( mImageVector[0], wxBITMAP_TYPE_JPEG ) ;
		lClientDC.Clear() ;
		mChess_Panel->SetBackgroundColour( wxColour(_T("wxWHITE")) );
		lClientDC.DrawBitmap( mImage, 0, 0, false ) ;
	}
	
	else
	{
		wxClientDC lClientDC( mTable_Tennis_Panel ) ;
		mImage.LoadFile( mImageVector[1], wxBITMAP_TYPE_JPEG ) ;
		lClientDC.Clear() ;
		mChess_Panel->SetBackgroundColour( wxColour(_T("wxWHITE")) );
		lClientDC.DrawBitmap( mImage, 0, 0, false ) ;
	}


	if( ( mSports -> GetSelection() == 1 ) && ( mOutdoor_Sports -> GetSelection() == 1 ) )
		drawLayout() ;
}

void
DrawImages	::	indoorImages( wxNotebookEvent& eve )
{
	if( mIndoor_Sports->GetSelection() == 0 )
	{
		wxClientDC lClientDC( mChess_Panel ) ;
		mImage.LoadFile( mImageVector[0], wxBITMAP_TYPE_JPEG ) ;
		lClientDC.Clear() ;
		mChess_Panel->SetBackgroundColour( wxColour(_T("wxWHITE")) );
		lClientDC.DrawBitmap( mImage, 0, 0, false ) ;
	}

	else
	{
		wxClientDC lClientDC( mTable_Tennis_Panel ) ;
		mImage.LoadFile( mImageVector[1], wxBITMAP_TYPE_JPEG ) ;
		lClientDC.Clear() ;
		mChess_Panel->SetBackgroundColour( wxColour(_T("wxWHITE")) );
		lClientDC.DrawBitmap( mImage, 0, 0, false ) ;
	}

}

void
DrawImages	::	helpFunction( wxNotebookEvent &eve )
{
	indoorImages( eve ) ;

	if( ( mSports -> GetSelection() == 1 ) && ( mOutdoor_Sports -> GetSelection() == 1 ) )
		drawLayout() ;
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
DrawImages	::	isNumeric( std::string aReceivedString )
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
	std::string lString ;
	int lCase ;
	
	if( eve.GetId() == TEXT_CTRL_1 )
	{
		lString = std::string( (mTextBox1->GetValue()).mb_str() ) ;
		lCase = 1 ;
	}
	else if( eve.GetId() == TEXT_CTRL_2 )
	{
		lString = std::string( (mTextBox2->GetValue()).mb_str() ) ;
		lCase = 2 ;
	}
	else if( eve.GetId() == TEXT_CTRL_3 )
	{
		lString = std::string( (mTextBox3->GetValue()).mb_str() ) ;
		lCase = 3 ;
	}

	if ( isNumeric( lString ) )
	{
	}

	else
	{
		switch( lCase )
		{
			case 1:
				mTextBox1->Remove( gValue, gValue+1 ) ;
				break ;
			
			case 2:
				mTextBox2->Remove( gValue, gValue+1 ) ;
				break ;
			
			case 3:
				mTextBox3->Remove( gValue, gValue+1 ) ;
				break ;
			
			default:
				break ;
		}
		Beep(400, 100) ;	// Definitely MSW specific function
	}
}


void
DrawImages	::	makeCalculations()
{
	std::vector<float> lValues ;
	
	lValues.push_back( wxAtof(mTextBox1->GetValue()) );
	lValues.push_back( wxAtof(mTextBox2->GetValue()) );
	lValues.push_back( wxAtof(mTextBox3->GetValue()) );


	if( (lValues[0] != 0) &&
		(lValues[1] != 0) &&
		(lValues[2] != 0)
	  )
	{
		
		mNumberOfBuckets			= ceil( 1000/( lValues[0]* lValues[1]* lValues[2] ) );
		mNumOfLateralBuckets		= ceil( 10 / lValues[0] ) ;
		mNumOfLongitudinalBuckets	= ceil( 10 / lValues[1] ) ;

		wxString str( wxString::Format(wxT("%i"),mNumberOfBuckets) ) ;
		str.Append(_T(",") ) ;
		str.Append( wxString::Format(wxT("%i"),mNumOfLateralBuckets) ) ;
		str.Append(_T(",") ) ;
		str.Append( wxString::Format(wxT("%i"),mNumOfLongitudinalBuckets) ) ;


		mStaticText -> SetLabel( str );

	}

	drawLayout() ;
}

void
DrawImages	::	drawLayout()
{
	
	int lX_Add , lY_Add ;
	int lx1,ly1, lx2, ly2 ;
	static bool lChangeColor( true ) ;

	wxSize lSize( mCricket_Panel -> GetSize() ) ;
	lX_Add = lSize.GetHeight() ;
	lY_Add = lSize.GetWidth() ;

	lX_Add /= mNumOfLateralBuckets ;
	lY_Add /= mNumOfLongitudinalBuckets ;

	wxClientDC lDC( mBasket_Ball_Panel ) ;

	for( int i=0 ; i < mNumOfLateralBuckets ; i++ )
	{
		lx1 = lX_Add * i ;
		for( int j=0 ; j < mNumOfLongitudinalBuckets ; j++ )
		{
			ly1 = lY_Add * j ;
			lx2 = lX_Add * ( i+1 ) ;
			ly2 = lY_Add * ( j+1 ) ;

			if( lChangeColor )
			{
				lDC.SetBrush( *wxBLUE_BRUSH ) ;
				lChangeColor = false ;
			}
			else
			{
				lDC.SetBrush( *wxRED_BRUSH ) ;
				lChangeColor = true ;
			}

			lDC.DrawRectangle( lx1, ly1, lx2, ly2 ) ;

		}
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
	EVT_TEXT( TEXT_CTRL_2, enteredWXString )
	EVT_TEXT( TEXT_CTRL_3, enteredWXString )
	EVT_TEXT_ENTER( wxID_ANY, resetGlobalValue )
	
END_EVENT_TABLE()
