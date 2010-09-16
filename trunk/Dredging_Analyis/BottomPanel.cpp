#include "BottomPanel.h"
#include "DrawImages.h"

enum
{
	GET_RESULTS = 200,
	BUCKET_SELECTION_COMBO_BOX
};

BottomPanel	::	BottomPanel(wxFrame *aParent)
			:	wxPanel( aParent, wxID_ANY, wxPoint(0,500), wxSize(500,200), wxBORDER_NONE, _T(" Bottom Panel to place controls ") ) ,
				mBucketTypeStaticText( new wxStaticText( this, wxID_ANY, _T("Bucket Type"), wxPoint(20,20)) ),
				mBucketSelectionComboBox( new wxComboBox( this, BUCKET_SELECTION_COMBO_BOX, _T("CableArm"), wxPoint(90,17), wxDefaultSize) ) ,
				mGetResultsButton( new wxButton( this, GET_RESULTS, _T("Get Results"), wxPoint(400,137)) )

{
	mBucketTypes.Add("CableArm") ;
	mBucketTypes.Add("GLDD Enclosed") ;
	mBucketTypes.Add("GLDD Conventional") ;

	mBucketSelectionComboBox -> Append( mBucketTypes ) ;

}


void
BottomPanel	::	whichImagesToLoad( wxCommandEvent &eve )
{
	int lSelect( mBucketSelectionComboBox -> GetSelection() ) ;

	mFriendReference -> mWhichImageFileToLoad = lSelect ;
	
	if( mFriendReference -> mSports -> GetSelection() != 0 )
	{
		mFriendReference -> mSports -> ChangeSelection( 0 ) ;
	}

	mFriendReference -> drawHelper() ;
}

void
BottomPanel	::	setDrawImagesFriendReference( DrawImages *aReference )
{
	mFriendReference = aReference ;
}

void
BottomPanel	::	getResults( wxCommandEvent &eve )
{
	
	
	mFriendReference -> mSports -> ChangeSelection( 1 ) ;
	mFriendReference -> mOutdoor_Sports -> ChangeSelection( 1 ) ;/*-> ChangeSelection( 1 )*/ ;
	mFriendReference -> makeCalculations() ;
	//mFriendReference -> drawHelper() ;

}

BEGIN_EVENT_TABLE( BottomPanel, wxPanel )

	EVT_COMBOBOX( BUCKET_SELECTION_COMBO_BOX, whichImagesToLoad )
	EVT_BUTTON	( GET_RESULTS, getResults )

END_EVENT_TABLE()