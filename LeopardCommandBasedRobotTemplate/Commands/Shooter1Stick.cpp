#include "Shooter1Stick.h"

Shooter1Stick::Shooter1Stick() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooterAngle);
}

// Called just before this Command runs the first time
void Shooter1Stick::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Shooter1Stick::Execute() {
	shooterAngle->StickOutput(oi->GetShootJoystick());

}

// Make this return true when this Command no longer needs to run execute()
bool Shooter1Stick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Shooter1Stick::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shooter1Stick::Interrupted() {
}
