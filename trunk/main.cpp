#include <conio.h>
#include <cmath>
#include <iostream>

#include "MyClass.h"

int main()
{
	int Continue( 1 ) ;
	std::cout <<"Checking this:\t" <<std::endl ;
	do
	{
		MyClass* Obj = new MyClass() ;
		delete Obj ;

		std::cout <<" Key In 1 for another set of calculations and 0 to exit...\t" ;
		std::cin >> Continue ;

	}while( Continue == 1) ;
	return 0 ;

}


