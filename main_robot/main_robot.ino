#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <NewPing.h>
#include <NewServo.h>
#include <PLab_ZumoMotors.h>


ZumoMotors motors;

void setup() {
  setupAttack();
}

void loop() {
  findAndAttack(18);

}
