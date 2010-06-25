#ifndef MACHINE_H
#define MACHINE_H

class Machine
{

	public:
		Machine() ;
		void SetMachineProperties() ;
		const float GetBoomLength() const;
		
		/*void  SetAngularDisplacement( float& AngularDisplacement ) ;
		float GetAngularDisplacement() const;
		
		void VolumeCalculation() ;

		void SetHookToSeabedHeight( int& ) ;*/



	private:
		float mBoomLength, mMaxDredgeWidth, mMinDredgeReach, mMaxDredgeReach ;

} ;

#endif
