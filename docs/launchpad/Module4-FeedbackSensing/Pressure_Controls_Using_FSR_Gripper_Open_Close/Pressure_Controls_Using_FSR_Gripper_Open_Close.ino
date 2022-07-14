//---------------------------------------
// Include the Arduino Stepper Library
#include <Stepper.h>
#include <Servo.h>
#include <Adafruit_MotorShield.h>

// Define variables:
int position;                          
const int servoPin = 10;               // Gripper (servo)
const int FSR_sensorPin = A0;          // FSR (1 sensor) gripper

Servo myservo;                         // Servo (object)  

//-----------------------------------------
void setup() {
  //Serial Port begin
  Serial.begin (9600);

  //Gripper Servo
  myservo.write(0);         // Set the Gripper to zero (Open)
  position = 0;
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
  myservo.attach(servoPin);
  myservo.write(0); // Go to open position
  position = 0;
}

void closeGripper() {
  int force;

  //myservo.write(130);
  for (position = 0; position < 150; position++) {
    myservo.write(position);
    delay(40);
    force = analogRead(FSR_sensorPin);
    Serial.println(force);
    if (force > 800)    // Change the FSR Pressure Constraint 
      myservo.detach();                     // Stop the Servo from continuing
  }
  
}
//-----------------------------------------
