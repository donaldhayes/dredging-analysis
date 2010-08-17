#include "DialogInput.h"

BEGIN_EVENT_TABLE(DialogInput, wxDialog )
	EVT_CHOICE(wxID_LATERAL_BUCKET,DialogInput::GetLateralOverlap)
	EVT_RADIOBOX(wxID_RADIO,DialogInput::GetLateralLongitudinalOverlap)
	EVT_CHOICE(wxID_LONGITUDINAL_BUCKET,DialogInput::GetLongitudinalOverlap)
END_EVENT_TABLE()

DialogInput::DialogInput(int lLateralBucketNumber,int lLongBucketNumber)
			:wxDialog(NULL,wxID_ANY,_("Optimal Overlap"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE,_("dialogbox"))
{
	AddOptimizeDialog(lLateralBucketNumber,lLongBucketNumber);
}

void DialogInput ::AddOptimizeDialog(int lLateralBucketNumber,int lLongBucketNumber)
{	
	int i=0,j=lLateralBucketNumber,k=16,l =lLongBucketNumber  ;
	wxString *mNumber_Buckets= new wxString[k];	
	wxString *mNumber_BucketsLong= new wxString[k];	

	for( i=0;i<k;i++)
	{
		 mNumber_Buckets[i] =  wxString::Format(wxT("%i"),j);
		j++;
	}	
	i = 0;
	for( i=0;i<k;i++)
	{
		 mNumber_BucketsLong[i] =  wxString::Format(wxT("%i"),l);
		l++;
	}	

	wxBoxSizer *mTopSizer = new wxBoxSizer( wxVERTICAL );
    wxBoxSizer *mRadioSizer = new wxBoxSizer( wxVERTICAL );

	wxStaticBox* mNumLatBucketsBox = new wxStaticBox(this,wxID_STATIC,_("Optimal Lateral Overlap"),wxDefaultPosition,wxDefaultSize,0);
	wxBoxSizer* LateralSizer = new wxStaticBoxSizer( mNumLatBucketsBox, wxVERTICAL );
    mRadioSizer->Add(LateralSizer, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemSizer2 = new wxBoxSizer( wxHORIZONTAL);
	itemSizer2->Add(new wxStaticText(this, wxID_STATIC, _("&Lateral Buckets:    ")), 0,wxALIGN_TOP, 5);
    mLateralChoice = new wxChoice(this, wxID_LATERAL_BUCKET, wxDefaultPosition, wxDefaultSize,15, mNumber_Buckets,0);
	itemSizer2->Add(mLateralChoice, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP, 5);
	wxBoxSizer* itemSizer3 = new wxBoxSizer( wxHORIZONTAL);
	mLateralOverlap = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("Text Box To Enter Dredge Area Lateral Overlap") ) ;
	itemSizer3->Add(new wxStaticText(this, wxID_STATIC, _("&Lateral Overlap:   ")), 0,wxALIGN_TOP, 5);
	itemSizer3->Add(mLateralOverlap,0,wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP ,5);
    LateralSizer->Add(itemSizer2, 0, wxGROW|wxALL, 5);
	LateralSizer->Add(itemSizer3, 0, wxGROW|wxALL, 5);
	
    
	wxStaticBox* mNumLonBucketsBox = new wxStaticBox(this,wxID_STATIC,_("Optimal Longitudinal Overlap"),wxDefaultPosition,wxDefaultSize,0);
    wxBoxSizer* LongitudinalSizer = new wxStaticBoxSizer( mNumLonBucketsBox, wxVERTICAL );
	mRadioSizer->Add(LongitudinalSizer, 0, wxGROW|wxALL, 5);

	wxBoxSizer* itemSizer4 = new wxBoxSizer( wxHORIZONTAL );
	itemSizer4->Add(new wxStaticText(this, wxID_STATIC, _("&Longitudinal Buckets:   ")), 0, wxALIGN_TOP, 5);
	mLongitudinalChoice = new wxChoice(this, wxID_LONGITUDINAL_BUCKET , wxDefaultPosition, wxDefaultSize,15, mNumber_BucketsLong,0);
	itemSizer4->Add(mLongitudinalChoice, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP, 5);
	wxBoxSizer* itemSizer5 = new wxBoxSizer( wxHORIZONTAL );
	itemSizer5->Add(new wxStaticText(this, wxID_STATIC, _("&Longitudinal Overlap:   ")), 0,wxALIGN_TOP, 5);
	mLongitudinalOverlap = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("Text Box To Enter Dredge Area Longitudinal Overlap") ) ;
	itemSizer5->Add(mLongitudinalOverlap,0,wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP,5);
	LongitudinalSizer->Add(itemSizer4, 0, wxGROW|wxALL, 5);
	LongitudinalSizer->Add(itemSizer5, 0, wxGROW|wxALL, 5);

	wxString mJustificationChoices[2];
    mJustificationChoices[0] = _("&Center Justified");
    mJustificationChoices[1] = _("&Side Justified");

	mCenterSideRadio = new wxRadioBox(this, wxID_RADIO, _("Type of Justification"),wxDefaultPosition, wxDefaultSize, 2, mJustificationChoices);
    mRadioSizer->Add(mCenterSideRadio, 0, wxGROW|wxALL, 5);
	mCenterSideRadio->SetSelection(0);
	
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


void DialogInput::GetLateralLongitudinalOverlap(wxCommandEvent& WXUNUSED(event))
{
	
	LateralLongitudinalOverLapCalculate();

}

void DialogInput::LateralLongitudinalOverLapCalculate()
{
	LateralOverLapCalculate();
	LongitudinalOverLapCalculate();
}


void DialogInput::LateralOverLapCalculate()
{
	int lRadioSelection;
	lRadioSelection = mCenterSideRadio->GetSelection();
	wxString lLateralString,lLateralOverlap;
	float lBucketLength = *mBucketLength,lBucketWidth = *mBucketWidth,lLateralChoiceSelection =0,lCenterJustify=0,lSideJustify=0;
	float lSwingArcLength = Cal_SwingCharacteristics() ;
	lLateralString = mLateralChoice->GetStringSelection();
	lLateralChoiceSelection = mFormInput->ConvertWXStringToFloat(lLateralString );
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

void DialogInput::GetLateralOverlap(wxCommandEvent& WXUNUSED(event))
{
	LateralOverLapCalculate();
}

void DialogInput::LongitudinalOverLapCalculate()
{
	int lRadioSelection;
	wxString lString,lLongitudunalString,lLongitudinalOverlap;
	float lBucketLength = *mBucketLength,lBucketWidth = *mBucketWidth;
	lRadioSelection = mCenterSideRadio->GetSelection();
	float lCenterJustify,lSideJustify,lLongitudinalChoiceSelection; ;
	lLongitudunalString = mLongitudinalChoice->GetStringSelection();
	lLongitudinalChoiceSelection = mFormInput->ConvertWXStringToFloat(lLongitudunalString );
	if(lRadioSelection == 0)
	{
		lCenterJustify = lBucketWidth - ( (*mDredgeAreaLength) / lLongitudinalChoiceSelection ) + 1 ;
		lLongitudinalOverlap = mFormInput->ConvertFloatToWXString( lCenterJustify );
		mLongitudinalOverlap->ChangeValue(lLongitudinalOverlap);
	}
	else
	{
		lSideJustify= lBucketWidth - ( (*mDredgeAreaLength) / lLongitudinalChoiceSelection ) + 1 ;
		lLongitudinalOverlap = mFormInput->ConvertFloatToWXString( lSideJustify );
		mLongitudinalOverlap->ChangeValue(lLongitudinalOverlap);
	}


}

void DialogInput::GetLongitudinalOverlap(wxCommandEvent& WXUNUSED(event))
{
	LongitudinalOverLapCalculate();
}
