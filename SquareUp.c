#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor1,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
task main()
{
//forward
motor[leftMotor] = 70;
motor[rightMotor] = 70;
wait1Msec(6000);
motor[leftMotor] = 0;
motor[rightMotor] = 0;

//back up tiny bit

//left (turn right wheel back up)

motor[leftMotor] = -20;
motor[rightMotor] = 60;
wait1Msec(1000);
motor[leftMotor] = 0;
motor[rightMotor] = 0;

//square back
motor[leftMotor] = -60;
motor[rightMotor] = -60;
wait1Msec(1000);
motor[leftMotor] = 0;
motor[rightMotor] = 0;


}
