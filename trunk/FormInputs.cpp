#include "FormInputs.h"
#include <cmath>
#include <iostream>

BEGIN_EVENT_TABLE( FormInputs, MyFrame )
	EVT_BUTTON( 0, OnSubmit ) 
	EVT_BUTTON( 1, OnRefresh ) 
	//EVT_CHOICE(wxID_LATERAL_BUCKET, FormInputs::NumLateralBuckets)
END_EVENT_TABLE()

FormInputs	::	FormInputs()
			:	mBoomLength(0), mMaxDredgeWidth(0), mMinDredgeReach(0), mMaxDredgeReach(0),
				mDredgeAreaLength(0), mDredgeAreaWidth(0), mDredgeAreaLateralOverlap(0), mDredgeAreaLongitudinalOverlap(0),
				mBucketLength(0), mBucketWidth(0), mPenetrationDepth(0),

				mSwingArcLength(0),

				MyFrame(_T( "Dredging Analysis") )

{
	this->Connect(2,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(FormInputs::GetFileToPlay));
	this->Connect(wxID_ANY, wxEVT_MEDIA_LOADED,wxMediaEventHandler(FormInputs::OnMediaLoad),(wxObject*)0);
	this->Connect(3,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(FormInputs::OptimizeBucketPlacement));
	this->Connect(wxID_LATERAL_BUCKET,wxEVT_COMMAND_CHOICE_SELECTED,wxCommandEventHandler(FormInputs::NumLateralBuckets));
}
void FormInputs :: GetFileToPlay(wxCommandEvent& WXUNUSED(event))
{
	mNotebook -> ChangeSelection(2) ;
	wxFileDialog m_fd = new wxFileDialog(mMediaPlayerPanel,_("<-----Select From List----->"),_(""),_(""),_("*.*"),wxOPEN,wxDefaultPosition,wxDefaultSize);
	if(m_fd.ShowModal() == wxID_OK)
	{
		OnGetPath(m_fd.GetPath());
	}

}
void FormInputs ::OnGetPath(const wxString& path)
{
	bool lLoadCheck = mMediaPlayer->Load(path);
}


void FormInputs::OnMediaLoad(wxMediaEvent& WXUNUSED(event))
{
	bool lPlayCheck = mMediaPlayer->Play();
	if(lPlayCheck)
	{
		mMediaPlayer->ShowPlayerControls(wxMEDIACTRLPLAYERCONTROLS_DEFAULT);
	}
	else
	{
		wxLogMessage(wxT("Unable To Play the File"));
	}
}

void FormInputs::OptimizeBucketPlacement(wxCommandEvent& WXUNUSED(event))
{
	mDialog = new wxDialog(NULL,3,_("Optimize"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE,"dialogbox");
	wxBoxSizer *topSizer = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );

	wxString mJustificationChoices[2];
    mJustificationChoices[0] = _("&Center Justified");
    mJustificationChoices[1] = _("&Side Justified");

	wxRadioBox* mCenter_Side = new wxRadioBox(mDialog, wxID_ANY, _(""),wxDefaultPosition, wxDefaultSize, 2, mJustificationChoices);
    item0->Add(mCenter_Side, 0, wxGROW|wxALL, 5);
	mCenter_Side->SetSelection(0);

	wxString *mNumber_Buckets= new wxString[3];
    mNumber_Buckets[0] = _("1");
	mNumber_Buckets[1] = _("2");
	mNumber_Buckets[2] = _("3");
    wxStaticBox* staticBox3 = new wxStaticBox(mDialog, 9, _("Number of Buckets:"));

    wxBoxSizer* styleSizer = new wxStaticBoxSizer( staticBox3, wxVERTICAL );
    item0->Add(styleSizer, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemSizer2 = new wxBoxSizer( wxVERTICAL );

     choice2 = new wxChoice(mDialog, wxID_LATERAL_BUCKET, wxDefaultPosition, wxDefaultSize,5, mNumber_Buckets,0);
	wxChoice* choice3 = new wxChoice(mDialog, wxID_LONGITUDINAL_BUCKET, wxDefaultPosition, wxDefaultSize,5, mNumber_Buckets,0);


    itemSizer2->Add(new wxStaticText(mDialog, wxID_ANY, _("&Lateral Buckets:")), 0,wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);
	
    itemSizer2->Add(5, 5, 1, wxALL, 0);
    itemSizer2->Add(choice2, 0, wxALL|wxLEFT, 5);
	itemSizer2->Add(new wxStaticText(mDialog, wxID_ANY, _("&Longitudinal Buckets:")), 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);
	itemSizer2->Add(choice3, 0, wxALL|wxLEFT, 5);

    styleSizer->Add(itemSizer2, 0, wxGROW|wxALL, 5);
	topSizer->Add( item0, 1, wxGROW|wxALIGN_CENTRE|wxALL, 5 );
    topSizer->AddSpacer(5);
	mDialog->SetSizer(topSizer);
	this->SetAutoLayout(true);

	mDialog->ShowModal();
	mDialog->Destroy();
	
}

void FormInputs::NumLateralBuckets(wxCommandEvent& WXUNUSED(event))
{
	wxString msg;
	int lSelection = choice2->GetCurrentSelection();
	msg.Printf(_T("You've entered %d"), lSelection );
	

	
}


void
FormInputs :: GetDredgeAreaData()
{
	wxString lString ;
	
	lString = mDredgeArea_Width -> GetValue() ;
	mDredgeAreaWidth = ConvertWXStringToFloat( lString ) ;

	lString = mDredgeArea_Length -> GetValue() ;
	mDredgeAreaLength = ConvertWXStringToFloat( lString ) ;

	lString = mDredgeArea_LateralOverlap -> GetValue() ;
	mDredgeAreaLateralOverlap = ConvertWXStringToFloat( lString ) ;

	lString = mDredgeArea_LongitudinalOverlap -> GetValue() ;
	mDredgeAreaLongitudinalOverlap = ConvertWXStringToFloat( lString ) ;
	
}

void
FormInputs :: GetMachineData()
{

	wxString lString ;
	
	lString = mMachine_BoomLength -> GetValue() ;
	mBoomLength = ConvertWXStringToFloat( lString ) ;

	lString = mMachine_MaxDredgeWidth -> GetValue() ;
	mMaxDredgeWidth = ConvertWXStringToFloat( lString ) ;

	lString = mMachine_MinDredgeReach -> GetValue() ;
	mMinDredgeReach = ConvertWXStringToFloat( lString ) ;

	lString = mMachine_MaxDredgeReach -> GetValue() ;
	mMaxDredgeReach = ConvertWXStringToFloat( lString ) ;

}

void
FormInputs :: GetBucketData()
{

	wxString lString ;
	
	lString = mBucket_Width -> GetValue() ;
	mBucketWidth = ConvertWXStringToFloat( lString ) ;

	lString = mBucket_Length -> GetValue() ;
	mBucketLength = ConvertWXStringToFloat( lString ) ;

	lString = mBucket_PenetrationDepth -> GetValue() ;
	mPenetrationDepth = ConvertWXStringToFloat( lString ) ;

}

void
FormInputs :: OnSubmit( wxCommandEvent& SubmitEvent )
{

	GetDredgeAreaData() ;
	GetMachineData() ;
	GetBucketData() ;

	Calculate_SwingCharacteristics() ;
	Calculate_LateralBucketPlacements() ;
	Calculate_BucketRows() ;

	mNotebook -> ChangeSelection(1) ;

}

void
FormInputs :: OnRefresh( wxCommandEvent& RefreshEvent )
{

	mMachine_BoomLength -> Clear() ;
	mMachine_MaxDredgeWidth -> Clear() ;
	mMachine_MinDredgeReach -> Clear() ;
	mMachine_MaxDredgeReach -> Clear() ;
	
    mBucket_Width -> Clear() ;
	mBucket_Length -> Clear() ;
	mBucket_PenetrationDepth -> Clear() ;

	mDredgeArea_Width -> Clear() ;
	mDredgeArea_Length -> Clear() ;
	mDredgeArea_LateralOverlap -> Clear() ;
	mDredgeArea_LongitudinalOverlap -> Clear() ;

	mNotebook -> ChangeSelection(0) ;
	
}

float
FormInputs :: ConvertWXStringToFloat( wxString lString )
{
	double lValue ;
	lString.ToDouble(&lValue) ;
	return (float)lValue ;
}

wxString
FormInputs :: ConvertFloatToWXString( float lFloat )
{
	return  wxString::Format(wxT("%f"), lFloat) ;
}

void
FormInputs :: Calculate_SwingCharacteristics()
{
	float lTotalDredgeSwingAngle = 0 ;
	
	lTotalDredgeSwingAngle = 2 * asin( mDredgeAreaLength / (2*mBoomLength) );
	mSwingArcLength = mDredgeAreaLength / lTotalDredgeSwingAngle ;

	wxString lString( ConvertFloatToWXString(mSwingArcLength) ) ;
	wxStaticText* lStaticText = new wxStaticText( mResultsPanelTab, wxID_ANY, lString, wxPoint(50,50), wxDefaultSize, 0, _T("Static Dredge Area Length Label") ) ;

}

void
FormInputs :: Calculate_LateralBucketPlacements()
{

	int lnumCenterJustified = 0, lnumSideJustified = 0;
	float lCenterJustified = 0, lSideJustified = 0 ;


	lnumCenterJustified = (	2* (  (mSwingArcLength - mBucketLength)/
								  (2* (mBucketLength - mDredgeAreaLateralOverlap) )
							   ) + 1 
						  ) + 1 ;

	lnumSideJustified = (  (mSwingArcLength - mDredgeAreaLateralOverlap)/
						   (mBucketLength - mDredgeAreaLateralOverlap)
					    ) + 1 ;

	lCenterJustified = mBucketLength - ( (mSwingArcLength - mBucketLength)/
										 (lnumCenterJustified - 1)
									   ) ;

	lSideJustified = ( (lnumSideJustified*mBucketLength) - (mBucketLength + lnumSideJustified) /
		               (lnumSideJustified - 2)
					 ) ;


	std::cout <<" Number of Buckets in a swing width given a fixed overlap .... " << std::endl ;
	std::cout <<" \t\t i)   For center justified bucket placement:  "<< lnumCenterJustified << std::endl ;
	std::cout <<" \t\t ii)  For side justified ( left or right ) bucket placement:  "<< lnumSideJustified << std::endl ;
	std::cout <<" \n\t The bucket overlap necessary for the number of bucket placements in a swing width to exactly fit the dredging width ..." <<std::endl ;
	std::cout <<" \t\t i)   For center justified bucket placement:  "<< lCenterJustified << std::endl ;
	std::cout <<" \t\t ii)  For side justified ( left or right ) bucket placement:  "<< lSideJustified <<std::endl ;

}

void
FormInputs :: Calculate_BucketRows()
{

	float lnumBucketRows, lLongitudinalOverlap ;

	lnumBucketRows = floor (  mDredgeAreaWidth / 
								( mBucketWidth - mDredgeAreaLongitudinalOverlap ) 
						   );

	lLongitudinalOverlap = mBucketWidth - ( mDredgeAreaLength / lnumBucketRows ) + 1 ;

	std::cout << " \n\nNumber of bucket rows:\t" << lnumBucketRows <<std::endl ;
	std::cout << " Longitudinal bucket overlap to fix bucket exactly:\t" << lLongitudinalOverlap <<std::endl ;

}
