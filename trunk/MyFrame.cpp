#include <iostream>
#include "MyFrame.h"


BEGIN_EVENT_TABLE( MyFrame, wxFrame )
	EVT_BUTTON( 0, OnSubmit ) 
	EVT_BUTTON( 1, OnRefresh ) 
END_EVENT_TABLE()


MyFrame:: MyFrame( const wxString& lTitle )
		: mNotebook( NULL ),
		  mDataPanelTab( NULL ),
		  mResultsPanelTab( NULL ),
		  mButtonPanel( NULL ), 
		  mSubmitButton( NULL ), 
		  mRefreshButton( NULL ), 

		  wxFrame( NULL, wxID_ANY, lTitle, wxDefaultPosition, wxSize(500,700), wxDEFAULT_FRAME_STYLE, wxString(_T("Frame")) )
{

	/*AddPageIndexes() ;
	AddIndexOneSubpages() ;
	AddIndexTwoSubpages() ;

	IndexOne_MachinePage() ;
	IndexOne_BucketPage() ;
	IndexOne_DredgeAreaPage() ;

	IndexTwo_SwingCharacteristicsPage() ;
	IndexTwo_LateralBucketPlacementPage() ;
	IndexTwo_BucketRowsPage() ;*/

	AddButtons() ;

}

void
MyFrame :: AddPageIndexes()
{

	mNotebook = new wxNotebook( this, -1, wxDefaultPosition, wxSize(500,500),wxNB_FIXEDWIDTH, _T("Notebook") ) ;
	mDataPanelTab = new wxPanel( mNotebook, wxID_ANY ) ;
	mResultsPanelTab = new wxPanel( mNotebook, wxID_ANY ) ;
	mNotebook->AddPage( mDataPanelTab, _T(" Data "),true, 0 ) ;
	mNotebook->AddPage( mResultsPanelTab, _T(" Results " ), false, 1 ) ;

}

void
MyFrame :: AddIndexOneSubpages()
{
}

void
MyFrame :: AddIndexTwoSubpages()
{
}

void
MyFrame :: IndexOne_BucketPage()
{
	/*
		std::cout <<"\n\n Enter Bucket Data \n " ;
		std::cout <<"-------------------\n" ;

		std::cout <<" \t Bucket Width:  " ; 
		std::cin >> mBucketWidth ;
		std::cout <<" \t Bucket Length:  " ; 
		std::cin >> mBucketLength ;
		std::cout <<" \t Depth of Penetration:  " ; 
		std::cin >> mPenetrationDepth ;
	*/
}

void
MyFrame :: IndexOne_DredgeAreaPage()
{
	/*
	std::cout <<"\n\n Enter Dredge Area Data \n " ;
	std::cout <<"----------------------------\n" ;
	std::cout <<" \t Area Width:   " ; 
	std::cin >> mDredgeWidth ;
	std::cout <<" \t Area Length:  " ; 
	std::cin >> mDredgeLength ;
	std::cout <<" \t Lateral Bucket Overlap at the Centre Line:  " ; 
	std::cin >> mLateralOverlap ;
	std::cout <<" \t Longitudinal Bucket Over
	*/
}

void
MyFrame :: IndexOne_MachinePage()
{
	/*
	std::cout <<"\n\n Enter Dredging Machine Data \n" ;
	std::cout <<" ------------------------------- \n" ;

	std::cout <<"\t Boom Length:  " ;
	std::cin >> mBoomLength ;
	std::cout <<"\t Maximum Dredging Width:  " ;
	std::cin >> mMaxDredgeWidth ;
	std::cout <<"\t Minimum Dredge Reach:  " ;
	std::cin >> mMinDredgeReach ;
	std::cout <<"\t Maximum Dredge Reach:  " ;
	std::cin >> mMaxDredgeReach ;
	*/
}

void
MyFrame :: IndexTwo_SwingCharacteristicsPage()
{
}

void
MyFrame :: IndexTwo_LateralBucketPlacementPage()
{
}

void
MyFrame :: IndexTwo_BucketRowsPage()
{
}


void
MyFrame :: AddButtons()
{

		mButtonPanel   = new wxPanel( this, wxID_ANY, wxPoint(0,500), wxSize(500,200), wxTAB_TRAVERSAL, wxString(_T("Panel")) ) ;
		mSubmitButton  = new wxButton( mButtonPanel, 0, _T(" Submit "), wxPoint(100,600), wxDefaultSize ) ;
		mRefreshButton = new wxButton( mButtonPanel, 1, _T(" Refresh"), wxPoint(300,600), wxDefaultSize ) ;	

}


void
MyFrame :: Calculate_SwingCharacteristics()
{
	/*
	mTotalDredgeSwingAngle = 2 * asin( mDredgeLength / (2*GetBoomLength()) );
	mSwingArcLength = mDredgeLength / mTotalDredgeSwingAngle ;

	std::cout <<" \n The total dredge swing angle:\t " << mTotalDredgeSwingAngle ;
	std::cout <<" \n Swing Arc Length:\t " << mSwingArcLength <<"\n\n" ;
	*/
}

void
MyFrame :: Calculate_LateralBucketPlacements()
{
	/*
	float lBucketLength( GetBucketLength() ) ;
	int lnumCenterJustified, lnumSideJustified ;
	float lCenterJustified, lSideJustified ;


	lnumCenterJustified = (	2* (  (mSwingArcLength - lBucketLength)/
								  (2* (lBucketLength - mLateralOverlap) )
							   ) + 1 
						  ) + 1 ;

	lnumSideJustified = (  (mSwingArcLength - mLateralOverlap)/
						   (lBucketLength - mLateralOverlap)
					    ) + 1 ;

	lCenterJustified = lBucketLength - ( (mSwingArcLength - lBucketLength)/
										 (lnumCenterJustified - 1)
									   ) ;

	lSideJustified = ( (lnumSideJustified*lBucketLength) - (lBucketLength + lnumSideJustified) /
		               (lnumSideJustified - 2)
					 ) ;


	std::cout <<" Number of Buckets in a swing width given a fixed overlap .... " << std::endl ;
	std::cout <<" \t\t i)   For center justified bucket placement:  "<< lnumCenterJustified << std::endl ;
	std::cout <<" \t\t ii)  For side justified ( left or right ) bucket placement:  "<< lnumSideJustified << std::endl ;
	std::cout <<" \n\t The bucket overlap necessary for the number of bucket placements in a swing width to exactly fit the dredging width ..." <<std::endl ;
	std::cout <<" \t\t i)   For center justified bucket placement:  "<< lCenterJustified << std::endl ;
	std::cout <<" \t\t ii)  For side justified ( left or right ) bucket placement:  "<< lSideJustified <<std::endl ;
	*/
}

void
MyFrame :: Calculate_BucketRows()
{
	/*
	float lBucketWidth( GetBucketWidth() ) ;
	float lnumBucketRows, lLongitudinalOverlap ;

	lnumBucketRows = (  mDredgeWidth / 
				       ( lBucketWidth - mLongitudinalOverlap ) 
					 ) + 1 ;

	lLongitudinalOverlap = lBucketWidth - ( mDredgeLength / lnumBucketRows ) + 1 ;

	std::cout << " \n\nNumber of bucket rows:\t" << lnumBucketRows <<std::endl ;
	std::cout << " Longitudinal bucket overlap to fix bucket exactly:\t" << lLongitudinalOverlap <<std::endl ;
	*/
}

void
MyFrame :: OnSubmit( wxCommandEvent& SubmitEvent )
{
	std::cout <<" Submit button clicked " << std::endl ;
}

void
MyFrame :: OnRefresh( wxCommandEvent& RefreshEvent )
{
	std::cout <<" Refresh button clicked" << std::endl ;
}
