#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
#pragma config(Sensor, in2,    Potentio,         sensorPotentiometer)
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
#include "./follow_line.c";


/*----------------------------------------------------------------------------------------------------*\
|*                               - Verkefni 6 Bergur og Kristberg -                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*   In this assignment we programmed the robot to follow a line and then grab a pipe, pick that pipe *|
|*   up then follow the line again and then trop the pipe in a box.     												      *|
\*----------------------------------------------------------------------------------------------------*/

task main(){
	StartTask(fail_safe);
	while(true){
		if(vexRT[Btn5U]){
			StartTask(followLine);
		}
		if(vexRT[Btn5D]){
			StopTask(followLine);
		}
	}
}


































































//}
