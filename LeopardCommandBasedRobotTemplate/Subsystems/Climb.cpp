#include "Climb.h"
#include "../Robotmap.h"
#include "Commands/Subsystem.h"
#include "WPiLib.h"



Climb::Climb() : Subsystem("Climb") {
	
	rightClimbLift = new Solenoid(ch_RightClimbLift);
	rightClimbLower = new Solenoid(ch_RightClimbLower);
	leftClimbLift = new Solenoid(ch_LeftClimbLift);
	leftClimbLower = new Solenoid(ch_LeftClimbLower);
			 
}

void Climb::InitDefaultCommand(){
}

void Climb::RaiseArms()
{
	rightClimbLower->Set(true);
	leftClimbLower->Set(true);
	rightClimbLift->Set(false);
	leftClimbLift->Set(false);
	
}
void Climb::LiftRobot()
{
	
	rightClimbLower->Set(false);
	leftClimbLower->Set(false);
	rightClimbLift->Set(true);
	leftClimbLift->Set(true);
}





