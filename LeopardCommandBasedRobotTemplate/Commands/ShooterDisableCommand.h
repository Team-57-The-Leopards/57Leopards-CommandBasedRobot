#ifndef SHOOTERDISABLECOMMAND_H
#define SHOOTERDISABLECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class ShooterDisableCommand: public CommandBase {
public:
	ShooterDisableCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
