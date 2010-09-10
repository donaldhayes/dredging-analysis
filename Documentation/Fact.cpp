/**
*		@file	Fact.cpp
*		@author	V.Mahesh Babu	<mxv4013@louisiana.edu>
*		@date	9/9/2010
*
*		@brief	Implementation of the Fact.h.
*		Fact class definitions are implemented here. However, default constructor behaviour is described in class itself.
*		@ingroup	Sources
*/
#include "Fact.h"

/**
		@brief Implementation of setFunction( int aNumber ).
		Arguement input taken is set to the class variable mInputNumber. This function returns void.
*/

void
Factorial	::	setNumber( int aNumber )
{
	mInputNumber = aNumber ;
}

/**
		
		@brief Implentation of the getResult.
		Computes the factorial of the given input.

		@return	Returns the result which is an integer value.

*/

int
Factorial	::	getResult()
{
	
	int lFactResult = 1 ;

	for( int i=1; i <= mInputNumber; i++ )
	{
		lFactResult *= i ;
	}

	return lFactResult ;

}