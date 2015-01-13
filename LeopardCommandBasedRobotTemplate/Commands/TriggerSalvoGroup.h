#ifndef TRIGGERSALVOGROUP_H
#define TRIGGERSALVOGROUP_H

#include "Commands/CommandGroup.h"
#include "FireDiscGroup.h"
#include "AngleEnableCommand.h"
#include "AngleSetpointCommand.h"
#include "AngleDisableCommand.h"
#include "ShooterDisableCommand.h"

#include "../CommandBase.h"
/**
 *
 *
 * @author Kevin Sevcik
 */
class TriggerSalvoGroup: public CommandGroup {
public:	
	TriggerSalvoGroup();
};

#endif
