const float TURNBASE =3.5;
const int DRIVETIME = 1000;
void resetEncoder(){//Resets the encoders
	SensorValue[QuadEncLeft]=0;
	SensorValue[QuadEncRight]=0;
}
void turn(int deg, bool leftRight){
	while(deg*TURNBASE > abs(SensorValue[QuadEncRight])){
		if(leftRight){//turns right
			motor[leftMotor]=60;
			motor[rightMotor]=-60;
		}
		else{ // turns left
			motor[leftMotor]=-60;
			motor[rightMotor]=60;
		}
	}
	motor[leftMotor]=0;
	motor[rightMotor]=0;
}

void closeClaw(){
	motor[clawMotor] = -60;
	wait1Msec(800);
}


void openClaw(){
	motor[clawMotor] = 60;
	wait1Msec(800);
}

void armDown(){
	while(SensorValue(Potentio) < 1900){
		motor[armMotor] = 30;
	}
	motor[armMotor] = 0;
}

void armUp(){
	while(SensorValue[Potentio] > 1400){
		motor[armMotor] = -40;
	}
	motor[armMotor] = 0;
}

void drive_line(){
	int threshold = 505;
	while(SensorValue(sonarSensor) > 20 || SensorValue(sonarSensor)==-1)
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


void drive(int dist,bool bf){
int multiplier = (bf)?(1):(-1);
	while( dist > abs(SensorValue[QuadEncLeft])){
		if(abs(SensorValue[QuadEncLeft]) == abs(SensorValue[QuadEncRight])) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[leftMotor] = 80*multiplier;		    // Right Motor is run at power level 80
			motor[rightMotor]  = 80*multiplier;		    // Left Motor is run at power level 80

		}
		else if(abs(SensorValue[QuadEncLeft]) > abs(SensorValue[QuadEncRight]))	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[leftMotor] = 80*multiplier;		    // Right Motor is run at power level 60
			motor[rightMotor]  = 40*multiplier;		    // Left Motor is run at power level 80

		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[leftMotor] = 60*multiplier;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 100*multiplier;		    // Left Motor is run at power level 60

		}
	}
}
void drive_forward(int i){
	motor[rightMotor] = 90;
	motor[leftMotor]  = 90;
	wait1Msec(DRIVETIME*i);
}

void drive_backwards(int i){
	motor[rightMotor] = -90;
	motor[leftMotor]  = -90;
	wait1Msec(DRIVETIME*i);

}
