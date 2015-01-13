#include "NoDriveAutonGroup.h"

NoDriveAutonGroup::NoDriveAutonGroup() {
	NoDriveAutonGroup(1);
}
	NoDriveAutonGroup::NoDriveAutonGroup(int num) {
        // Add Commands here:
        // e.g. AddSequential(new Command1());
        //      AddSequential(new Command2());
        // these will run in order.

        // To run multiple commands at the same time,
        // use AddParallel()
        // e.g. AddParallel(new Command1());
        //      AddSequential(new Command2());
        // Command1 and Command2 will run in parallel.

        // A command group will require all of the subsystems that each member
        // would require.
        // e.g. if Command1 requires chassis, and Command2 requires arm,
        // a CommandGroup containing them would require both the chassis and the
        // arm.
		AddSequential(new ShooterRetractCommand());
	    AddSequential(new ShooterEnableCommand());
	    AddSequential(new ShooterSetpointCommand(num));
	    AddSequential(new AngleSetGroup(num));
	    AddSequential(new AngleEnableCommand());
	    AddSequential(new WaitCommand(1.0));
	    AddSequential(new AutonFireGroup(num));
	    AddSequential(new AutonFireGroup(num));
	    AddSequential(new AutonFireGroup(num));
	    AddSequential(new ShooterDisableCommand());
		AddParallel(new ShooterExtendCommand());
	    AddSequential(new WaitCommand(1.0));
	    AddParallel(new GotoLoadGroup());
	    AddSequential(new DriveTimeCommand(3.0, 0.6, 0));
}
