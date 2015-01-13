#include "Shooter2.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"

Shooter2::Shooter2() : AdvPIDSubsystem("Shooter2", Kp, Ki, Kd, Kf) {
	rpmSensor = new RPMCounter(ch_Shooter2Pulse);
	rpmSensor->SetMaxPeriod(kMaxPeriod);
	rpmSensor->Start();
	motor = new CANJaguar(ch_ShooterM2);
	motor->SetSafetyEnabled(kMotorSafety);
	lastRPM = 1000;
	
	AdvPIDController *controller = GetPIDController(); 
	
	controller->SetInputRange(MinInput, MaxInput);
	controller->SetOutputRange(MinOutput, MaxOutput);
	controller->SetAbsoluteTolerance(AbsErr);
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double Shooter2::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	lastRPM = rpmSensor->GetRPM();
	return lastRPM;
}

double Shooter2::ReturnRPM() {
	return lastRPM;
}

double Shooter2::GetOutput() {
	return motorOut;
}

void Shooter2::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	motorOut = inverted ? -output : output;
	motor->Set(motorOut);
}

void Shooter2::StickOutput(Joystick *stick) {
	motorOut = (stick->GetZ() + 1) / 2;
	motorOut = inverted ? -motorOut : motorOut;
	motor->Set(motorOut);
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void Shooter2::InitDefaultCommand() {
	// Set the default command for a subsystem here.
}
