#include "config.hpp"
#include "main.h"
#include "okapi/api.hpp"

bool tray_used = false;

void op_arm_high(){
  pros::lcd::print(4, "Arm: Active");
  tray_used = true;
  tray.move_absolute(-900, 150);
  pros::delay(500);
  arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  arm.move_absolute(-2780, 201);
  while(master.get_digital(DIGITAL_X)){
    pros::delay(2);
  }
}

void op_arm_mid(){
  pros::lcd::print(4, "Arm: Active");
  tray_used = true;
  tray.move_absolute(-900, 150);
  pros::delay(700);
  arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  arm.move_absolute(-2100, 200);
  while(master.get_digital(DIGITAL_Y)){
    pros::delay(2);
  }
}

void op_arm_low() {
  tray_used = true;
  // okapi::MotorGroup intakes({15, 17});
  // tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  arm.move_absolute(0, 200);
  pros::delay(700);
  tray.move_absolute(0, 200);
  while(master.get_digital(DIGITAL_B)){
    pros::delay(2);
  }

  arm.move_velocity(0);
  tray.move_velocity(0);
  tray.tare_position();
  arm.tare_position();
}
