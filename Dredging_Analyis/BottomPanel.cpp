#include "BottomPanel.h"

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


BEGIN_EVENT_TABLE( BottomPanel, wxPanel )

END_EVENT_TABLE()