#include "OI.h"
#include "Robotmap.h"
#include "Commands/LowGearCommand.h"
#include "Commands/HighGearCommand.h"
#include "Commands/RaiseArmsCommand.h"
#include "Commands/FireDiscGroup.h"
#include "Commands/LiftRobotCommand.h"
#include "Commands/ShooterEnableCommand.h"
#include "Commands/ShooterDisableCommand.h"
#include "Commands/ShooterSetpointCommand.h"
#include "Commands/AngleEnableCommand.h"
#include "Commands/AngleDisableCommand.h"
#include "Commands/AngleSetpointCommand.h"
#include "Commands/TriggerSalvoGroup.h"
#include "Commands/AngleSetGroup.h"
#include "Commands/GotoLoadGroup.h"
#include "Commands/GotoStowGroup.h"

OI::OI() {
	// Process operator interface input here.
	shooterStick = new Joystick(ch_ShooterJoystick);
	driveStick = new Joystick(ch_DriveJoystick);
	shootdisc =new JoystickButton(shooterStick,ch_FireButton);
	shifttrigger = new JoystickButton(driveStick,ch_ShiftTrigger);
	raisebutton = new JoystickButton(driveStick,ch_RaiseButton);
	liftbutton = new JoystickButton(driveStick,ch_LiftButton);
	
	fireButton = new JoystickButton(shooterStick, ch_FireButton);
	angleButton = new JoystickButton(shooterStick, ch_AngleButton);
	loadButton = new JoystickButton(shooterStick, ch_LoadButton);
	stowButton = new JoystickButton(driveStick, ch_StowButton);
	
//		fireButton->WhenPressed(new ShooterEnableCommand());
//		fireButton->WhenPressed(new FireDiscGroup());
//		fireButton->WhenReleased(new ShooterDisableCommand());
//		setButton->WhenPressed(new ShooterSetpointCommand());
	fireButton->WhenPressed(new TriggerSalvoGroup());
	fireButton->WhenReleased(new ShooterDisableCommand());
	angleButton->WhenPressed(new AngleSetGroup());
	loadButton->WhenPressed(new GotoLoadGroup());
	stowButton->WhenPressed(new GotoStowGroup());
	
	shifttrigger->WhenPressed(new LowGearCommand());
	shifttrigger->WhenReleased(new HighGearCommand());
	raisebutton->WhenPressed(new RaiseArmsCommand());
	liftbutton->WhenPressed(new LiftRobotCommand());
}
Joystick * OI::GetDriveJoystick()
{
	return driveStick;
}
Joystick * OI::GetShootJoystick()
{
	return shooterStick;
}
