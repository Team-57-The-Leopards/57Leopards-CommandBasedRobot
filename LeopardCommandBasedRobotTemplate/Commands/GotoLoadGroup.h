#ifndef GOTOLOADGROUP_H
#define GOTOLOADGROUP_H

#include "Commands/CommandGroup.h"
#include "AngleEnableCommand.h"
#include "AngleSetpointCommand.h"
#include "AngleDisableCommand.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class GotoLoadGroup: public CommandGroup {
public:	
	GotoLoadGroup();
};

#endif
