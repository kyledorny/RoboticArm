#include "SpeedyStepper.h"

SpeedyStepper stepper1;

const int microstepping = 8;
const float stepperSpeed = .25;
const float acceleration = .5;
const float transmission = 2;

void setup() {
  stepper1.connectToPort(1);

  stepper1.setStepsPerRevolution(200 * microstepping * transmission);
  stepper1.setSpeedInRevolutionsPerSecond(stepperSpeed);
  stepper1.setAccelerationInRevolutionsPerSecondPerSecond(acceleration);
 
 homing();
}

void loop() {

if(!digitalRead(A2)){
  moveMagnetTallToShort(1000);
}

delay(2000);

if(!digitalRead(A3)){
  moveMagnetShortToTall(1000);
}

delay(2000);

}

void homing() {
   const int directionTowardHome = 1;
  const float speedInRevolutionsPerSecond = .25;
  const float maxDistanceToMoveInRevolutions = 1.5;
  const byte homeSwitchPin = A1;

  stepper1.moveToHomeInRevolutions(directionTowardHome, speedInRevolutionsPerSecond, maxDistanceToMoveInRevolutions, homeSwitchPin);
}

void moveMagnetShortToTall(int pickupTime) {
  stepper1.moveToPositionInRevolutions(-.575);
  delay(pickupTime);
  stepper1.moveToPositionInRevolutions(-.75);
  delay(pickupTime);
  stepper1.moveToPositionInRevolutions(0);

}
 void moveMagnetTallToShort(int pickupTime) {
   stepper1.moveToPositionInRevolutions(-.75);
  delay(pickupTime);
  stepper1.moveToPositionInRevolutions(-.575);
  delay(pickupTime);
  stepper1.moveToPositionInRevolutions(0);

 }

