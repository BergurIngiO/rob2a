/*----------------------------------------------------------------------------------------------------*\
|*                               - Verkefni 2 hluti 3 Bergur og Kristberg -                           *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*   This program runs the 3rd part of assignment 2. When the program runs the robot drives forwards  *|
|*   500cm then turns left 90° then forwards again then turns 90° right and again forwards 500cm      *|
|*   then turns right again 90° and then finishes by driving 500cm forwards again.                    *|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/

#pragma config(Sensor, in1,    lightSens,      sensorReflection)
#pragma config(Sensor, in2,    Potent,         sensorPotentiometer)
#pragma config(Sensor, in3,    lineSLeft,      sensorLineFollower)
#pragma config(Sensor, in4,    lineSmiddle,    sensorReflection)
#pragma config(Sensor, in5,    lineSRight,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  QuadEncRight,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  QuadEncLeft,       sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonar1,         sensorSONAR_cm)
#pragma config(Sensor, dgtl11, touch,          sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)

#include "./functions/motor_functions.c";  //We include the file motor_functions to get the drive and turn funtions

task main()
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

}
