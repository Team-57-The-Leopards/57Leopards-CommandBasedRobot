#include "ShooterRetractCommand.h"

ShooterRetractCommand::ShooterRetractCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooterSolenoid);
}

// Called just before this Command runs the first time
void ShooterRetractCommand::Initialize() {
	SetTimeout(kTimeout);
}

// Called repeatedly when this Command is scheduled to run
void ShooterRetractCommand::Execute() {
	shooterSolenoid->Retract();
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterRetractCommand::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ShooterRetractCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterRetractCommand::Interrupted() {
}
