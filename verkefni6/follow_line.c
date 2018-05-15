

#include "./functions/motor_functions.c";

int globalCounter = 0;
task fail_safe()
{
	while(true)
	{
		if(vexRT[Btn7L] == 1)
		{
			StopAllTasks();
		}
		if(SensorValue(touch) == 1){
			StopAllTasks();
		}
	}
}


task followLine()
{

	drive_line();

	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	armDown();
	closeClaw();
	motor[clawMotor] = 0;
	armUp();
	resetEncoder();
	wait1Msec(1000);
	turn(150,false);
	wait1Msec(1000);

	drive_line();

	openClaw();
	motor[clawMotor] = 0;
	StopTask(followLine);
}
