#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	
	

public:
	OI();
	Joystick *driveStick;
	Joystick *shooterStick;
	JoystickButton *shifttrigger;
	JoystickButton *raisebutton;
	JoystickButton *liftbutton;
	JoystickButton *shootdisc;
	JoystickButton *fireButton;
	JoystickButton *angleButton;
	JoystickButton *loadButton;
	JoystickButton *stowButton;
	Joystick *GetDriveJoystick();
	Joystick *GetShootJoystick();
};

#endif
