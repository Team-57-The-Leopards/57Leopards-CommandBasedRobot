#ifndef RAISEARMSCOMMAND_H
#define RAISEARMSCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Team 57
 */
class RaiseArmsCommand: public CommandBase {
public:
	RaiseArmsCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
