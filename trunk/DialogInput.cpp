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

	wxString mJustificationChoices[2];
    mJustificationChoices[0] = _("&Center Justified");
    mJustificationChoices[1] = _("&Side Justified");

	mCenterSideRadio = new wxRadioBox(this, wxID_RADIO, _("Type of Justification"),wxDefaultPosition, wxDefaultSize, 2, mJustificationChoices);
    mRadioSizer->Add(mCenterSideRadio, 0, wxGROW|wxALL, 5);
	mCenterSideRadio->SetSelection(1);

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
	itemSizer2->Add(mLateralOverlap,0,wxALL,5);
    itemSizer2->Add(new wxStaticText(this, wxID_STATIC, _("&Lateral Buckets:")), 0,wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);
	
    itemSizer2->Add(5, 5, 1, wxALL|wxRIGHT, 0);
    itemSizer2->Add(mLateralChoice, 0, wxALL|wxLEFT, 5);
	itemSizer2->Add(new wxStaticText(this, wxID_STATIC, _("&Longitudinal Buckets:")), 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);
	itemSizer2->Add(mLongitudinalChoice, 0, wxALL|wxLEFT, 5);

	mBucket = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("Text Box To Enter Dredge Area Lateral Overlap") ) ;
	itemSizer2->Add(mBucket,0,wxALL,5);

	styleSizer->Add(itemSizer2, 0, wxGROW|wxALL, 5);
	mTopSizer->Add( mRadioSizer, 1, wxGROW|wxALIGN_CENTRE|wxALL, 5 );
    mTopSizer->AddSpacer(5);
	this->SetSizer(mTopSizer);
	this->SetAutoLayout(true);
	
	wxButton *lOk = new wxButton(this,wxID_OK,_T("OK"),wxPoint(300,300),wxDefaultSize,0);
}


float DialogInput :: Cal_SwingCharacteristics()
{
	float lTotalDredgeSwingAngle = 0 ;
	float lSwingArcLength ;
	
	lTotalDredgeSwingAngle = 2 * asin( mFormInput->mDredgeAreaLength / (2*mFormInput->mBoomLength) );
	lSwingArcLength = mFormInput->mDredgeAreaLength / lTotalDredgeSwingAngle ;

return 	lSwingArcLength;

}

void DialogInput::GetOverlap(wxCommandEvent& WXUNUSED(event))
{
	mFormInput = new FormInputs();
	int lRadioSelection;
	float lCenterJustify,lSideJustify;
	
	wxString lLateralString,lLateralOverlap,lBucket;
	float lLateralChoiceSelection;
	mFormInput->GetDredgeAreaData();
	mFormInput->GetMachineData();
	mFormInput->GetBucketData();
	lBucket = mFormInput->ConvertFloatToWXString( mFormInput->mBucket_Length );
	mBucket->ChangeValue(lBucket);
	float lSwingArcLength = Cal_SwingCharacteristics() ;
	lLateralString = mLateralChoice->GetStringSelection();
	lLateralChoiceSelection = mFormInput->ConvertWXStringToFloat(lLateralString );
	lRadioSelection = mCenterSideRadio->GetSelection();
	
	if(lRadioSelection == 0)
	{
		lCenterJustify = mFormInput->mBucketLength - ((lSwingArcLength - mFormInput->mBucketLength)/
										 (lLateralChoiceSelection - 1)) ;
		lLateralOverlap = mFormInput->ConvertFloatToWXString( lCenterJustify );
		mLateralOverlap->ChangeValue(lLateralOverlap);

	}
	else 
	{
		lSideJustify = ((lLateralChoiceSelection*mFormInput->mBucketLength) - (mFormInput->mBucketLength + lLateralChoiceSelection) /
		               (lLateralChoiceSelection - 2));
	}

}
