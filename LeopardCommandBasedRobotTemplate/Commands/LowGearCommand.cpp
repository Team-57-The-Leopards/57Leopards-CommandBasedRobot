#include "LowGearCommand.h"

LowGearCommand::LowGearCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LowGearCommand::Initialize() {
//	Requires(chassis);
}

// Called repeatedly when this Command is scheduled to run
void LowGearCommand::Execute() {
	chassis->LowGear();
}

// Make this return true when this Command no longer needs to run execute()
bool LowGearCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void LowGearCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowGearCommand::Interrupted() {
}
