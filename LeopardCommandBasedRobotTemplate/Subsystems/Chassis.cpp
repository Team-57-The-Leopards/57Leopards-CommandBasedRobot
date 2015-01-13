#include "Chassis.h"
#include "../Robotmap.h"
#include "Commands/Subsystem.h"
#include "../Commands/DriveCommand.h"
#include "WPiLib.h"



Chassis::Chassis() : Subsystem("Chassis") {
	frontleftm = new CANJaguar(ch_FrontLeftM);
	backleftm = new CANJaguar(ch_BackLeftM);
	frontrightm = new CANJaguar(ch_BackRightM);
	backrightm = new CANJaguar(ch_FrontRightM);
	drive = new RobotDrive(frontleftm, backleftm, frontrightm, backrightm);
	drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	drive->SetSafetyEnabled(kMotorSafety);
	shifter = new Solenoid(ch_LowGear);			 
}


void Chassis::InitDefaultCommand(){
	SetDefaultCommand(new DriveCommand());
}

void Chassis::HighGear()
{
    shifter->Set(false);
}
void Chassis::LowGear()
{
	shifter->Set(true); 
}

void Chassis::DriveWithJoystick(Joystick *drivestick)
{
	drive->ArcadeDrive(drivestick);
}

void Chassis::ArcadeDrive(double y, double x)
{
	drive->ArcadeDrive(y, x);
}

