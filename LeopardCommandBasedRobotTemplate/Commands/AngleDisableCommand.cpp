#include "AngleDisableCommand.h"

AngleDisableCommand::AngleDisableCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooterAngle);
}

// Called just before this Command runs the first time
void AngleDisableCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AngleDisableCommand::Execute() {
	shooterAngle->Disable();
}

// Make this return true when this Command no longer needs to run execute()
bool AngleDisableCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AngleDisableCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AngleDisableCommand::Interrupted() {
}
