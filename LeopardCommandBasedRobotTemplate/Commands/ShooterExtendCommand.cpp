#include "ShooterExtendCommand.h"

ShooterExtendCommand::ShooterExtendCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooterSolenoid);
}

// Called just before this Command runs the first time
void ShooterExtendCommand::Initialize() {
	SetTimeout(kTimeout);
}

// Called repeatedly when this Command is scheduled to run
void ShooterExtendCommand::Execute() {
	shooterSolenoid->Fire();
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterExtendCommand::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ShooterExtendCommand::End() {
	shooterSolenoid->Retract();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterExtendCommand::Interrupted() {
	shooterSolenoid->Retract();
}
