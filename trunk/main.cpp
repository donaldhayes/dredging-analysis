#include <conio.h>
#include <iostream>

#include "MyClass.h"

int main()
{
	int Continue( 1 ) ;
	
	do
	{
		MyClass* Obj = new MyClass() ;
		delete Obj ;

		std::cout <<" Key In 1 for another set of calculations and 0 to exit...\t" ;
		std::cin >> Continue ;

	}while( Continue == 1) ;
	return 0 ;

}


