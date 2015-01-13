#include "ShooterEnableCommand.h"

ShooterEnableCommand::ShooterEnableCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooter1);
	Requires(shooter2);
	Requires(shooter3);
}

// Called just before this Command runs the first time
void ShooterEnableCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShooterEnableCommand::Execute() {
	shooter1->Enable();
	shooter2->Enable();
	shooter3->Enable();
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterEnableCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShooterEnableCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterEnableCommand::Interrupted() {
}
