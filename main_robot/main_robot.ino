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

void setup() {
  bluetooth_communication_setup();
  initSensors();
  setupAttack();
}
void loop() {
  findAndAttack(1);
  bluetooth_communication_loop();  
  lineTrackerLoop();
}
