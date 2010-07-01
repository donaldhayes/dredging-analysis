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

	AddPageIndexes() ;
	AddButtons() ;

	AddDataPageContent() ;

}

void
MyFrame :: AddPageIndexes()
{

	mNotebookPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 500,500 ), wxDEFAULT, _T(" Notebook Panel") );
	mNotebook = new wxNotebook( mNotebookPanel, -1, wxDefaultPosition, wxSize(500,500),wxNB_FIXEDWIDTH, _T("Notebook") ) ;
	mDataPanelTab = new wxPanel( mNotebook, wxID_ANY ) ;
	mResultsPanelTab = new wxPanel( mNotebook, wxID_ANY ) ;
	mNotebook->AddPage( mDataPanelTab, _T(" Data "),true, 1 ) ;
	mNotebook->AddPage( mResultsPanelTab, _T(" Results " ), false, 2 ) ;
	
}

void
MyFrame :: AddButtons()
{

	mButtonPanel   = new wxPanel( this, wxID_ANY, wxPoint(0,500), wxSize(500,200), wxTAB_TRAVERSAL, wxString(_T("Panel")) ) ;
	mSubmitButton  = new wxButton( mButtonPanel, 0, _T(" Submit "), wxPoint(100,100), wxDefaultSize ) ;
	mRefreshButton = new wxButton( mButtonPanel, 1, _T(" Refresh"), wxPoint(300,100), wxDefaultSize ) ;	

}

void
MyFrame :: AddDataPageContent()
{
	
	DredgeAreaData() ;
	MachineData() ;
	BucketData() ;

}

void
MyFrame :: DredgeAreaData()
{
	
	mDredgeAreaData						= new wxStaticBox ( mDataPanelTab, wxID_ANY, _T("&Dredge Area"), wxDefaultPosition, wxSize(475,170), 0, _T("Dredge Area Data Boundary") ) ;
	
	mST_DredgeArea_Length				= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Length"), wxPoint(50,50), wxDefaultSize, 0, _T("Static Dredge Area Length Label") ) ;
	mST_DredgeArea_Width				= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Width"),  wxPoint(50,120),wxDefaultSize, 0, _T("Static Dredge Area Width Label" ) ) ;
	mST_DredgeArea_LateralOverlap		= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Lateral Overlap"), wxPoint(250,50), wxDefaultSize, 0, _T("Static Dredge Area Lateral Overlap Label") );
	mST_DredgeArea_LongitudinalOverlap	= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Longitudinal Overlap"), wxPoint(250,120), wxDefaultSize, 0, _T("Static Dredge Area Longitudinal Overlap Label") );

	mDredgeArea_Length					= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(100,50), wxDefaultSize, 0, wxDefaultValidator, _T("Text Box To Enter Dredge Area Length") ) ;
	mDredgeArea_Width					= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(100,120), wxDefaultSize, 0, wxDefaultValidator, _T("Text Box To Enter Dredge Area Width") ) ;
	mDredgeArea_LateralOverlap			= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(350,50), wxDefaultSize, 0, wxDefaultValidator, _T("Text Box To Enter Dredge Area Lateral Overlap") ) ;
	mDredgeArea_LongitudinalOverlap		= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(350,120), wxDefaultSize, 0, wxDefaultValidator, _T("Text Box To Enter Dredge Area Longitudinal Overlap") ) ;

}

void
MyFrame :: MachineData()
{
	
	mMachineData						= new wxStaticBox ( mDataPanelTab, wxID_ANY, _T("&Machine"), wxPoint(0,175), wxSize(475,170), 0, _T("Machine Data Boundary") ) ;

	mST_Machine_BoomLength				= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Boom Length"), wxPoint(50,230), wxDefaultSize, 0, _T("Machine Boom Length Static Label") );
	mST_Machine_MaxDredgeWidth			= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Max. Dredge Width"), wxPoint(50,300), wxDefaultSize, 0, _T("Machine Max. Dredge Width Static Label") );
	mST_Machine_MinDredgeReach			= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Min. Dredge Reach"), wxPoint(250,230), wxDefaultSize, 0, _T("Machine Min. Dredge Reach Static Label") );
	mST_Machine_MaxDredgeReach			= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Max. Dredge Reach"), wxPoint(250,300), wxDefaultSize, 0, _T("Machine Max. Dredge Reach Static Label") );

	mMachine_BoomLength					= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(150,228), wxSize(80,23), 0, wxDefaultValidator, _T("Text Box To Enter Machine Boom Length") ) ;
	mMachine_MaxDredgeWidth				= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(150,298), wxSize(80,23), 0, wxDefaultValidator, _T("Text Box To Enter Max. Machine Width") ) ;
	mMachine_MinDredgeReach				= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(350,228), wxSize(80,23), 0, wxDefaultValidator, _T("Text Box To Enter Min. Dredge Reach") ) ;
	mMachine_MaxDredgeReach				= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(350,298), wxSize(80,23), 0, wxDefaultValidator, _T("Text Box To Enter Max. Dredge Reach") ) ;

}

void
MyFrame :: BucketData()
{
	
	mBucketData							= new wxStaticBox ( mDataPanelTab, wxID_ANY, _T("&Bucket"), wxPoint(0,350), wxSize(475,120), 0, _T("Bucket Data Boundary") ) ;

	mST_Bucket_Length					= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Length"), wxPoint(50,405), wxDefaultSize, 0, _T("Bucket Length Static Label") );
	mST_Bucket_Width					= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Width"), wxPoint(180,405), wxDefaultSize, 0, _T("Bucket Width Static Label") );
	mST_Bucket_PenetrationDepth			= new wxStaticText( mDataPanelTab, wxID_ANY, _T("Penetration Depth"), wxPoint(300,405), wxDefaultSize, 0, _T("Bucket Penetration Depth Static Label") );

	mBucket_Length						= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(100,403), wxSize(50,23), 0, wxDefaultValidator, _T("Text Box To Enter Bucket Length") ) ;
	mBucket_Width						= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(220,403), wxSize(50,23), 0, wxDefaultValidator, _T("Text Box To Enter Bucket Width") ) ;
	mBucket_PenetrationDepth			= new wxTextCtrl( mDataPanelTab, wxID_ANY, wxEmptyString, wxPoint(400,403), wxSize(50,23), 0, wxDefaultValidator, _T("Text Box To Enter Bucket Penetration Depth") ) ;

}


void
MyFrame :: OnSubmit( wxCommandEvent& SubmitEvent )
{
	Calculate_SwingCharacteristics() ;
	Calculate_LateralBucketPlacements() ;
	Calculate_BucketRows() ;
}


void
MyFrame :: OnRefresh( wxCommandEvent& RefreshEvent )
{
	
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

