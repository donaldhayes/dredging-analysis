&ltpre name="code" class="c++">

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

&lt/pre>



<link type="text/css" rel="stylesheet" href="css/SyntaxHighlighter.css"></link>
<script language="javascript" src="js/shCore.js"></script>
<script language="javascript" src="js/shBrushCSharp.js"></script>
<script language="javascript" src="js/shBrushXml.js"></script>
<script language="javascript">
<script language="javascript">
window.onload = function () {
    dp.SyntaxHighlighter.ClipboardSwf = '/flash/clipboard.swf';
    dp.SyntaxHighlighter.HighlightAll('code');
}
</script>
</script>