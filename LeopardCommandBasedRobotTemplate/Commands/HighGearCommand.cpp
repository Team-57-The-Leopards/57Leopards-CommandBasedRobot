#include "HighGearCommand.h"

HighGearCommand::HighGearCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void HighGearCommand::Initialize() {
//	Requires(chassis);
}

// Called repeatedly when this Command is scheduled to run
void HighGearCommand::Execute() {
	chassis->HighGear();
}

// Make this return true when this Command no longer needs to run execute()
bool HighGearCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void HighGearCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HighGearCommand::Interrupted() {
}
