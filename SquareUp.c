#pragma config(Sensor, dgtl1,  Quad1,          sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  Quad2,          sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  Ultrasonic,     sensorSONAR_inch)
#pragma config(Sensor, dgtl7,  bump,           sensorTouch)
#pragma config(Sensor, dgtl8,  bump2,          sensorTouch)
#pragma config(Sensor, dgtl10, LED1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, LED2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, LED3,           sensorLEDtoVCC)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor1,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void driveTillBump(int leftSpeed, int rightSpeed)
{

	motor[leftMotor] = leftSpeed;
	motor[rightMotor] = rightSpeed;


}

void driveTillUltrasonicThenSquare(int leftSpeed, int rightSpeed)
{
	motor[leftMotor] = leftSpeed;
	motor[rightMotor] = rightSpeed;

	while(SensorValue[Ultrasonic]>=10)
	{

}
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	wait1Msec(250);
	motor[leftMotor] = leftSpeed/2;
	motor[rightMotor] = rightSpeed/2;
	wait1Msec(1000);
	motor[leftMotor] = -leftSpeed/2;
	motor[rightMotor] = -rightSpeed/2;
	wait1Msec(250);
	motor[leftMotor] = leftSpeed/2;
	motor[rightMotor] = -rightSpeed/2;
	wait1Msec(500);
	motor[leftMotor] = -leftSpeed/2;
	motor[rightMotor] = -rightSpeed/2;
	while((!SensorValue[bump])&&(!SensorValue[bump2]))
	{}
motor[leftMotor] = 0;
	motor[rightMotor] = 0;

}
task main()
{
	 while (!vexRT[Btn8D])
	{
	}
	driveTillUltrasonicThenSquare(100,100);
/*
  for (int x=0; x<16; x++)
  {
  	if(x%2==1)
  	  SensorValue[LED1] = true;
  	else
  		SensorValue[LED1] = false;

  	if(x%4>=2)
  	  SensorValue[LED2] = true;
  	else
  		SensorValue[LED2] = false;

  	if(x%8>=4)
  	  SensorValue[LED3] = true;
  	else
  		SensorValue[LED3] = false;

  	wait1Msec(150);
  }

//forward
motor[leftMotor] = 50;
motor[rightMotor] = 50;
wait1Msec(2000);
motor[leftMotor] = 0;
motor[rightMotor] = 0;

//back up tiny bit

motor[leftMotor] = -40;
motor[rightMotor] = -40;
wait1Msec(250);

//left (turn right wheel back up)

motor[leftMotor] = -60;
motor[rightMotor] = -20;
wait1Msec(250);
motor[leftMotor] = 0;
motor[rightMotor] = 0;

//square back
motor[leftMotor] = -60;
motor[rightMotor] = -60;
wait1Msec(150);
motor[leftMotor] = 0;
motor[rightMotor] = 0;
*/

}
