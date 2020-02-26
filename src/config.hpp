#include "main.h"
#include "okapi/api.hpp"


extern pros::Controller master;
extern pros::Motor driveleft_B;
extern pros::Motor driveright_B;
extern pros::Motor driveleft_T;
extern pros::Motor driveright_T;
extern pros::Motor intake;
extern pros::Motor intake2;
extern pros::Motor tray;
extern pros::Motor arm;
extern pros::ADIDigitalIn limit;
extern pros::ADIGyro gyro;
extern pros::ADIUltrasonic sensor;
extern pros::Task tUpdateActualGyro;
extern double gyroActual;
