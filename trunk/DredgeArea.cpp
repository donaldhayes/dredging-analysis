#include "DredgeArea.h"
#include <iostream>
#include <math.h>

DredgeArea:: DredgeArea()
		   : mDredgeLength( 0.0 ),
		     mDredgeWidth ( 0.0 ),
			 mDredgeArea ( 0.0 ),
			 mTotalDredgeSwingAngle( 0.0 ), 
			 mSwingArcLength( 0.0 ),
			 mLateralOverlap( 0.0 ), 
			 mLongitudinalOverlap( 0.0 )
{
	SetDredgeAreaProperties() ;
}

void
DredgeArea:: SetDredgeAreaProperties()
{
	std::cout <<"\n\n Enter Dredge Area Data \n " ;
	std::cout <<"----------------------------\n" ;
	std::cout <<" \t Area Width:   " ; 
	std::cin >> mDredgeWidth ;
	std::cout <<" \t Area Length:  " ; 
	std::cin >> mDredgeLength ;
	std::cout <<" \t Lateral Bucket Overlap at the Centre Line:  " ; 
	std::cin >> mLateralOverlap ;
	std::cout <<" \t Longitudinal Bucket Overlap at the Center Line:  " ; 
	std::cin >> mLongitudinalOverlap ;
}

void
DredgeArea:: SwingCharacteristics()
{
	mTotalDredgeSwingAngle = 2 * asin( mDredgeLength / (2*GetBoomLength()) );
	mSwingArcLength = mDredgeLength / mTotalDredgeSwingAngle ;

	std::cout <<" \n The total dredge swing angle:\t " << mTotalDredgeSwingAngle ;
	std::cout <<" \n Swing Arc Length:\t " << mSwingArcLength <<"\n\n" ;
}

void
DredgeArea:: LateralBucketPlacemnet()
{

	float lBucketLength( GetBucketLength() ) ;
	int lnumCenterJustified, lnumSideJustified ;
	float lCenterJustified, lSideJustified ;


	lnumCenterJustified = (	2* (  (mSwingArcLength - lBucketLength)/
								  (2* (lBucketLength - mLateralOverlap) )
							   ) + 1 
						  ) + 1 ;

	lnumSideJustified = (  (mSwingArcLength - mLateralOverlap)/
						   (lBucketLength - mLateralOverlap)
					    ) + 1 ;

	lCenterJustified = lBucketLength - ( (mSwingArcLength - lBucketLength)/
										 (lnumCenterJustified - 1)
									   ) ;

	lSideJustified = ( (lnumSideJustified*lBucketLength) - (lBucketLength + lnumSideJustified) /
		               (lnumSideJustified - 2)
					 ) ;


	std::cout <<" Number of Buckets in a swing width given a fixed overlap .... " << std::endl ;
	std::cout <<" \t\t i)   For center justified bucket placement:  "<< lnumCenterJustified << std::endl ;
	std::cout <<" \t\t ii)  For side justified ( left or right ) bucket placement:  "<< lnumSideJustified << std::endl ;
	std::cout <<" \n\t The bucket overlap necessary for the number of bucket placements in a swing width to exactly fit the dredging width ..." <<std::endl ;
	std::cout <<" \t\t i)   For center justified bucket placement:  "<< lCenterJustified << std::endl ;
	std::cout <<" \t\t ii)  For side justified ( left or right ) bucket placement:  "<< lSideJustified <<std::endl ;

}

void
DredgeArea:: BucketRows()
{

	float lBucketWidth( GetBucketWidth() ) ;
	float lnumBucketRows, lLongitudinalOverlap ;

	lnumBucketRows = (  mDredgeWidth / 
				       ( lBucketWidth - mLongitudinalOverlap ) 
					 ) + 1 ;

	lLongitudinalOverlap = lBucketWidth - ( mDredgeLength / lnumBucketRows ) + 1 ;

	std::cout << " \n\nNumber of bucket rows:\t" << lnumBucketRows <<std::endl ;
	std::cout << " Longitudinal bucket overlap to fix bucket exactly:\t" << lLongitudinalOverlap <<std::endl ;

}