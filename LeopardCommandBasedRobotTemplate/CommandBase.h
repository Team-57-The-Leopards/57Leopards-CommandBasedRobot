#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Climb.h"
#include "Subsystems/Shooter1.h"
#include "Subsystems/Shooter2.h"
#include "Subsystems/Shooter3.h"
#include "Subsystems/ShooterAngle.h"
#include "Subsystems/ShooterSolenoid.h"
#include "OI.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;
	static Chassis *chassis;
	static ShooterSolenoid *shooterSolenoid;
	static Shooter1 *shooter1;
	static Shooter2 *shooter2;
	static Shooter3 *shooter3;
	static ShooterAngle *shooterAngle;
	static Climb *climb;	
	static int shootSelect;
	
};

#endif
