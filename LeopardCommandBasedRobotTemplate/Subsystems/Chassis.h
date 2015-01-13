#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robotmap.h"

class Chassis: public Subsystem {
private:
	RobotDrive *drive;
	
public:
	Chassis();
	void InitDefaultCommand();
	void HighGear();
	void LowGear();
	void DriveWithJoystick(Joystick *drivestick);
	void ArcadeDrive(double y, double x);
	CANJaguar *frontleftm;
	CANJaguar *backleftm;
	CANJaguar *frontrightm;
	CANJaguar *backrightm;
	Solenoid *shifter;
};

#endif
