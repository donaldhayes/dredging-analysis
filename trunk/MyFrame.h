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
		void AddIndexOneSubpages() ;
		void AddIndexTwoSubpages() ;

		void IndexOne_MachinePage() ;
		void IndexOne_BucketPage() ;
		void IndexOne_DredgeAreaPage() ;

		void IndexTwo_SwingCharacteristicsPage() ;
		void IndexTwo_LateralBucketPlacementPage() ;
		void IndexTwo_BucketRowsPage() ;

		void AddButtons() ;

		void Calculate_SwingCharacteristics() ;
		void Calculate_LateralBucketPlacements() ;
		void Calculate_BucketRows() ;

		void OnSubmit( wxCommandEvent& ) ;
		void OnRefresh( wxCommandEvent& ) ;

	private:

		wxPanel *mButtonPanel ;
		wxPanel *mDataPanelTab, *mResultsPanelTab ;
		wxNotebook *mNotebook ;
		wxButton *mSubmitButton, *mRefreshButton ;

	DECLARE_EVENT_TABLE()
};


#endif