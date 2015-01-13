#include "ShooterSolenoid.h"
#include "../Robotmap.h"
#include "Commands/Subsystem.h"
#include "WPiLib.h"
ShooterSolenoid::ShooterSolenoid() : Subsystem("ShooterSolenoid") {
	
	fireSolenoid = new Solenoid(ch_ShooterFire);
	retractSolenoid = new Solenoid(ch_ShooterRetract);
}
void ShooterSolenoid::Fire()
{
 	fireSolenoid->Set(true);
 	retractSolenoid->Set(false);
}
void ShooterSolenoid::Retract()
{
	fireSolenoid->Set(false);
	retractSolenoid->Set(true);
}
void ShooterSolenoid::InitDefaultCommand()
{
}
