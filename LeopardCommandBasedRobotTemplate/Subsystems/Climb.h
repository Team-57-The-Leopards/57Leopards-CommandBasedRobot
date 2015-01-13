#ifndef CLIMB_H
#define CLIMB_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robotmap.h"

class Climb: public Subsystem {
private:
	
	
public:
	Climb();
	void InitDefaultCommand();
	void RaiseArms();
	void LiftRobot();
	Solenoid *rightClimbLift;
	Solenoid *rightClimbLower;
	Solenoid *leftClimbLift;
	Solenoid *leftClimbLower;
};

#endif

