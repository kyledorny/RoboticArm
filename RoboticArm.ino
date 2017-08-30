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

}

void loop() {

  stepper1.moveToPositionInRevolutions(-1.5);
  stepper1.moveToPositionInRevolutions(1.5);
}
