#include "mbed.h"

#include "bbcar.h"


Ticker servo_ticker;

PwmOut pin5(D5), pin6(D6);


BBCar car(pin5, pin6, servo_ticker);


int main() {

   // please contruct you own calibration table with each servo
   // left servo
   double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table0[] = {-15.386, -14.828, -13.632, -10.603, -4.943, 0.000, 6.059, 11.400, 14.031, 14.988, 15.386};

   // right servo
   double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table1[] = {-16.183, -15.785, -14.669, -11.799, -5.820, 0.000, 5.979, 11.639, 14.669, 15.705, 16.263};



   // first and fourth argument : length of table

   car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);


   while (1) {

      car.goStraightCalib(5);

      ThisThread::sleep_for(5s);

      car.stop();

      ThisThread::sleep_for(5s);

   }

}