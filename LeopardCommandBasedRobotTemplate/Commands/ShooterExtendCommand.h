#ifndef SHOOTEREXTENDCOMMAND_H
#define SHOOTEREXTENDCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class ShooterExtendCommand: public CommandBase {
private:
	static const double kTimeout = 0.25;
public:
	ShooterExtendCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
