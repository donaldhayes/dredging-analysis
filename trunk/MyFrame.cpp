#include <iostream>
#include "MyFrame.h"
#include "FormInputs.h"

MyFrame:: MyFrame( const wxString& lTitle )
		: mNotebook( NULL ),
		  mDataPanelTab( NULL ),
		  mResultsPanelTab( NULL ),
		  mButtonPanel( NULL ), 
		  mSubmitButton( NULL ), 
		  mRefreshButton( NULL ),
		  mOptimizeButton( NULL),
		  xxxx(90),
		  wxFrame( NULL, wxID_ANY, lTitle, wxDefaultPosition, wxSize(500,700), wxDEFAULT_FRAME_STYLE, wxString(_T("Frame")))
{

	AddPageIndexes() ;
	AddButtons() ;

	AddDataPageContent() ;
	AddMediaPlayer();
}

void MyFrame :: AddPageIndexes()
{

	mNotebookPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 500,500 ), wxDEFAULT, _T(" Notebook Panel") );
	mNotebook = new wxNotebook( mNotebookPanel, -1, wxDefaultPosition, wxSize(500,500),wxNB_FIXEDWIDTH, _T("Notebook") ) ;
	mDataPanelTab = new wxPanel( mNotebook, wxID_ANY ) ;
	mResultsPanelTab = new wxPanel( mNotebook, wxID_ANY ) ;
	mMediaPlayerPanel = new wxPanel( mNotebook,wxID_ANY);
	mNotebook->AddPage( mDataPanelTab, _T(" Data "),true, 1 ) ;
	mNotebook->AddPage( mResultsPanelTab, _T(" Results " ), false, 2 ) ;
	mNotebook->AddPage(mMediaPlayerPanel,_T(" MediaPlayer "), false, 3);

}
void MyFrame::AddMediaPlayer()
{
	mMediaPlayer = new wxMediaCtrl();
	wxFlexGridSizer* sizer = new wxFlexGridSizer(2, 1, 0, 0);
	
	mMediaPlayer->Create(mMediaPlayerPanel,wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0,wxMEDIABACKEND_WMP10);
	mMediaPlayerPanel->SetSizer(sizer);
    mMediaPlayerPanel->SetAutoLayout(true);
    sizer->AddGrowableRow(0);
    sizer->AddGrowableCol(0);
	sizer->Add(mMediaPlayer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5);
}

void
MyFrame :: AddButtons()
{

	mButtonPanel       = new wxPanel( this, wxID_ANY, wxPoint(0,500), wxSize(500,200), wxTAB_TRAVERSAL, wxString(_T("Panel")) ) ;
	mSubmitButton      = new wxButton( mButtonPanel, 0, _T(" Submit "), wxPoint(100,100), wxDefaultSize ) ;
	mRefreshButton     = new wxButton( mButtonPanel, 1, _T(" Refresh"), wxPoint(300,100), wxDefaultSize ) ;	
	//mMediaPlayerButton = new wxButton(mButtonPanel,wxID_MEDIA,wxT("File"), wxPoint(200,100),wxDefaultSize);
	mOptimizeButton   = new wxButton(mButtonPanel,wxID_OPTIMIZE,_("Optimize Overlap"),wxPoint(200,50),wxDefaultSize);
	mPlayList= new wxString[3];	
	mPlayList[0] = _("Dredging Video 1");
	mPlayList[1] = _("Dredging Video 2");
	mPlayList[2] = _("Dredging Video 3");
	mMediaText = new wxStaticText ( mButtonPanel, wxID_ANY, _("&SELECT FILE TO PLAY"), wxPoint(25,25), wxDefaultSize, 0, _T("Choose The Play") ) ;
	mMediaSelect = new wxChoice(mButtonPanel,wxID_MEDIACHOICE,wxPoint(25,50),wxDefaultSize,3,mPlayList,0);
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
