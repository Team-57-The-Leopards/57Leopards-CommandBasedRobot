#ifndef AUTONFIREGROUP_H
#define AUTONFIREGROUP_H

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
class AutonFireGroup: public CommandGroup {
public:	
	AutonFireGroup();
	AutonFireGroup(int num);
};

#endif
