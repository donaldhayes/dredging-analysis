#ifndef FORM_INPUTS_H
#define FORM_INPUTS_H

#include "MyFrame.h"


class FormInputs : public MyFrame
{
	public:
		FormInputs() ;
		
		void GetDredgeAreaData() ;
		void GetMachineData() ;
		void GetBucketData() ;

		void GetFileToPlay(wxCommandEvent& event);
		void OnGetPath(const wxString& path);
		void OnMediaLoad(wxMediaEvent& event);

		float ConvertWXStringToFloat( wxString ) ;
		wxString ConvertFloatToWXString( float ) ;

		void OnSubmit( wxCommandEvent& ) ;
		void OnRefresh( wxCommandEvent& ) ;

		void Calculate_SwingCharacteristics() ;
		void Calculate_LateralBucketPlacements() ;
		void Calculate_BucketRows() ;
	
	private:
		float mBoomLength, mMaxDredgeWidth, mMinDredgeReach, mMaxDredgeReach ;
		float mDredgeAreaWidth, mDredgeAreaLength, mDredgeAreaLateralOverlap, mDredgeAreaLongitudinalOverlap ;
		float mBucketWidth, mBucketLength, mPenetrationDepth ;

		float mSwingArcLength ;

		DECLARE_EVENT_TABLE()
};

#endif