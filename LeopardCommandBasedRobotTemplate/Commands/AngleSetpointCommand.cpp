#include "AngleSetpointCommand.h"
#include "../Robotmap.h"
#include "../CommandBase.h"

AngleSetpointCommand::AngleSetpointCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooterAngle);
	select = 0;
	_hold = false;
	tmr = new Timer();
	SetTimeout(kSetTime);
}
AngleSetpointCommand::AngleSetpointCommand(int num, bool hold) {
	// Use requires() here to declare subsystem dependencies
	Requires(shooterAngle);
	select = num;
	_hold = hold;
	SetTimeout(kSetTime);
	tmr = new Timer();
}

// Called just before this Command runs the first time
void AngleSetpointCommand::Initialize() {
	tmr->Start();
	
}

// Called repeatedly when this Command is scheduled to run
void AngleSetpointCommand::Execute() {
	SmartDashboard::PutNumber("ExeSelect",select);
	if (select < 0)
	{
		int num = CommandBase::shootSelect;
		if (num <= 6)
			shooterAngle->SetSetpoint(kShootAngles[num]);
		else
		{
			Joystick* drv = CommandBase::oi->GetShootJoystick();
			shooterAngle->SetSetpoint((drv->GetY() + 1.0) / 2);
		}
	} else
		shooterAngle->SetSetpoint(kShootAngles[select]);
	if (!shooterAngle->OnTarget())
		tmr->Reset();
//		SetTimeout(kSetTime);	
}

// Make this return true when this Command no longer needs to run execute()
bool AngleSetpointCommand::IsFinished() {
	if (_hold)
	{
		Joystick* stick = CommandBase::oi->GetShootJoystick();
		return !(stick->GetRawButton(ch_AngleButton) || stick->GetRawButton(ch_LoadButton));
	}
	else
		return tmr->HasPeriodPassed(kSetTime);
}

// Called once after isFinished returns true
void AngleSetpointCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AngleSetpointCommand::Interrupted() {
}
