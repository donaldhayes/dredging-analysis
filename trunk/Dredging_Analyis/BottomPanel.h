<pre name="code" class="c++">

#ifndef BOTTOM_PANEL_H
#define BOTTOM_PANEL_H
	
	#include <wx/panel.h>
	#include <wx/stattext.h>
	#include <wx/combobox.h>
	#include <wx/button.h>
	#include <wx/wx.h>

	class DrawImages ;
	class BottomPanel : public wxPanel
	{
		public:

			BottomPanel( wxFrame* aParent ) ;
			void whichImagesToLoad( wxCommandEvent& eve ) ;
			void getResults( wxCommandEvent& eve ) ;
			void setDrawImagesFriendReference( DrawImages	*aReference ) ;

		private:

			wxButton		*mGetResultsButton ;
			wxStaticText	*mBucketTypeStaticText ;
			wxComboBox		*mBucketSelectionComboBox ;
			wxArrayString	mBucketTypes ;

			DrawImages		*mFriendReference ;

		DECLARE_EVENT_TABLE()
	} ;


#endif

</pre>