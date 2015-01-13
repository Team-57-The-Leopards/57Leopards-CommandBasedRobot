#include "ShooterAngle.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/Shooter1Stick.h"

ShooterAngle::ShooterAngle() : AdvPIDSubsystem("ShooterAngle", Kp, Ki, Kd) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	angleSensor = new AnalogChannel(ch_ShooterAngle);
	motor = new CANJaguar(ch_LeadscrewM);
	motor->SetSafetyEnabled(kMotorSafety);
	lastAngle = 1;
	
	AdvPIDController *controller = GetPIDController(); 
	
	controller->SetInputRange(MinInput, MaxInput);
	controller->SetOutputRange(MinOutput, MaxOutput);
	controller->SetAbsoluteTolerance(AbsErr);
}

double ShooterAngle::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	lastAngle = angleSensor->GetVoltage();
	return lastAngle;
}

double ShooterAngle::ReturnAngle() {
	lastAngle = angleSensor->GetVoltage();
	return lastAngle;
}

double ShooterAngle::GetOutput() {
	return motorOut;
}

void ShooterAngle::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	motorOut = inverted ? -output : output;
	motor->Set(motorOut);
}

bool ShooterAngle::IsEnabled()
{
	return GetPIDController()->IsEnabled();
}

void ShooterAngle::StickOutput(Joystick *stick) {
	motorOut = stick->GetY();
	motorOut = inverted ? -motorOut : motorOut;
	motor->Set(motorOut);
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void ShooterAngle::InitDefaultCommand() {
	// Set the default command for a subsystem here.
//	SetDefaultCommand(new Shooter1Stick());
}
