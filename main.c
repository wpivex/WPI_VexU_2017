#pragma config(Sensor, in1,    mg_pot,         sensorPotentiometer)
#pragma config(Sensor, in2,    lift_pot,       sensorNone)
#pragma config(Sensor, in3,    fb_pot,         sensorNone)
#pragma config(Sensor, dgtl1,  upperLimit,     sensorTouch)
#pragma config(Sensor, dgtl2,  lowerLimit,     sensorTouch)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           LMG,           tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           R4B,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           FRD,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           BRD,           tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           L4B,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           RL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           BLD,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           FLD,           tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          RMG,           tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define MAIN_DEFINE 1

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

#define MAX_VOLTAGE 127

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "Drive.c"
#include "PID_DriveV2.c"
#include "MobileGoal.c"
#include "Auto.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	bStopTasksBetweenModes = true;
}

void runLift(int voltage){
	motor[RL] = motor[LL] = removeDeadband(voltage);
}

void run4Bar(int voltage){
	motor[L4B] = motor[R4B] = voltage;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	// ..........................................................................
	// Insert user code here.
	// ..........................................................................
	driveDistance(24);

	delay(10000);
	rightDrive(127);
	leftDrive(127);
	delay(1000);
	rightDrive(0);
	leftDrive(0);
}



/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
float aaaGyro, aaaLeftEnc, aaaRightEnc, aaapot;
task usercontrol()
{
	// User control code here, inside the loop

	startTask(PID_Drive);
	startTask(mg_intake);
	clearTimer(T1);

	while (true)
	{
		aaaPot = SensorValue(mg_pot);
		aaaGyro = getGyro();
		aaaLeftEnc = SensorValue(leftEncoder);
		aaaRightEnc = SensorValue(rightEncoder);
		if(vexRT(Btn7L)){
			driveDistance(24);
			} else if (vexRT(Btn7R) && abs(vexRT(Ch1)) < 25){
			turnAngle(90);
			} else {
			arcadeDrive();
			isDriving = false;
			isTurning = false;
		}

		if(vexRT(Btn6U) && (!SensorValue[upperLimit])){
			//mobileGoal(127);
			mg_up();
		}
		else if(vexRT(Btn6D) && ( !SensorValue[lowerLimit] || SensorValue[upperLimit])){
			//mobileGoal(-127);
			mg_down();
		}
		else{
			//mobileGoal(0);
		}

		if(vexRT[Btn5U]){
			if (time1[T1] < 500){
				runLift(80);
			}
			else{
				runLift(127);
			}
		}
		else if(vexRT[Btn5D]){
			runLift(-127);
		}
		else {
			clearTimer(T1);
			runLift(0);
		}

		if(vexRT[Btn8U]){
			run4Bar(127);
		}
		else if(vexRT[Btn8D]){
			run4Bar(-127);
		}
		else{
			run4Bar(0);
		}

		if (vexRT[Btn7L]){
			simple_auto(false);
		}
		if(vexRT[Btn7D]){
			resetEncoders();
		}

		// This is the main execution loop for the user control program.
		// Each time through the loop your program should update motor + servo
		// values based on feedback from the joysticks.

		// ........................................................................
		// Insert user code here. This is where you use the joystick values to
		// update your motors, etc.
		// ........................................................................
	}
}
