
#ifndef FORM_INPUTS_H
#define FORM_INPUTS_H

#include "MyFrame.h"
#include "DialogInput.h"



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
		void NumLateralBuckets(wxCommandEvent& );
		void OptimizeBucket();

		float ConvertWXStringToFloat( wxString ) ;
		wxString ConvertFloatToWXString( float ) ;
		wxString ConvertFloatToWXStrin( float );

		void OnSubmit( wxCommandEvent& ) ;
		void OnRefresh( wxCommandEvent& ) ;

		void Calculate_SwingCharacteristics() ;
		void Calculate_LateralBucketPlacements() ;
		void Calculate_BucketRows() ;
		friend class DialogInput;	

		DialogInput *mOptimizeDialog;	

		float mBoomLength, mMaxDredgeWidth, mMinDredgeReach, mMaxDredgeReach ;
		float mDredgeAreaWidth, mDredgeAreaLength, mDredgeAreaLateralOverlap, mDredgeAreaLongitudinalOverlap ;
		float mBucketWidth, mBucketLength, mPenetrationDepth ;
		float mSwingArcLength ;
		
		DECLARE_EVENT_TABLE()
};

#endif