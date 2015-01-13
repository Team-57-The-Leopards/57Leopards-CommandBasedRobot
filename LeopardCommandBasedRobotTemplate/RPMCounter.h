/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef RPM_COUNTER_H_
#define RPM_COUNTER_H_

#include "Counter.h"
#include "PIDSource.h"

/**
 * Alias for counter class.
 * Uses GetPeriod to calculate RPM in PIDGet()
 * with sanity checks.
 */
class RPMCounter : public Counter
{
public:
	RPMCounter(UINT32 channel);
	RPMCounter(UINT8 moduleNumber, UINT32 channel);
	RPMCounter(DigitalSource *source);
	RPMCounter(DigitalSource &source);
	virtual ~RPMCounter();

	virtual double GetPID();
	virtual double GetRPM();	
	virtual std::string GetSmartDashboardType();
		
private:
	/// 2mSec for threshold, 30,000 RPM
	static const double periodThreshold = 2e-3;
	float prevResult;
};


#endif
