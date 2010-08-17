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

	DialogInput(int,int );
	void AddOptimizeDialog(int,int);
	float Cal_SwingCharacteristics();

	void GetLateralLongitudinalOverlap(wxCommandEvent& event);
	void LateralLongitudinalOverLapCalculate();

	void GetLateralOverlap(wxCommandEvent& event);
	
	void LateralOverLapCalculate();

	void GetLongitudinalOverlap(wxCommandEvent& event);
	void LongitudinalOverLapCalculate();

	enum { wxID_RADIO,wxID_LATERAL_BUCKET ,wxID_LONGITUDINAL_BUCKET };

	wxChoice *mLateralChoice,*mLongitudinalChoice;
	wxRadioBox* mCenterSideRadio;
	wxTextCtrl *mLateralOverlap,*mLongitudinalOverlap,*mBucket,*mDredgeArea,*mBoom;
	float *mBucketLength,*mDredgeAreaLength,*mBoomLength,*mBucketWidth ;
	
	DECLARE_EVENT_TABLE()

	//void RadioSelect(wxCommandEvent& event);

	friend class FormInputs;
	
};
#endif