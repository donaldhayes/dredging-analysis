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
	FormInputs *mFormInput;

	DialogInput(int );
	void AddOptimizeDialog(int);
	void GetOverlap(wxCommandEvent& event);
	float Cal_SwingCharacteristics();
	void GetOverLapCalculate();
	void GetSwingCalculationInputs();
	
	enum { wxID_RADIO,wxID_LATERAL_BUCKET ,wxID_LONGITUDINAL_BUCKET };

	wxChoice *mLateralChoice,*mLongitudinalChoice;
	wxRadioBox* mCenterSideRadio;
	wxTextCtrl *mLateralOverlap,*mLongitudinalOverlap,*mBucket,*mDredgeArea,*mBoom;
	float *mBucketLength,*mDredgeAreaLength,*mBoomLength ;
	
	DECLARE_EVENT_TABLE()

	friend class FormInputs;
	
};
#endif