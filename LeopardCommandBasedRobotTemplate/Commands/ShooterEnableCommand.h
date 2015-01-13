#ifndef SHOOTERENABLECOMMAND_H
#define SHOOTERENABLECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class ShooterEnableCommand: public CommandBase {
public:
	ShooterEnableCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
