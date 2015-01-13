#ifndef SHOOTERSETPOINTCOMMAND_H
#define SHOOTERSETPOINTCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class ShooterSetpointCommand: public CommandBase {
public:
	ShooterSetpointCommand();
	ShooterSetpointCommand(int num);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
private:
	int select;
};

#endif
