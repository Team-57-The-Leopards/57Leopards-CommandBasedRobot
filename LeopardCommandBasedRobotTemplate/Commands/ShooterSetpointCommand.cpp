#include "ShooterSetpointCommand.h"
#include "../Robotmap.h"

ShooterSetpointCommand::ShooterSetpointCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooter1);
	Requires(shooter2);
	Requires(shooter3);
	select = 0;
}

ShooterSetpointCommand::ShooterSetpointCommand(int num) {
	// Use requires() here to declare subsystem dependencies
	Requires(shooter1);
	Requires(shooter2);
	Requires(shooter3);
	select = num;
}

// Called just before this Command runs the first time
void ShooterSetpointCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShooterSetpointCommand::Execute() {
	double speed;
	SmartDashboard::PutNumber("ExeSelect",select);
	if (select < 0)
	{
		Joystick* drv = CommandBase::oi->GetShootJoystick();
		int num = CommandBase::shootSelect;
		if (num <= 6)
			speed = kShootSpeeds[num];
		else
		{
			speed = 11000 * ((drv->GetX() + 1.0) / 2);
		}
		speed += 400 * drv->GetZ(); 
	} else
		speed = kShootSpeeds[select];
	

	double set1 = 0;
	double set2 = 4500;
	double set3 = 3200;
	set1 = speed;
	set2 = (set1 > set2) ? set2 : set1;
	set3 = (set2 > set3) ? set3 : set2;
	shooter1->SetSetpoint(set1);
	shooter2->SetSetpoint(set2);
	shooter3->SetSetpoint(set3);
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterSetpointCommand::IsFinished() {
	bool ret1 = shooter1->OnTarget();
	bool ret2 = shooter2->OnTarget();
	bool ret3 = shooter3->OnTarget();
	bool ret = ret1 && ret2 && ret3;
	if (ret)
		printf("Shooter On Target\n");
	return ret;
}

// Called once after isFinished returns true
void ShooterSetpointCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterSetpointCommand::Interrupted() {
}
