#include "DriveCommand.h"

DriveCommand::DriveCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(chassis);
}

// Called just before this Command runs the first time
void DriveCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() {
	chassis->DriveWithJoystick(oi->GetDriveJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted() {
}
