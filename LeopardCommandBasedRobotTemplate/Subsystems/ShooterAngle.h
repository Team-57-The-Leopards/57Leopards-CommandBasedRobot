#ifndef SHOOTERANGLE_H
#define SHOOTERANGLE_H

#include "../AdvPIDSubsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class ShooterAngle: public AdvPIDSubsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 14;
	static const double Ki = 0.0000;
	static const double Kd = 3.0;
	static const double Kf = 0.0;
	static const bool inverted = false;

	static const double MinOutput = -1.0;
	static const double MaxOutput = 1.0;

	static const double MinInput = 0.08;
	static const double MaxInput = 1.0;
	
	static const double AbsErr = 0.01;
	
	

	double lastAngle, motorOut;
	
	AnalogChannel* angleSensor;
	CANJaguar* motor;
	
public:
	ShooterAngle();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	
	double ReturnAngle();
	double GetOutput();
	bool IsEnabled();
	void StickOutput(Joystick *stick);
};

#endif
