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
#include "mytasks.c";



task main()
{
	StartTask(fail_safe);
	while(true){
		//hluti 1 i verkefni 2
		if(vexRT[Btn8D]==1){
			StopTask(verkefni2_hluti2);
			StopTask(verkefni2_hluti3);
			StopTask(verkefni3);
			StopTask(verkefni4);
			StopTask(verkefni5);
			StopTask(verkefni6);
			StartTask(verkefni2_hluti2);
		}



		//hluti 2 i verkefni 2
		if(vexRT[Btn8L]==1){
			StopTask(verkefni2_hluti1);
			StopTask(verkefni2_hluti3);
			StopTask(verkefni3);
			StopTask(verkefni4);
			StopTask(verkefni5);
			StopTask(verkefni6);
			StartTask(verkefni2_hluti2);
		}



		//hluti 3 i verkefni 2
		if(vexRT[Btn8U]==1){
			StopTask(verkefni2_hluti1);
			StopTask(verkefni2_hluti2);
			StopTask(verkefni3);
			StopTask(verkefni4);
			StopTask(verkefni5);
			StopTask(verkefni6);
			StartTask(verkefni2_hluti3);
		}



		//Verkefni 3
		if(vexRT[Btn8R]==1){
			StopTask(verkefni2_hluti1);
			StopTask(verkefni2_hluti2);
			StopTask(verkefni2_hluti3);
			StopTask(verkefni4);
			StopTask(verkefni5);
			StopTask(verkefni6);
			StartTask(verkefni3);
		}



		//Verkefni 4
		if(vexRT[Btn7R]==1){
			StopTask(verkefni2_hluti1);
			StopTask(verkefni2_hluti2);
			StopTask(verkefni2_hluti3);
			StopTask(verkefni3);
			StopTask(verkefni5);
			StopTask(verkefni6);
			StartTask(verkefni4);
		}



		//Verkefni 5
		if(vexRT[Btn7D]==1){
			StopTask(verkefni2_hluti1);
			StopTask(verkefni2_hluti2);
			StopTask(verkefni2_hluti3);
			StopTask(verkefni3);
			StopTask(verkefni4);
			StopTask(verkefni6);
			StartTask(verkefni5);
		}
		
		
		//Verkefni 6
		if(vexRT[Btn7U]==1){
			StopTask(verkefni2_hluti1);
			StopTask(verkefni2_hluti2);
			StopTask(verkefni2_hluti3);
			StopTask(verkefni3);
			StopTask(verkefni4);
			StopTask(verkefni5);
			StartTask(verkefni6);
		}
	}
}
