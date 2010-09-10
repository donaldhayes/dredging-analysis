/**
*		@file	Fact.h
*		@author	V.Mahesh Babu	<mxv4013@louisiana.edu>
*		@brief	Factorial header file.
*				Factorial has the necessary declartions to compute the factorial of a number.
*
*
*		@date	9/9/2010
*		ingroup	Headers
*/

class Factorial
{
	public:
		
		///	Saving the job of a compiler by providing default constructor myself.
		Factorial() {} ;
		
		/**

			@brief Taking user input.
			Function takes an arguement to which the factorial needs to be found out.

			@param	aNumber	Arguement set to a class variable.
			@return	Returns nothing.
		*/
		
		void setNumber( int aNumber ) ;

		/**
			@brief Gives result.
			Makes necessary calculations on the input. Gets the factorial of the number.

			@return Returns the result.
		*/

		int getResult() ;

	private:

		int mInputNumber ;
};