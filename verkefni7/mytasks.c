#include "motor_functions2.c";
const int DIST=564;
task fail_safe()
{
	while(true)
	{
		if(vexRT[Btn7L] == 1)
		{
			StopAllTasks();
		}
	}
}


task claw()
{ while(true){
		if(vexRT[Btn6U] == 1)
		{
			motor[clawMotor] = -60;
		}
		if(vexRT[Btn6D] == 1)
		{
			motor[clawMotor] = 60;
		}
		else
		{
			motor[clawMotor] = 0;
		}
	}
}

task arm()
{
	while(true){
		if(vexRT[Btn5U] == 1)
		{
			motor[armMotor] = 127;
		}
		if(vexRT[Btn5D] == 1)
		{
			motor[armMotor] = -127;
		}
		else
		{
			motor[armMotor] = 0;
		}
	}
}

task verkefni3()
{
	StartTask(arm);
	StartTask(claw);
	while(1 == 1)
	{
		if(vexRT[Btn6U] == 1)
		{
			StopTask(arm);
			StartTask(claw);
		}

		if(vexRT[Btn5U] == 1)
		{
			StopTask(claw);
			StartTask(arm);
		}

		motor[rightMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;
		motor[leftMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;
	}
}


task verkefni4()
{
	while(true){
		if(SensorValue(lightSensor) < 300)
		{
			while(SensorValue(sonarSensor) > 35  || SensorValue(sonarSensor) == -1)
			{
					motor[rightMotor] = 63;
					motor[leftMotor]  = 63;
			}
			resetEncoder();
			turn(120,true);
		}
	}
}


task verkefni5()
{
	wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.

	int threshold = 505;      /* found by taking a reading on both DARK and LIGHT    */
	/* surfaces, adding them together, then dividing by 2. */
	while(true)
	{

		// RIGHT sensor sees dark:
		if(SensorValue(lineFollowerRIGHT) > threshold)
		{
			// counter-steer right:
			motor[leftMotor]  = 63;
			motor[rightMotor] = 0;
		}
		// CENTER sensor sees dark:
		if(SensorValue(lineFollowerCENTER) > threshold)
		{
			// go straight
			motor[leftMotor]  = 45;
			motor[rightMotor] = 45;
		}
		// LEFT sensor sees dark:
		if(SensorValue(lineFollowerLEFT) > threshold)
		{
			// counter-steer left:
			motor[leftMotor]  = 0;
			motor[rightMotor] = 63;
		}
	}
}


////+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task verkefni2_hluti2()
{
	wait1Msec(2000);
	for(int i = 1; i < 5; i++){
		resetEncoder();
		drive(i*DIST,true);
		resetEncoder();
		drive(i*DIST,false);
	}
	abortTimeslice();

}


task verkefni2_hluti3()
{
	resetEncoder();			//We reset the encoder
	drive(564, true);   //Make the Robot drive 500cm forwards
	resetEncoder();     //We reset the encoder
	turn(120,true);			//Make the Robot turn 90° IRL
	resetEncoder();     //We reset the encoder
	drive(564, true);   //Make the Robot drive 500cm forwards
	resetEncoder();     //We reset the encoder
	turn(90,false);			//Make the Robot turn 90° IRL
	resetEncoder();     //We reset the encoder
	drive(564, true);   //Make the Robot drive 500cm forwards
	resetEncoder();     //We reset the encoder
	turn(90,false);			//Make the Robot turn 90° IRL
	resetEncoder();     //We reset the encoder
	drive(564, true);   //Make the Robot drive 500cm forwards
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;

}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task verkefni2_hluti1()
{
	for(int i = 1; i < 5; i++){
		drive_forward(i);
		drive_backwards(i);
	}
}


task verkefni6()
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
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	StopTask(verkefni6);
}
