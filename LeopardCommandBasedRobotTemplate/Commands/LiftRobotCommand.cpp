#include "LiftRobotCommand.h"

LiftRobotCommand::LiftRobotCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(climb);
}

// Called just before this Command runs the first time
void LiftRobotCommand::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void LiftRobotCommand::Execute() {
	climb->LiftRobot();
}

// Make this return true when this Command no longer needs to run execute()
bool LiftRobotCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftRobotCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftRobotCommand::Interrupted() {
}
