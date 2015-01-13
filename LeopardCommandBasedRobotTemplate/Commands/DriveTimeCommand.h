#ifndef DRIVETIMECOMMAND_H
#define DRIVETIMECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class DriveTimeCommand: public CommandBase {
public:
	DriveTimeCommand(double time, double y, double x);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	double timeout, mX, mY;
};

#endif
