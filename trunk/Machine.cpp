
#include <iostream>
#include "Machine.h"

Machine:: Machine()
        : mBoomLength( 0.0 ),
		  mMaxDredgeWidth( 0.0 ),
		  mMinDredgeReach( 0.0 ),
		  mMaxDredgeReach( 0.0 )
{
	SetMachineProperties() ;
}

void
Machine:: SetMachineProperties()
{
	std::cout <<"\n\n Enter Dredging Machine Data \n" ;
	std::cout <<" ------------------------------- \n" ;

	std::cout <<"\t Boom Length:  " ;
	std::cin >> mBoomLength ;
	std::cout <<"\t Maximum Dredging Width:  " ;
	std::cin >> mMaxDredgeWidth ;
	std::cout <<"\t Minimum Dredge Reach:  " ;
	std::cin >> mMinDredgeReach ;
	std::cout <<"\t Maximum Dredge Reach:  " ;
	std::cin >> mMaxDredgeReach ;
}

const float
Machine:: GetBoomLength() const
{
	return mBoomLength ;
}

/*
void
Machine:: SetAngularDisplacement( float &AngularDisplacement )
{
	mAngularDisplacement = AngularDisplacement ;
}

float
Machine:: GetAngularDisplacement() const
{
	return mAngularDisplacement ;
}

void
Machine:: VolumeCalculation()
{
	std:: cout <<" Calculation of Volume " << std::endl ;
}

void
Machine:: SetHookToSeabedHeight( int& HookToSeabedHeight )
{
	mHookToSeabedHeight = HookToSeabedHeight ;
}
*/
