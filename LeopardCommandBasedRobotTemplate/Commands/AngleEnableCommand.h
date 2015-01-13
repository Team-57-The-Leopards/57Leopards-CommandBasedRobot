#ifndef ANGLEENABLECOMMAND_H
#define ANGLEENABLECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class AngleEnableCommand: public CommandBase {
public:
	AngleEnableCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
