#include <PLab_ZumoMotors.h>
#include <NewPing.h>
#include <NewServo.h>
#include <PLab_ZumoMotors.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#include <Pushbutton.h>

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
ZumoReflectanceSensorArray sensors;
int speedMode = 400;
int speed = speed;

void setup() {
  Serial.begin(9600);
  bluetooth_communication_setup();
  initSensors();
  setupAttack();
  while(!button.isPressed()) {
    bluetooth_communication_loop();
  }
  speed = speedMode;
  motors.setSpeeds(speedMode,speedMode);
}
void loop() {
  if (!lineTrackerLoop()) {
    findAndAttack();
  }
}
