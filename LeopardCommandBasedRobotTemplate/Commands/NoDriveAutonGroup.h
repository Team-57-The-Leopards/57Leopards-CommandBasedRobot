#ifndef NODRIVEAUTONGROUP_H
#define NODRIVEAUTONGROUP_H

#include "Commands/CommandGroup.h"
#include "AutonFireGroup.h"
#include "AngleSetGroup.h"
#include "AngleEnableCommand.h"
#include "ShooterDisableCommand.h"
#include "ShooterEnableCommand.h"
#include "ShooterSetpointCommand.h"
#include "GotoLoadGroup.h"
#include "DriveTimeCommand.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class NoDriveAutonGroup: public CommandGroup {
public:	
	NoDriveAutonGroup();
	NoDriveAutonGroup(int num);
};

#endif
