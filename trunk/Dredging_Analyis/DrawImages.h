#ifndef DRAW_IMAGES_H
#define DRAW_IMAGES_H

	#include <wx/wx.h>
	#include <wx/notebook.h>
	#include <wx/mediactrl.h>
	#include <wx/combobox.h>
	#include <wx/textctrl.h>
	
	#include <string>

	enum
	{
		OUTER_NOTEBOOK = 100, 
		INNER_NOTEBOOK, 
		FRAME_PANEL, 
		NB_SPORTS_PANEL,
		NB_INDOOR_PANEL,
		NB_OUTDOOR_PANEL,
		MEDIA_PANEL,
		MEDIA_PLAYER,
		INDOOR_SPORTS,
		OUTDOOR_SPORTS,
		SPORTS,
		TEXT_CTRL_1
	};
	
	class BottomPanel ;

	class DrawImages : public wxPanel
	{
		public:

			DrawImages( wxFrame* aParent, wxString afile, wxBitmapType aformat) ;
			void paintEvent( wxPaintEvent & evt );
			void paintNow();
			void render( wxDC& dc );

			void addSportsNotebook() ;
			void addIndoorSportsNotebook() ;
			void addOutdoorSportsNotebook() ;

			void indoorImages( wxNotebookEvent& eve ) ;
			void helpFunction( wxNotebookEvent& eve ) ;

			void playVideoFile( wxCommandEvent& eve ) ;
			bool isAlphaNumeric( std::string aReceivedString ) ;
			void enteredWXString( wxCommandEvent& eve ) ;

			void resetGlobalValue( wxCommandEvent& eve ) ;
			void drawHelper() ;

			~DrawImages() ;

		private:
			
			wxImage mImage, mImage1 ;
			wxString mFile, mPaintEventCallCount ;

			static int mCount ;

			wxNotebook		*mSports, *mIndoor_Sports, *mOutdoor_Sports ;
			wxPanel			*mFrame_Panel ;
			wxPanel			*mSports_Panel, *mIndoor_Sports_Panel, *mOutdoor_Sports_Panel ;
			wxPanel			*mTable_Tennis_Panel, *mChess_Panel, *mBasket_Ball_Panel, *mCricket_Panel;
			wxPanel			*mOutDoor_Sports, *mInDoor_Sports, *mTable_Tennis, *mChess, *mBasket_Ball, *mCricket ;
			
			wxPanel			*mMedia_Panel ;
			wxMediaCtrl		*mMediaPlayer ;
			wxArrayString	mVedioLabel ;

			wxComboBox		*mVedioSelection ;

			wxTextCtrl		*mTextBox1 ;

			wxStaticText	*mStaticText ;

		friend class BottomPanel ;

		DECLARE_EVENT_TABLE()
	} ;

#endif