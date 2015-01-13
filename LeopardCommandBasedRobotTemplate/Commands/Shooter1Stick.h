#ifndef SHOOTER1STICK_H
#define SHOOTER1STICK_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class Shooter1Stick: public CommandBase {
public:
	Shooter1Stick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
