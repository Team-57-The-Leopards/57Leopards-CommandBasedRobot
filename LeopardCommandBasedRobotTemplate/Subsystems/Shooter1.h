#ifndef SHOOTER1_H
#define SHOOTER1_H

#include "../AdvPIDSubsystem.h"
#include "WPILib.h"
#include "../RPMCounter.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class Shooter1: public AdvPIDSubsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 0.00025;
	static const double Ki = 0.00005;
	static const double Kd = 0.0;
	static const double Kf = 8.15e-5;
	static const bool inverted = false;

	static const double MinOutput = 0.0;
	static const double MaxOutput = 1.0;

	static const double MinInput = 4000.0;
	static const double MaxInput = 11000.0;
	
	static const double AbsErr = 75;
	
	

	double lastRPM, motorOut;
	
	RPMCounter* rpmSensor;
	CANJaguar* motor;
	
public:
	Shooter1();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	
	double ReturnRPM();
	double GetOutput();
	void StickOutput(Joystick *stick);
};

#endif
