#include "main.h"


pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor driveleft_B(14, pros::E_MOTOR_GEARSET_18, false,
                        pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveright_B(15, pros::E_MOTOR_GEARSET_18, false,
                         pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveleft_T(2, pros::E_MOTOR_GEARSET_18, false,
                       pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveright_T(5, pros::E_MOTOR_GEARSET_18, false,
                         pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(12, pros::E_MOTOR_GEARSET_36, false,
                   pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake2(21, pros::E_MOTOR_GEARSET_36, false,
                    pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor tray(3, pros::E_MOTOR_GEARSET_36, true,
                     pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor arm(9, pros::E_MOTOR_GEARSET_36, false,
                pros::E_MOTOR_ENCODER_COUNTS);
pros::ADIGyro gyro(1);
//pros::ADIUltrasonic sensor(7, 8);
