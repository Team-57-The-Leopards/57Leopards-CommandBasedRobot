#include "DriveTimeCommand.h"

DriveTimeCommand::DriveTimeCommand(double time, double y, double x) {
	// Use requires() here to declare subsystem dependencies
	Requires(chassis);
	timeout = time;
	mY = y;
	mX = x;
}

// Called just before this Command runs the first time
void DriveTimeCommand::Initialize() {
	SetTimeout(timeout);
	chassis->ArcadeDrive(mY, mX);
}

// Called repeatedly when this Command is scheduled to run
void DriveTimeCommand::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTimeCommand::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void DriveTimeCommand::End() {
	chassis->ArcadeDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTimeCommand::Interrupted() {
}
