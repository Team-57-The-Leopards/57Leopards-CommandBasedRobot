#ifndef SHOOTER3_H
#define SHOOTER3_H

#include "../AdvPIDSubsystem.h"
#include "WPILib.h"
#include "../RPMCounter.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class Shooter3: public AdvPIDSubsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 0.0006;
	static const double Ki = 0.00015;
	static const double Kd = 0.0;
	static const double Kf = 0.00025;
	static const bool inverted = false;

	static const double MinOutput = 0.0;
	static const double MaxOutput = 1.0;

	static const double MinInput = 2000.0;
	static const double MaxInput = 3500.0;
	
	static const double AbsErr = 100;
	
	

	double lastRPM, motorOut;
	
	RPMCounter* rpmSensor;
	CANJaguar* motor;
	
public:
	Shooter3();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	
	double ReturnRPM();
	double GetOutput();
	void StickOutput(Joystick *stick);
};

#endif
