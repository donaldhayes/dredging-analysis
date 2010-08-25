#include "MyApp.h"


bool
MyApp :: OnInit()
{
	
	if( !wxApp::OnInit() )
		return false ;

	frame = new FormInputs() ;
	frame->Show( true ) ;

	return true ;
}
