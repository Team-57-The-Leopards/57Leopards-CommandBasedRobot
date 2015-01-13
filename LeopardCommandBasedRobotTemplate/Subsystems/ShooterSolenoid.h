#ifndef SHOOTERSOLENOID_H
#define SHOOTERSOLENOID_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robotmap.h"
/**
 *
 *
 * @author Team 57
 */
class ShooterSolenoid: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterSolenoid();
	void InitDefaultCommand();
	void Fire();
	void Retract();
	Solenoid *fireSolenoid;
	Solenoid *retractSolenoid;
};

#endif
