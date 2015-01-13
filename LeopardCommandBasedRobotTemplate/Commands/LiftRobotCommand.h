#ifndef LIFTROBOTCOMMAND_H
#define LIFTROBOTCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Team 57
 */
class LiftRobotCommand: public CommandBase {
public:
	LiftRobotCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
