#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <NewPing.h>
#include <NewServo.h>
#include <PLab_ZumoMotors.h>


ZumoMotors motors;

void setup() {
  bluetooth_communication_setup();
  setupAttack();
}

void loop() {
  findAndAttack(18);
  bluetooth_communication_loop();  
}
