#include "Bucket.h"
#include <iostream>

Bucket:: Bucket()
	   : mBucketWidth( 0.0 ),
	     mBucketLength( 0.0 ),
		 mPenetrationDepth( 0.0 )		 
{
	SetBucketProperties() ;
}

void
Bucket:: SetBucketProperties()
{
	std::cout <<"\n\n Enter Bucket Data \n " ;
	std::cout <<"-------------------\n" ;

	std::cout <<" \t Bucket Width:  " ; 
	std::cin >> mBucketWidth ;
	std::cout <<" \t Bucket Length:  " ; 
	std::cin >> mBucketLength ;
	std::cout <<" \t Depth of Penetration:  " ; 
	std::cin >> mPenetrationDepth ;
}


/*
void
Bucket:: SetBucketDimensions( int* temp )
{
	mBucketDimensions[0] = *temp ;
	mBucketDimensions[1] = *(temp+1) ;
}
*/
const float
Bucket:: GetBucketLength() const
{
	return mBucketLength ;
}

const float
Bucket:: GetBucketWidth() const
{
	return mBucketWidth ;
}