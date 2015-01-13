#ifndef LOWGEARCOMMAND_H
#define LOWGEARCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Team 57
 */
class LowGearCommand: public CommandBase {
public:
	LowGearCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
