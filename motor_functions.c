const float TURNBASE =3.5;
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
