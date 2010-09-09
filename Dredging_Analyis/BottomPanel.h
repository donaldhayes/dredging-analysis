#ifndef BOTTOM_PANEL_H
#define BOTTOM_PANEL_H
	
	#include <wx/panel.h>
	#include <wx/stattext.h>
	#include <wx/combobox.h>
	#include <wx/button.h>
	#include <wx/wx.h>

	class BottomPanel : public wxPanel
	{
		public:

			BottomPanel( wxFrame* aParent ) ;

		private:

			wxButton		*mGetResultsButton ;
			wxStaticText	*mBucketTypeStaticText ;
			wxComboBox		*mBucketSelectionComboBox ;
			wxArrayString	mBucketTypes ;

		DECLARE_EVENT_TABLE()
	} ;


#endif