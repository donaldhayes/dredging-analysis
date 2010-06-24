
#ifndef BUCKET_H
#define BUCKET_H

#include <string>
#include "Machine.h"

class Bucket : public Machine
{
	public:
		Bucket() ;
		void SetBucketProperties() ;
		const float GetBucketLength() const;
		const float GetBucketWidth() const ;
	/*	void SetBucketDimensions( int* ) ;
`
		int NumBucketsForCenterPlacementInSwing() ;
		int NumBucketsForSidePlacementInSwing() ;

		int NumOfBucketRows() ;*/



	private:
		float mBucketWidth, mBucketLength, mPenetrationDepth, mBucketVolume;
};

#endif 