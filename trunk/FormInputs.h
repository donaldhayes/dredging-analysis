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
		void OptimizeBucketPlacement(wxCommandEvent& event);
		void NumLateralBuckets(wxCommandEvent& event);

		float ConvertWXStringToFloat( wxString ) ;
		wxString ConvertFloatToWXString( float ) ;

		void OnSubmit( wxCommandEvent& ) ;
		void OnRefresh( wxCommandEvent& ) ;

		void Calculate_SwingCharacteristics() ;
		void Calculate_LateralBucketPlacements() ;
		void Calculate_BucketRows() ;
		enum { wxID_LATERAL_BUCKET = 12,wxID_LONGITUDINAL_BUCKET  };
	
	private:
		float mBoomLength, mMaxDredgeWidth, mMinDredgeReach, mMaxDredgeReach ;
		float mDredgeAreaWidth, mDredgeAreaLength, mDredgeAreaLateralOverlap, mDredgeAreaLongitudinalOverlap ;
		float mBucketWidth, mBucketLength, mPenetrationDepth ;

		float mSwingArcLength ;

		wxDialog *mDialog;
		wxChoice *choice2;

		DECLARE_EVENT_TABLE()
};

#endif