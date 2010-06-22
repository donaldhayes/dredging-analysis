
#ifndef BUCKET_H
#define BUCKET_H

#include <string>
#include "Machine.h"

class Bucket : public Machine
{
	public:
		Bucket( std::string Name, int Length, int Width, int Height, int LadderLength, float HookToSeabedHeight ) ;
		Bucket() {}
		const int* GetBucketDimensions() const;
		void SetBucketDimensions( int* ) ;

		int NumBucketsForCenterPlacementInSwing() ;
		int NumBucketsForSidePlacementInSwing() ;

		int NumOfBucketRows() ;

	private:
		int mBucketDimensions[2], mBucketVolume;
		float mLateralBucketOverlap ;
		std::string mBucketName ;
};

#endif 