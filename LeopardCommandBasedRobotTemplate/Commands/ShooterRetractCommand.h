#ifndef SHOOTERRETRACTCOMMAND_H
#define SHOOTERRETRACTCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class ShooterRetractCommand: public CommandBase {
private:
	static const double kTimeout = 0.5;
public:
	ShooterRetractCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
