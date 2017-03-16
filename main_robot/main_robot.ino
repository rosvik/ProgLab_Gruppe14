
#include <NewPing.h>
#include <NewServo.h>
#include <PLab_ZumoMotors.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

ZumoMotors motors;

void setup() {
  bluetooth_communication_setup();
  setupAttack();
void setup()
{
 button.waitForButton();
 initSensors();
void loop() {
  findAndAttack(18);
  bluetooth_communication_loop();  
}

void loop()
{
  lineTrackerLoop();
}

#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#include <NewPing.h>
#include <NewServo.h>
#include <PLab_ZumoMotors.h>
void setup()
{
 button.waitForButton();
 initSensors();

ZumoMotors motors;

void setup() {
  bluetooth_communication_setup();
  setupAttack();
void loop()
{
  lineTrackerLoop();
}

void loop() {
  findAndAttack(18);
  bluetooth_communication_loop();  
}
