#ifndef ANGLESETGROUP_H
#define ANGLESETGROUP_H
#include "AngleEnableCommand.h"
#include "AngleSetpointCommand.h"
#include "AngleDisableCommand.h"
#include "../CommandBase.h"

#include "Commands/CommandGroup.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class AngleSetGroup: public CommandGroup {
public:	
	AngleSetGroup();
	AngleSetGroup(int num);
};

#endif
