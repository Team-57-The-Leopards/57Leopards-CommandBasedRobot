#include "ShooterDisableCommand.h"

ShooterDisableCommand::ShooterDisableCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooter1);
	Requires(shooter2);
	Requires(shooter3);
}

// Called just before this Command runs the first time
void ShooterDisableCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShooterDisableCommand::Execute() {
	shooter1->Disable();
	shooter2->Disable();
	shooter3->Disable();
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterDisableCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShooterDisableCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterDisableCommand::Interrupted() {
}
