#ifndef ANGLEDISABLECOMMAND_H
#define ANGLEDISABLECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class AngleDisableCommand: public CommandBase {
public:
	AngleDisableCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
