void corner_pass(bool is_long){
	set_odom(-137, 16, 30);
	driveDistance(-16);
	turnAngle(-105);
	driveDistance(-20);
	turnAngle(-120);
	driveDistance(22);
	SensorValue[intake_piston] = 0;
	wait1Msec(400);
	CB_setpoint = CB_top_setpoint;
	target_p.p_x = 12;
	target_p.p_y = 90;
	driveDistance(0);
	set_outer_goal(gs_down);
	target_p.p_y = 105;
	driveDistance(0);
	SensorValue[intake_piston] = 1;
	turnAngle(0);
	set_inner_goal(gs_up);
	wait1Msec(400);
	driveDistance(-5);
	CB_setpoint = CB_bottom_setpoint;
	driveDistance(10);
	SensorValue[intake_piston] = 0;
	wait1Msec(400);
	CB_setpoint = CB_top_setpoint;
	turnAngle(45);
	SensorValue[intake_piston] = 1;




	//driveDistance(25);
 	// SensorValue[intake_piston] = 0;
	//delay(1000);
 	// CB_setpoint = CB_top_setpoint;
	//turnAngle(35);
	//driveDistance(30);
 	// SensorValue[intake_piston] = 1;

	//delay(2000);
	//driveDistance(0);
	//delay(2000);
	//turnAngle(-90);
	//delay(2000);
	//driveDistance(-27);
	//delay(2000);
	//turnAngle(-135);
}
