//---------------------------------------
// Include the Arduino Stepper Library
#include <Stepper.h>
#include <Servo.h>
#include <Adafruit_MotorShield.h>

// Define variables:
const int servoPin = 10;               // Gripper (servo)
const int FSR_sensorPin = A0;          // FSR (1 sensor) gripper

Servo myservo;                         // Servo (object)  

//-----------------------------------------
void setup() {
  //Serial Port begin
  Serial.begin (9600);

  //Gripper Servo
  myservo.write(0);         // Set the Gripper to zero (Open)
  myservo.attach(servoPin);
}
//-----------------------------------------
void loop() {
  //Gripper Executions
  Serial.println("Open gripper");
  openGripper();           // Call for Open Gripper
  delay(1000);
  Serial.println("Close gripper");
  closeGripper();          // Call for Close Gripper 
  delay(1000);
}
//-----------------------------------------
void openGripper() {
 // myservo.attach(servoPin);
  myservo.write(0); // Go to open position
  delay(1000);
}

void closeGripper() {
  int force;

  myservo.write(150);
  delay(1000);

}
//-----------------------------------------
