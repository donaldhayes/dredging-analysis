#ifndef DREDGE_AREA_H
#define DREDGE_AREA_H

#include "Bucket.h"

class DredgeArea : public Bucket
{
	public:
		DredgeArea( float Length, float Width ) ;
		void SwingCharacteristics() ;

		float GetTotalDredgeSwingAngle() const ;
		float GetSwingArcLength() const ;


	private:
		float mDredgeLength, mDredgeWidth ;
		float mDredgeArea, mTotalDredgeSwingAngle, mSwingArcLength ;

};

#endif