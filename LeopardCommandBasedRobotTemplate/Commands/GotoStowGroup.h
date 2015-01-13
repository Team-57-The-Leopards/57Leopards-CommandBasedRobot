#ifndef GOTOSTOWGROUP_H
#define GOTOSTOWGROUP_H

#include "Commands/CommandGroup.h"
#include "AngleEnableCommand.h"
#include "AngleSetpointCommand.h"
#include "AngleDisableCommand.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class GotoStowGroup: public CommandGroup {
public:	
	GotoStowGroup();
};

#endif
