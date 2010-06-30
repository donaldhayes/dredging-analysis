#ifndef MY_FRAME_H
#define MY_FRAME_H

#include "wx/wx.h"

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

		void Calculate_SwingCharacteristics() ;
		void Calculate_LateralBucketPlacements() ;
		void Calculate_BucketRows() ;

		void OnSubmit() ;
		void OnRefresh() ;
};


#endif