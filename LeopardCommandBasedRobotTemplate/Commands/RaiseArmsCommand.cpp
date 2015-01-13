#include "RaiseArmsCommand.h"

RaiseArmsCommand::RaiseArmsCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(climb);
}

// Called just before this Command runs the first time
void RaiseArmsCommand::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void RaiseArmsCommand::Execute() {
	climb->RaiseArms();
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseArmsCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RaiseArmsCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseArmsCommand::Interrupted() {
}
