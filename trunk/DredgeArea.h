#ifndef DREDGE_AREA_H
#define DREDGE_AREA_H

#include "Bucket.h"

class DredgeArea : public Bucket
{
	public:
		
		DredgeArea() ;
		void SetDredgeAreaProperties() ;
		void SwingCharacteristics() ;
		void LateralBucketPlacemnet() ;
		void BucketRows() ;

		float GetTotalDredgeSwingAngle() const ;
		float GetSwingArcLength() const ;
		
	private:
		float mDredgeLength, mDredgeWidth ;
		float mDredgeArea, mTotalDredgeSwingAngle, mSwingArcLength ;
		float mLateralOverlap, mLongitudinalOverlap ;

};

#endif