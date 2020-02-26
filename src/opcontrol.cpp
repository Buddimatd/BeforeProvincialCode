#include "main.h"
#include "functions.hpp"
#include "okapi/api.hpp"
#include "config.hpp"
#include <sstream>

/**

 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	intake2.set_reversed(true);
	std::stringstream ss;
	std::string display;
	intake.set_reversed(false);
	driveleft_B.set_reversed(true);
	driveleft_T.set_reversed(true);
	driveright_T.set_reversed(false);
	driveright_B.set_reversed(false);

	int power;
	int turn;
	int left;
	int right;
	int armpos = arm.get_position();
	int traypower;

	int armpower = 200;
	const double armult = 1;

	bool intakesystem = false;
	bool negIntake = false;
	bool slowmode = false;
	bool army = false;
	bool higharm = false;
	bool traycontrol = true;

	tray.tare_position();
	arm.tare_position();
	tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);



	while(true){
		// Set up stringstream
		ss.str(std::string());

		// Movment codee
		pros::delay(2);
		power = -master.get_analog(ANALOG_LEFT_Y);
		turn = (-master.get_analog(ANALOG_LEFT_X));
		traypower = master.get_analog(ANALOG_RIGHT_Y);
		left = power + turn;
		right = power - turn;

		driveright_T.move(right);
		driveright_B.move(right);
		driveleft_T.move(left);
		driveleft_B.move(left);

		// Intake controls
		if (master.get_digital(DIGITAL_R2)){
			intake.move(200);
			intake2.move(200);
		} else if (master.get_digital(DIGITAL_L2)){
			intake.move(-200);
			intake2.move(-200);
		}
		else if (master.get_digital(DIGITAL_R1)){
			intake.move(50);
			intake2.move(50);
		} else if (master.get_digital(DIGITAL_L1)){
			intake.move(-50);
			intake2.move(-50);
		} else if (((master.get_digital(DIGITAL_R1)) && (master.get_digital(DIGITAL_R1)) && (master.get_digital(DIGITAL_R1)) && (master.get_digital(DIGITAL_R1))) == false ) {
			intake.move(0);
			intake2.move(0);
		}
		// if (master.get_digital(DIGITAL_DOWN) && (intakesystem == true)){
		// 	intakesystem=false;	// Intake motors off
		// 	pros::delay(200);
		// 	}
		// else if (master.get_digital(DIGITAL_DOWN) && (intakesystem == false)){
		// 	intakesystem = true;	// Intake motors on
		// 	pros::delay(200);
		// }
		//
		// if (master.get_digital(DIGITAL_UP) && (negIntake == true)){
		// 	negIntake = false; // Intaking cubes
		// 	pros::delay(200);
		// }
		// else if (master.get_digital(DIGITAL_UP) && (negIntake == false)){
		// 	negIntake = true; // Outputing cubes
		// 	pros::delay(200);
		// }
		//
		// // Toggle slow intake
		// if (master.get_digital(DIGITAL_LEFT) && (slowmode == false)){
		// 	slowmode = true;
		// 	pros::delay(200);
		// }
		// else if (master.get_digital(DIGITAL_LEFT) && (slowmode == true)){
		// 	slowmode = false;
		// 	pros::delay(200);
		// }
		// // Apply logic to the motors
		// if (intakesystem==true && slowmode == false){
		// 	if (negIntake == false) {
		// 		intake.move_velocity(200);
		// 		intake2.move_velocity(200);
		// 	}
		// 	 if (negIntake == true) {
		// 		intake.move_velocity(-200);
		// 		intake2.move_velocity(-200);
		// 	}
		// }
		// else if (intakesystem==true && slowmode == true){
		// 	if (negIntake == false) {
		// 		intake.move_velocity(50);
		// 		intake2.move_velocity(50);
		// 	}//
		// 	 if (negIntake == true) {
		// 		intake.move_velocity(-50);
		// 		intake2.move_velocity(-50);
		// 	}
		// }
		//  if (intakesystem==false){
		// intake.move_velocity(0);
		// intake2.move_velocity(0);
		// }

		// Reset trays internal position value

	// Makes tray actively hold in place

		// Set up values for display
		if (master.get_digital(DIGITAL_X) && !army){
			army = true;
			higharm = true;
			pros::delay(200);
		} else if (master.get_digital(DIGITAL_X) && army){
			army = false;
			pros::delay(200);
		}
		if (master.get_digital(DIGITAL_Y) && !army){
			army = true;
			higharm = false;
			pros::delay(200);
		} else if (master.get_digital(DIGITAL_Y) && army){
			army = false;
			pros::delay(200);
		}

		// Move arm and tray for competsation
		if (master.get_digital(DIGITAL_X) ){
			op_arm_high();
		} if (master.get_digital(DIGITAL_Y)){
			op_arm_mid();
		} if (master.get_digital(DIGITAL_B)){
			op_arm_low();
		} else{
			tray.move(-traypower);

			// arm adjust
			if (master.get_digital(DIGITAL_UP)){
				arm.move(-120);
			}
			else if (master.get_digital(DIGITAL_DOWN)){
				arm.move(120);

			} else if ((!(master.get_digital(DIGITAL_UP))) and (!(master.get_digital(DIGITAL_DOWN)))){
				arm.move_velocity(0);
			}

			if (master.get_analog(ANALOG_LEFT_Y) < -100){
				tray.tare_position();
			}

		}
}
}




	// if (armpower){
	// 	float traypower = armpower * 1.2;
	// 	if (traypower > 127) traypower = 127;
	// 	if (traypower < -127) traypower = -127;
	// 	if ((tray.get_position() > 940)){
	// 			tray.move_absolute(930, 150);
	// 			traypower = 0;
	// 			pros::delay(200);
	// 		}
	// 		else{
	//
	// 			tray.move((int)traypower);
	// 		}
	// 		arm.move(armpower);


		// if(armpower > 0){
		// 	arm.move_velocity(0);
		// 	tray.move_velocity(0);
		// }



		//if tray.get_position()






		// Shows controller output to screen
		// pros::lcd::print(0, "X: %d Y: %d", turn, power);
		// //master.set_text(1, 0, "X: %d Y: %d", turn, power);
		// if (slowmode){
		// 	ss << "S";
		//
		// }else {
		// 	ss << "F";
		// }
		// if (intakesystem == true) {
		// 		pros::lcd::print(1, "Intake status: Active" );
		//
		// 	}
		// if (intakesystem == false){
		// 		pros::lcd::print(1, "Intake status: Inactive" );
		//
		// }
		// 	if (negIntake == true) {
		// 			pros::lcd::print(2, "Intake Negative Status: Negative" );
		// 			ss << "O";
		// 		}
		// 	if (negIntake == false){
		// 			pros::lcd::print(2, "Intake Negative Status: " );
		// 			ss << "I";
		// 		}
		// 		pros::lcd::print(3, "Gyrpo: %d", gyro.get_value());
		// 	//	master.set_text(2, 2, "G: %d", gyro.get_value());
		// 	display = ss.str();
		// 	master.set_text(2, 0,	display.c_str());
		// 	//std::cout << "Gyro: " << gyro.get_value() << std::endl;
		// }


		//master.set_text(0,0,"hey buddima");
