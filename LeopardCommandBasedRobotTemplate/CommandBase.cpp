#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}
// Initialize a single static instance of all of your subsystems to NULL
Chassis* CommandBase::chassis = NULL;
OI* CommandBase::oi = NULL;
ShooterSolenoid* CommandBase::shooterSolenoid = NULL;
Climb* CommandBase::climb = NULL;
Shooter1* CommandBase::shooter1 = NULL;
Shooter2* CommandBase::shooter2 = NULL;
Shooter3* CommandBase::shooter3 = NULL;
ShooterAngle* CommandBase::shooterAngle = NULL;
int CommandBase::shootSelect = 1;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	chassis = new Chassis();
	climb = new Climb();
	shooterSolenoid = new ShooterSolenoid();
	shooter1 = new Shooter1();
	shooter2 = new Shooter2();
	shooter3 = new Shooter3();
	shooterAngle = new ShooterAngle();
	oi = new OI();
	shootSelect = 1;
};
