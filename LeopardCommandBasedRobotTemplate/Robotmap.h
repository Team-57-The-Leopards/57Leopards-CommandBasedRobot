#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// Safety Enabled set false for debugging, true for motor safety enabled.
static const bool kMotorSafety = false;

//	Shooting Setpoints
// 	Use caution when changing, and do NOT change the Lift angle
//  Cases are 						{Stow, Far, Near, Lift, Corner, Top Goal, Load} 
static const double kShootAngles[7] = {0.05, 0.710, 1.00, 1.00, 0.697, 0.710, 0.50};
static const double kShootSpeeds[7] = {1000, 8300, 5800, 6000, 8150, 8300, 1000};

static const double kMaxPeriod = 0.5;
 
// CAN Jaguars for chassis
static const UINT32 ch_FrontLeftM = 1;
static const UINT32 ch_BackLeftM = 2;
static const UINT32 ch_BackRightM = 3;
static const UINT32 ch_FrontRightM = 4;

// CAN Jaguars for Leadscrew
static const UINT32 ch_LeadscrewM = 5;

// CAN Jaguars for shooter
static const UINT32 ch_ShooterM1 = 6;
static const UINT32 ch_ShooterM2 = 7;
static const UINT32 ch_ShooterM3 = 8;

//Relay Constants
static const UINT32 ch_PumpRelay = 1;

//Solenoid Channels for pneumatics
static const UINT32 ch_ShooterRetract= 1; //Swapped to bias piston forward
static const UINT32 ch_ShooterFire = 2;
static const UINT32 ch_RightClimbLower = 3;
static const UINT32 ch_RightClimbLift = 4;
static const UINT32 ch_LeftClimbLower = 5;
static const UINT32 ch_LeftClimbLift = 6;
static const UINT32 ch_LowGear = 7;

//Digital IO for sensors
static const UINT32 ch_Incline1 = 1;
static const UINT32 ch_Incline2 = 2;
static const UINT32 ch_Incline3 = 3;
static const UINT32 ch_Incline4 = 4;
static const UINT32 ch_Shooter1Pulse = 5;
static const UINT32 ch_Shooter2Pulse = 6;
static const UINT32 ch_Shooter3Pulse = 7;
static const UINT32 ch_PressureSwitch = 14;

//Analog Inputs
static const UINT32 ch_ShooterAngle = 1;

// Joysticks
static const UINT32 ch_DriveJoystick = 1;
static const UINT32 ch_ShooterJoystick = 2;

//Buttons
static const UINT32 ch_ShiftTrigger= 1;
static const UINT32 ch_RaiseButton = 7;
static const UINT32 ch_LiftButton= 6;
static const UINT32 ch_FireButton = 9;
static const UINT32 ch_AngleButton = 8;
static const UINT32 ch_LoadButton = 7;
static const UINT32 ch_StowButton = 11;


#endif
