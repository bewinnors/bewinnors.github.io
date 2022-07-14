#include <Wire.h>
#include <Adafruit_MotorShield.h>
// #include "utility/Adafruit_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

void setup() {
  AFMS.begin();
  myMotor->setSpeed(60);
  myMotor->release();
}

void loop() {

  while(1){
    myMotor->step(30,FORWARD,SINGLE);
    delay(1000);
    }

}
