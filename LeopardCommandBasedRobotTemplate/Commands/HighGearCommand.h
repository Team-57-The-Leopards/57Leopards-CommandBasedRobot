#ifndef HIGHGEARCOMMAND_H
#define HIGHGEARCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Team 57
 */
class HighGearCommand: public CommandBase {
public:
	HighGearCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
