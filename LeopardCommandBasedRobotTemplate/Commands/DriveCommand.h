#ifndef DRIVECOMMAND_H
#define DRIVECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Team 57
 */
class DriveCommand: public CommandBase {
public:
	DriveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
