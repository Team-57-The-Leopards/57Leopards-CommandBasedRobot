#ifndef ANGLESETPOINTCOMMAND_H
#define ANGLESETPOINTCOMMAND_H

#include "../CommandBase.h"
#include "../Robotmap.h"
#include "Timer.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class AngleSetpointCommand: public CommandBase {
public:
	AngleSetpointCommand();
	AngleSetpointCommand(int num, bool hold = false);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	int select;
	bool _hold;
	Timer *tmr;
	static const double kSetTime = 0.1;

};

#endif
