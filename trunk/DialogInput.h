#ifndef DIALOG_INPUT_H
#define DIALOG_INPUT_H
#include "FormInputs.h"
#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

class FormInputs;
class DialogInput :public wxDialog
{
public:
	DialogInput();
	
	void AddOptimizeDialog();
		wxChoice *mLateralChoice,*mLongitudinalChoice;
		wxRadioBox* mCenterSideRadio;
		wxTextCtrl *mLateralOverlap,*mLongitudinalOverlap,*mBucket,*mDredgeArea,*mBoom;
		FormInputs *mFormInput;
		enum { wxID_RADIO,wxID_LATERAL_BUCKET ,wxID_LONGITUDINAL_BUCKET };
		DECLARE_EVENT_TABLE()

		void GetOverlap(wxCommandEvent& event);
		float Cal_SwingCharacteristics() ;
		void GetOverLapCalculate();
		void GetSwingCalculationInputs();
		float *mBucketLength,*mDredgeAreaLength,*mBoomLength ;
		friend class FormInputs;
		
	
};
#endif