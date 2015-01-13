#include "AngleEnableCommand.h"

AngleEnableCommand::AngleEnableCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooterAngle);
}

// Called just before this Command runs the first time
void AngleEnableCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AngleEnableCommand::Execute() {
	shooterAngle->Enable();
}

// Make this return true when this Command no longer needs to run execute()
bool AngleEnableCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AngleEnableCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AngleEnableCommand::Interrupted() {
}
