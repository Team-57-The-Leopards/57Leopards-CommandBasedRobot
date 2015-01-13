#ifndef READYDISCGROUP_H
#define READYDISCGROUP_H

#include "Commands/CommandGroup.h"
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
class ReadyDiscGroup: public CommandGroup {
public:	
	ReadyDiscGroup();
	ReadyDiscGroup(int num);
};

#endif
