/**
*		@file	main.cpp
*		@author	V.Mahesh Babu	<mxv4013@louisiana.edu>
*
*		@date	9/9/2010
*		@ingroup	Sources
*/

#include <iostream>
#include <conio.h>
#include "Fact.h"

/**
		Program execution starts here.
		@param	argc	Arguements count.
		@param	argv	Arguements value.

		@return void.
*/

int main( int argc, const char* argv )
{
	Factorial*	factObject = new Factorial() ;
	
	factObject -> setNumber( 5 ) ;
	std::cout << "Factorial of the number is:\t" << factObject -> getResult() ;

	///	Making the console to quit on any keyboard character input.
	_getch() ;

	return 0 ;
}
