#ifndef MACHINE_H
#define MACHINE_H

class Machine
{

	public:
		Machine( int LadderLength, float HookToSeabedHeight ) ;
		Machine() {}

		void  SetAngularDisplacement( float& AngularDisplacement ) ;
		float GetAngularDisplacement() const;
		
		void VolumeCalculation() ;

		void SetHookToSeabedHeight( int& ) ;
		const int  GetHookToSeabedHeight() const;

	private:
		int mLadderLength, mHookToSeabedHeight ;
		float mAngularDisplacement, mMinDredgeReach, mMaxDredgeReach ;

} ;

#endif
