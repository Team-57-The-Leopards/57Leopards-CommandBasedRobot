/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "RPMCounter.h"
#include "LiveWindow/LiveWindow.h"


const double RPMCounter::periodThreshold;

/**
 * Construct a RPMCounter sensor given a channel.
 * 
 * The default module is assumed.
 * 
 * @param channel The GPIO channel on the digital module that the sensor is connected to.
 */
RPMCounter::RPMCounter(UINT32 channel)
	: Counter(channel)
{
}

/**
 * Construct a RPMCounter sensor given a channel and module.
 * 
 * @param moduleNumber The digital module (1 or 2).
 * @param channel The GPIO channel on the digital module that the sensor is connected to.
 */
RPMCounter::RPMCounter(UINT8 moduleNumber, UINT32 channel)
	: Counter(moduleNumber, channel)
{
	LiveWindow::GetInstance()->AddSensor("RPMCounter", moduleNumber, channel, this);
}

/**
 * Construct a RPMCounter sensor given a digital input.
 * This should be used when sharing digial inputs.
 * 
 * @param source An object that fully descibes the input that the sensor is connected to.
 */
RPMCounter::RPMCounter(DigitalSource *source)
	: Counter(source)
{
}

RPMCounter::RPMCounter(DigitalSource &source): Counter(source)
{
}

/**
 * Get calculated RPM from counter
 */
double RPMCounter::GetRPM()
{
	if (Counter::GetStopped())
	{
		prevResult = 0;
		return 0;
	}
	float period = Counter::GetPeriod();
	if (period < periodThreshold)
	{
		return prevResult;
	}
	prevResult = 60.0 / period;
	return prevResult;
}

double RPMCounter::GetPID()
{
	return GetRPM();
}


/**
 * Free the resources associated with a gear tooth sensor.
 */
RPMCounter::~RPMCounter()
{
}


std::string RPMCounter::GetSmartDashboardType() {
	return "RPMCounter";
}

