#ifndef MACHINE_H
#define MACHINE_H

class Machine
{

	public:
		Machine() ;
		void SetMachineProperties() ;
		/*void  SetAngularDisplacement( float& AngularDisplacement ) ;
		float GetAngularDisplacement() const;
		
		void VolumeCalculation() ;*/

	//	void SetHookToSeabedHeight( int& ) ;

		const float GetBoomLength() const;

	private:
		float mBoomLength, mMaxDredgeWidth, mMinDredgeReach, mMaxDredgeReach ;

} ;

#endif
