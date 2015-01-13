#ifndef SHOOTER2_H
#define SHOOTER2_H

#include "../AdvPIDSubsystem.h"
#include "WPILib.h"
#include "../RPMCounter.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class Shooter2: public AdvPIDSubsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 0.00056;
	static const double Ki = 0.00011;
	static const double Kd = 0.0;
	static const double Kf = 0.00018;
	static const bool inverted = true;

	static const double MinOutput = 0.0;
	static const double MaxOutput = 1.0;

	static const double MinInput = 3000.0;
	static const double MaxInput = 4900.0;
	
	static const double AbsErr = 100;
	
	

	double lastRPM, motorOut;
	
	RPMCounter* rpmSensor;
	CANJaguar* motor;
	
public:
	Shooter2();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	
	double ReturnRPM();
	double GetOutput();
	void StickOutput(Joystick *stick);
};

#endif
