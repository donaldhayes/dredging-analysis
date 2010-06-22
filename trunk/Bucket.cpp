#include "Bucket.h"

Bucket:: Bucket( std::string Name, int Length, int Width, int Height, int LadderLength, float HookToSeabedHeight )
	   : Machine( LadderLength, HookToSeabedHeight ) ,
	     mBucketName( Name ),	// Cannot initialize arrays using initializer lists
	     mBucketVolume( Length * Width * Height )
{
	mBucketDimensions[0] = Length ;
	mBucketDimensions[1] = Width ;
	mBucketDimensions[2] = Height ;
}

void
Bucket:: SetBucketDimensions( int* temp )
{
	mBucketDimensions[0] = *temp ;
	mBucketDimensions[1] = *(temp+1) ;
}

const int*
Bucket:: GetBucketDimensions() const
{
	return mBucketDimensions ;
}
