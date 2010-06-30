#include "MyApp.h"
#include "MyFrame.h"

bool
MyApp :: OnInit()
{
	if( !wxApp::OnInit() )
		return false ;

	MyFrame* frame = new MyFrame( _T( "Dredging Analysis") ) ;

	frame->Show( true ) ;

	return true ;
}