#include "MyApp.h"
#include "FormInputs.h"

bool
MyApp :: OnInit()
{
	if( !wxApp::OnInit() )
		return false ;

	FormInputs* frame = new FormInputs() ;

	frame->Show( true ) ;

	return true ;
}