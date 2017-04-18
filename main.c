#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorNone, openLoop)
#pragma config(Motor,  port7,           liftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm - 1 Remote -                            *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses both the Left and the Right joysticks to run the robot using "tank control".    *|
|*  The Group 6 buttons on the top-right of the VEXnet Joystick are used to raise and lower an arm.   *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 1          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 10          leftMotor            VEX Motor           Left motor                     *|
|*    Motor - Port 6          armMotor             VEX Motor           Arm motor    
|*    Motor - Port 7          liftMotor             VEX Motor          Lift Motor                     *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task main()
{

int threshold = 10;
int threshold2 = 50;
bool slowMode = 0;
float speedMod = 1;

  while(1 == 1)
  {
    //Driving Motor Control
    /*motor[leftMotor] = vexRT[Ch3] / 2;//old direct drive
    motor[rightMotor] = vexRT[Ch2] / 2;*/
    
    if(vexRT[Btn6U])
    {
    	speedMod = 0.5;
    }
    else
    {
    	speedMod = 1;
    }
    	

     if(abs(vexRT[Ch3]) < threshold)         // If the left joystick is greater than or less than the threshold:
    {
      motor[leftMotor]  = speedMod*(vexRT[Ch3]);   // Left Joystick Y value / 2.
    }
    else if (abs(vexRT[Ch3])< threshold2)
    {
        motor[leftMotor] = speedMod*(vexRT[Ch3])/2;
    }
    else
    {
        motor[leftMotor]  = speedMod*(vexRT[Ch3]);
    }
  

    if(abs(vexRT[Ch2]) < threshold)         // If the right joystick is greater than or less than the threshold:
    {
      motor[rightMotor] = speedMod*(vexRT[Ch2]);   // Right Joystick Y value / 2.
    }
     else if (abs(vexRT[Ch2])< threshold2)
    {
        motor[rightMotor] = speedMod*(vexRT[Ch2])/2;
    }
    else
    {
        motor[rightMotor] = speedMod*(vexRT[Ch2]);
    }
    

    //Arm Control
    if(vexRT[Btn7U] == 1)
    {
      motor[armMotor] = 40;
    }
    else if(vexRT[Btn7D] == 1)
    {
      motor[armMotor] = -40;
    }
    else
    {
    	motor[armMotor] = 0;
    }
    //lift control
   if(vexRT[Btn8D] == 1)
    {
      motor[liftMotor] = 40;
    }
    else if(vexRT[Btn8U] == 1)
    {
      motor[liftMotor] = -40;
    }
    else
    {
    	motor[liftMotor] = 5;
    }
    
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
