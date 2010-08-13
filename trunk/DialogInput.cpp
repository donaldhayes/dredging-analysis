#include "DialogInput.h"

BEGIN_EVENT_TABLE(DialogInput, wxDialog )
	EVT_CHOICE(wxID_LATERAL_BUCKET,DialogInput::GetOverlap)
	EVT_RADIOBOX(wxID_RADIO,DialogInput::GetOverlap)
END_EVENT_TABLE()

DialogInput::DialogInput()
			:wxDialog(NULL,wxID_ANY,_("Optimize Bucket"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE,_("dialogbox"))
{
	AddOptimizeDialog();
}

void DialogInput ::AddOptimizeDialog()
{	
	wxBoxSizer *mTopSizer = new wxBoxSizer( wxVERTICAL );
    wxBoxSizer *mRadioSizer = new wxBoxSizer( wxVERTICAL );

	

	wxStaticBox* mValueEntryBox = new wxStaticBox(this,wxID_STATIC,_("Enter Values"),wxDefaultPosition,wxDefaultSize,0);
	wxBoxSizer* styleSizer1 = new wxStaticBoxSizer( mValueEntryBox, wxHORIZONTAL );
	mRadioSizer->Add(styleSizer1, 0, wxGROW|wxALL, 5);
	wxBoxSizer* itemSizer3 = new wxBoxSizer( wxHORIZONTAL );
	//wxBoxSizer* styleSizer2 = new wxStaticBoxSizer( mValueEntryBox, wxHORIZONTAL );
	//mRadioSizer->Add(styleSizer2, 0, wxGROW|wxALL, 5);
	//wxBoxSizer* itemSizer4 = new wxBoxSizer( wxHORIZONTAL );
	//itemSizer4->Add(new wxStaticText(this, wxID_STATIC, _("&Lateral Buckets:")), 0,wxTOP|wxADJUST_MINSIZE, 5);
	
    itemSizer3->Add(5, 5, 1, wxALL|wxRIGHT, 0);
	mBucket = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("Text Box To Enter Dredge Area Lateral Overlap") ) ;
	itemSizer3->Add(mBucket,0,wxALL,5);

	mDredgeArea = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("Text Box To Enter Dredge Area Lateral Overlap") ) ;
	itemSizer3->Add(mDredgeArea,0,wxALL,5);

	mBoom = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("Text Box To Enter Dredge Area Lateral Overlap") ) ;
	itemSizer3->Add(mBoom,0,wxALL,5);
	styleSizer1->Add(itemSizer3, 0, wxGROW|wxALL, 5);
	//styleSizer1->Add(itemSizer4, 0, wxGROW|wxALL, 5);


	wxString *mNumber_Buckets= new wxString[3];
    mNumber_Buckets[0] = _("1");
	mNumber_Buckets[1] = _("2");
	mNumber_Buckets[2] = _("3");
    wxStaticBox* mNumBucketsBox = new wxStaticBox(this,wxID_STATIC,_("Number of Buckets"),wxDefaultPosition,wxDefaultSize,0);

    wxBoxSizer* styleSizer = new wxStaticBoxSizer( mNumBucketsBox, wxVERTICAL );
    mRadioSizer->Add(styleSizer, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemSizer2 = new wxBoxSizer( wxVERTICAL );

    mLateralChoice = new wxChoice(this, wxID_LATERAL_BUCKET, wxDefaultPosition, wxDefaultSize,5, mNumber_Buckets,0);
	mLongitudinalChoice = new wxChoice(this, wxID_LONGITUDINAL_BUCKET , wxDefaultPosition, wxDefaultSize,5, mNumber_Buckets,0);
	mLateralOverlap = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("Text Box To Enter Dredge Area Lateral Overlap") ) ;
	
    itemSizer2->Add(new wxStaticText(this, wxID_STATIC, _("&Lateral Buckets:")), 0,wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);
	
    itemSizer2->Add(5, 5, 1, wxALL|wxRIGHT, 0);
    itemSizer2->Add(mLateralChoice, 0, wxALL|wxLEFT, 5);
	itemSizer2->Add(mLateralOverlap,0,wxALL,5);
	itemSizer2->Add(new wxStaticText(this, wxID_STATIC, _("&Longitudinal Buckets:")), 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);
	mLongitudinalOverlap = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("Text Box To Enter Dredge Area Longitudinal Overlap") ) ;
	itemSizer2->Add(mLongitudinalChoice, 0, wxALL|wxLEFT, 5);
	itemSizer2->Add(mLongitudinalOverlap,0,wxALL,5);

	wxString mJustificationChoices[2];
    mJustificationChoices[0] = _("&Center Justified");
    mJustificationChoices[1] = _("&Side Justified");

	mCenterSideRadio = new wxRadioBox(this, wxID_RADIO, _("Type of Justification"),wxDefaultPosition, wxDefaultSize, 2, mJustificationChoices);
    mRadioSizer->Add(mCenterSideRadio, 0, wxGROW|wxALL, 5);
	//mCenterSideRadio->SetSelection(1);
	
	styleSizer->Add(itemSizer2, 0, wxGROW|wxALL, 5);
	
	mTopSizer->Add( mRadioSizer, 1, wxGROW|wxALIGN_CENTRE|wxALL, 5 );
    mTopSizer->AddSpacer(5);
	this->SetSizer(mTopSizer);
	this->SetAutoLayout(true);
	
	wxButton *lOk = new wxButton(this,wxID_OK,_T("OK"),wxPoint(300,350),wxDefaultSize,0);
}


float DialogInput :: Cal_SwingCharacteristics()
{
	float lBoomLength = *mBoomLength;
	float lDredgeAreaLength = *mDredgeAreaLength;
	float lTotalDredgeSwingAngle = 0 ;
	float llSwingArcLength = 0;
	
	lTotalDredgeSwingAngle = 2 * asin( lDredgeAreaLength / (2*lBoomLength) );
	llSwingArcLength = lDredgeAreaLength / lTotalDredgeSwingAngle ;
	
	return 	llSwingArcLength;

}


void DialogInput::GetOverlap(wxCommandEvent& WXUNUSED(event))
{
	
	GetOverLapCalculate();

}

void DialogInput::GetOverLapCalculate()
{
	wxString lString,lLateralString,lLateralOverlap,lLongitudunalString,lLongitudinalOverlap;
	int lRadioSelection;
	float lBucketLength = *mBucketLength;
	float lLateralChoiceSelection,lCenterJustify,lSideJustify;
	float lSwingArcLength = Cal_SwingCharacteristics() ;
	
	
	lString = mFormInput->ConvertFloatToWXString((*mBoomLength));
	mBoom->ChangeValue(lString);
	lString = mFormInput->ConvertFloatToWXString((*mBucketLength));
	mBucket->ChangeValue(lString);
	lString = mFormInput->ConvertFloatToWXString((*mDredgeAreaLength));
	mDredgeArea->ChangeValue(lString);
	lLateralString = mLateralChoice->GetStringSelection();
	lLateralChoiceSelection = mFormInput->ConvertWXStringToFloat(lLateralString );
	lRadioSelection = mCenterSideRadio->GetSelection();
	
	if(lRadioSelection == 0)
	{
		lCenterJustify = lBucketLength - ((lSwingArcLength - lBucketLength)/
										 (lLateralChoiceSelection - 1)) ;
		lLateralOverlap = mFormInput->ConvertFloatToWXString( lCenterJustify );
		mLateralOverlap->ChangeValue(lLateralOverlap);

	}
	else 
	{
		lSideJustify = (( lLateralChoiceSelection* lBucketLength) - (lBucketLength + lLateralChoiceSelection) /
		               (lLateralChoiceSelection - 2));
		
		lLateralOverlap = mFormInput->ConvertFloatToWXString( lSideJustify );
		mLateralOverlap->ChangeValue(lLateralOverlap);
	}

}
