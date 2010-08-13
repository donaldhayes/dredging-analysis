#include "FormInputs.h"
#include <cmath>
#include <iostream>
#include <wx/debug.h>
BEGIN_EVENT_TABLE( FormInputs, MyFrame )
	EVT_BUTTON( 0, OnSubmit ) 
	EVT_BUTTON( 1, OnRefresh ) 
	
END_EVENT_TABLE()


FormInputs	::	FormInputs()
			:	mBoomLength(0), mMaxDredgeWidth(0), mMinDredgeReach(0), mMaxDredgeReach(0),
				mDredgeAreaLength(0), mDredgeAreaWidth(0), mDredgeAreaLateralOverlap(0), mDredgeAreaLongitudinalOverlap(0),
				mBucketLength(0), mBucketWidth(0), mPenetrationDepth(0),

				mSwingArcLength(0),

				MyFrame(_T( "Dredging Analysis") )

{
	this->Connect(wxID_MEDIA,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(FormInputs::GetFileToPlay));
	this->Connect(wxID_ANY, wxEVT_MEDIA_LOADED,wxMediaEventHandler(FormInputs::OnMediaLoad),(wxObject*)0);
	this->Connect(wxID_OPTIMIZE,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(FormInputs::OptimizeBucketPlacement));
  mOptimizeDialog = new DialogInput();
		
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

wxString
FormInputs :: ConvertFloatToWXStrin( float lFloat )
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
void FormInputs::OptimizeBucketPlacement(wxCommandEvent& WXUNUSED(event))
{

	GetDredgeAreaData() ;
	GetMachineData() ;
	GetBucketData() ;
	OptimizeBucket();
}
void FormInputs::OptimizeBucket()
{
	//mOptimizeDialog = new DialogInput();
	//float *lTempBoomLength = &(mOptimizeDialog->mBoomLength) ;
	//*lTempBoomLength = mBoomLength;
	mOptimizeDialog->mBoomLength = &mBoomLength;
	mOptimizeDialog->mBucketLength = &mBucketLength;
	mOptimizeDialog->mDredgeAreaLength = &mDredgeAreaLength;
	//*(mOptimizeDialog->mBoomLength) = mBoomLength; 
	mOptimizeDialog->ShowModal();

}
