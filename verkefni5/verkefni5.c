#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
#pragma config(Sensor, in2,    Potent,         sensorPotentiometer)
#pragma config(Sensor, in3,    lineFollowerCENTER,      sensorLineFollower)
#pragma config(Sensor, in4,    lineFollowerRIGHT,    sensorLineFollower)
#pragma config(Sensor, in5,    lineFollowerLEFT,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  QuadEncRight,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  QuadEncLeft,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl11, touch,          sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorServoContinuousRotation, openLoop)

#include "./motor_functions.c";

/*----------------------------------------------------------------------------------------------------*\
|*                               - Verkefni 5 Bergur og Kristberg -                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*   In this assignment we programmed the robot to follow a line and to have a kill switch on the     *|
|*   controller.																																								      *|
\*----------------------------------------------------------------------------------------------------*/

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


task main()
{
	StartTask(fail_safe);
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
