
#include "main.h"
#include "config.hpp"
#include "drive.hpp"
#include "okapi/api.hpp"
//#include "tray.hpp"
//#include "cofig.cpp"
int red_big = 1;
int blue_big = 2;
int red_small = 3;
int blue_small = 4;


int side = red_small; // Side robot is starting


void buddimoto(){

  arm.move_velocity(-100);
  pros::delay(100);
  arm.move_velocity(0);

    arm.move_velocity(100);
    pros::delay(200);
    arm.move_velocity(10);
    //pros::Task drive_task(driveTask);
    //pros::Task turn_task(turnTask);

    intake.move_velocity(0);
     intake2.move_velocity(0);

     // Full speed intake
     intake.move_velocity(200);
     intake2.move_velocity(200);

     // Drive straight
     if((side == 3)||(side == 4))
     drive_pid(3300, 50);
     if ((side == 1)||(side == 2)){
       drive_pid(3300, 200);
     }

     // Slow down intake


     // Reverse
     if((side == 3)||(side == 4)){rev_pid(2200,50);}
     pros::delay(300);
     arm.move_velocity(0);
     // Turn
     if (side == 3){turn_r(712, 60);}
     if(side == 2){turn_r(810, 90);}
     if(side == 4){turn_l(777, 60);}
     if(side == 1){turn_l(777, 90);}


     pros::delay(900);

     // Intake last cube for vertcal stacks
     if ((side == 1)||(side == 2)){
       driveleft_T.set_reversed(true);
       driveleft_B.set_reversed(true);
     intake.move_velocity(175);
     intake2.move_velocity(175);
     driveleft_T.tare_position();
     driveleft_B.move_relative(-2975, 70);
    driveleft_T.move_relative(-2975, 70);
    driveright_B.move_relative(-2975, 70);
    driveright_T.move_relative(-2975, 70);
    while (driveleft_T.get_position() > -2950){
      pros::delay(2);
    }
  } else {
    driveleft_T.set_reversed(true);
    driveleft_B.set_reversed(true);
    driveleft_B.move_relative(-700, 70);
   driveleft_T.move_relative(-700, 70);
   driveright_B.move_relative(-700, 70);
   driveright_T.move_relative(-700, 70);
   pros::delay(1000);
  }

     // Reconfigre motors for encoders instead of pid because bot might get stuck in a loop

     // Drives forward into the corner


     // Slowly stops outaking
     intake.move_velocity(-50);
     intake2.move_velocity(-50);
     pros::delay(600);
     intake.move_velocity(0);
     intake2.move_velocity(0);

     // Moves tray about 90 Deggress
     tray.move_absolute(-3800, 60);
     pros::delay(2250);
     tray.move_absolute(-3800, 40);
     pros::delay(100);

     // burr
     intake.move_velocity(-200);
     intake2.move_velocity(-200);
     pros::delay(300);
     intake.move_velocity(0);
     intake2.move_velocity(0);

     // Pause
     pros::delay(100);

     // burrrrr
     intake.move_velocity(-200);
     intake2.move_velocity(-200);
     pros::delay(300);
     intake.move_velocity(0);
     intake2.move_velocity(0);

     // Puts tray down
     pros::delay(500);
     intake.move_velocity(-20);
     intake2.move_velocity(-20);
     tray.move_absolute(0, 30);
     pros::delay(600);

     // Pulls out of the corner
     driveleft_T.move_relative(30, 60);
     driveleft_B.move_relative(30, 60);
     driveright_B.move_relative(30, 60);
     driveright_T.move_relative(30, 60);
     driveleft_T.move_relative(900, 60);
     driveleft_B.move_relative(900, 60);
     driveright_B.move_relative(900, 60);
     driveright_T.move_relative(900, 60);
     tray.move_absolute(0, 100);
     pros::delay(300);
 }


void autonomous() {
  // _driveReset(); // reset the drive encoders
  // pros::Task drive_task(driveTas);
  // pros::Tas turn_tak(turnTask);
  // Deploy code
  //
  // ok
  intake2.set_reversed(true);
  intake.move_velocity(-200);
  intake2.move_velocity(-200);
  pros::delay(1500);
  buddimoto();
}
