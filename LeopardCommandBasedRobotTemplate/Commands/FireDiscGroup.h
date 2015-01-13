#ifndef FIREDISCGROUP_H
#define FIREDISCGROUP_H

#include "Commands/CommandGroup.h"
#include "ReadyDiscGroup.h"
#include "ShooterEnableCommand.h"
#include "ShooterSetpointCommand.h"
#include "ShooterExtendCommand.h"
#include "ShooterRetractCommand.h"
#include "../CommandBase.h"
#include "../Robotmap.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class FireDiscGroup: public CommandGroup {
public:	
	FireDiscGroup();
	FireDiscGroup(int num);
	virtual bool IsFinished();
};

#endif
