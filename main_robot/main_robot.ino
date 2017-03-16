#include <ZumoMotors.h>
#include <Pushbutton.h>

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);

void setup() {
  // put your setup code here, to run once:
  // Sander tester Git
  //bluetooth_connector_setup();
  bluetooth_communication_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  //bluetooth_connector_loop();
  bluetooth_communication_loop();  
}
