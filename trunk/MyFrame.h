#ifndef MY_FRAME_H
#define MY_FRAME_H

#include "wx/wx.h"
#include "wx/notebook.h"
#include "wx/gdicmn.h"

class MyFrame : public wxFrame
{
	public:
		
		MyFrame(const wxString& title) ;
		void AddPageIndexes() ;
		void AddButtons() ;
		
		void AddDataPageContent() ;
		void MachineData() ;
		void BucketData() ;
		void DredgeAreaData() ;

	protected:

		wxPanel *mButtonPanel, *mNotebookPanel ;
		wxPanel *mDataPanelTab, *mResultsPanelTab ;
		wxPanel *mFirstChildMachinePanel ;
		wxNotebook *mNotebook, *mFirstChildNotebook ;
		wxButton *mSubmitButton, *mRefreshButton ;

		wxStaticBox *mMachineData, *mBucketData, *mDredgeAreaData ;

		wxStaticText *mST_Machine_BoomLength, *mST_Machine_MaxDredgeWidth, *mST_Machine_MinDredgeReach, *mST_Machine_MaxDredgeReach ;
		wxStaticText *mST_Bucket_Width, *mST_Bucket_Length, *mST_Bucket_PenetrationDepth ;
		wxStaticText *mST_DredgeArea_Width, *mST_DredgeArea_Length, *mST_DredgeArea_LateralOverlap, *mST_DredgeArea_LongitudinalOverlap ;

		wxTextCtrl *mMachine_BoomLength, *mMachine_MaxDredgeWidth, *mMachine_MinDredgeReach, *mMachine_MaxDredgeReach ;
		wxTextCtrl *mBucket_Width, *mBucket_Length, *mBucket_PenetrationDepth ;
		wxTextCtrl *mDredgeArea_Width, *mDredgeArea_Length, *mDredgeArea_LateralOverlap, *mDredgeArea_LongitudinalOverlap ;

		int xxxx ;

};


#endif