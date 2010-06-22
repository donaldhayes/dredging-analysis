
#include <iostream>
#include "Machine.h"

Machine:: Machine( int LadderLength, float HookToSeabedHeight )
        : mLadderLength( LadderLength ),
		  mHookToSeabedHeight( HookToSeabedHeight )
{
}

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

const int
Machine:: GetHookToSeabedHeight() const
{
	return mHookToSeabedHeight ;
}
