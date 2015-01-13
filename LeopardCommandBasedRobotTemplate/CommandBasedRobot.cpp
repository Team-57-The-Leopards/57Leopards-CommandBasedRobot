#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/NoDriveAutonGroup.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	DriverStationLCD *dsLCD;
	SmartDashboard *smarty;
	SendableChooser *autoChooser;
	Compressor *pump;
	Timer *dataTimer;
	
	
public: CommandBasedRobot(void)
{
	dsLCD = DriverStationLCD::GetInstance();
	pump = new Compressor(ch_PressureSwitch, ch_PumpRelay);
	dataTimer = new Timer();
	autoChooser = new SendableChooser();
}
	
	virtual void RobotInit() {
		CommandBase::init();
		autoChooser = new SendableChooser();
		autoChooser->AddDefault("No Drive, Back Pyramid", new NoDriveAutonGroup(1));
		autoChooser->AddObject("No Drive, Back Corner", new NoDriveAutonGroup(4));
		pump->Start();
		Joystick *shtStick = CommandBase::oi->GetShootJoystick();
		SmartDashboard::PutNumber("X Axis", shtStick->GetX());
		SmartDashboard::PutNumber("Y Axis", shtStick->GetY());
		SmartDashboard::PutNumber("Z Axis", shtStick->GetZ());
		SmartDashboard::PutNumber("Shooter", CommandBase::shooter1->GetSetpoint());
		SmartDashboard::PutNumber("Angle", CommandBase::shooterAngle->GetSetpoint());
		SmartDashboard::PutNumber("Select", CommandBase::shootSelect);
		SmartDashboard::PutData("SchedulerData", Scheduler::GetInstance());
		SmartDashboard::PutData("Auto Mode Chooser", autoChooser);
		
		autonomousCommand = NULL;
		lw = LiveWindow::GetInstance();
	}
	
	virtual void AutonomousInit() {
		autonomousCommand = (Command*) autoChooser->GetSelected();
		autonomousCommand->Start();
		dataTimer->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();

		if(dataTimer->HasPeriodPassed(0.1))
		{
			dsLCD->Clear();
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line1,"Angle FB: %f", CommandBase::shooterAngle->ReturnAngle());
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line2,"Angle St: %f", CommandBase::shooterAngle->GetSetpoint());
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line3,"Angle Cm: %f", CommandBase::shooterAngle->GetOutput());
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line4,"%d %d %d", (int)CommandBase::shooter1->ReturnRPM(), (int)CommandBase::shooter2->ReturnRPM(), (int)CommandBase::shooter3->ReturnRPM());
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line5,"%d %d %d", (int)CommandBase::shooter1->GetSetpoint(), (int)CommandBase::shooter2->GetSetpoint(), (int)CommandBase::shooter3->GetSetpoint());
			dsLCD->UpdateLCD();
			
			SmartDashboard::PutNumber("Shooter", CommandBase::shooter1->GetSetpoint());
			SmartDashboard::PutNumber("Angle", CommandBase::shooterAngle->GetSetpoint());
			SmartDashboard::PutNumber("Select", CommandBase::shootSelect);
			dataTimer->Reset();
		}
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if(autonomousCommand != NULL)
			autonomousCommand->Cancel();
		dataTimer->Start();
		dataTimer->Reset();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
		Joystick *shtStick = CommandBase::oi->GetShootJoystick();
		
		for(int i=1; i<=5; i++)
		{
			if(shtStick->GetRawButton(i))
				CommandBase::shootSelect = i;
		}
		if(shtStick->GetRawButton(6))
			CommandBase::shootSelect = 7;
		
		if(dataTimer->HasPeriodPassed(0.1))
		{
			dsLCD->Clear();
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line1,"Angle FB: %f", CommandBase::shooterAngle->ReturnAngle());
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line2,"Angle St: %f", CommandBase::shooterAngle->GetSetpoint());
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line3,"Angle Cm: %f", CommandBase::shooterAngle->GetOutput());
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line4,"%d %d %d", (int)CommandBase::shooter1->ReturnRPM(), (int)CommandBase::shooter2->ReturnRPM(), (int)CommandBase::shooter3->ReturnRPM());
			dsLCD->PrintfLine(DriverStationLCD::kUser_Line5,"%d %d %d", (int)CommandBase::shooter1->GetSetpoint(), (int)CommandBase::shooter2->GetSetpoint(), (int)CommandBase::shooter3->GetSetpoint());
			dsLCD->UpdateLCD();
			
			SmartDashboard::PutNumber("X Axis", shtStick->GetX());
			SmartDashboard::PutNumber("Y Axis", shtStick->GetY());
			SmartDashboard::PutNumber("Z Axis", shtStick->GetZ());
			SmartDashboard::PutNumber("Shooter", CommandBase::shooter1->GetSetpoint());
			SmartDashboard::PutNumber("Angle", CommandBase::shooterAngle->GetSetpoint());
			SmartDashboard::PutNumber("Select", CommandBase::shootSelect);
			dataTimer->Reset();
		}
		
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

