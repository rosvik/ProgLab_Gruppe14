/*
 */

#include <SoftwareSerial.h>
#include <PLabBTSerial.h>

#define txPin 4  // Tx pin on Bluetooth unit
#define rxPin 5  // Rx pin on Bluetooth unit

PLabBTSerial btSerial(txPin, rxPin);

void bluetooth_communication_setup() {
    //Serial.begin(9600);   // Open serial communication to Serial Monitor
    btSerial.begin(9600); // Open serial communication to Bluetooth unit
}

void bluetooth_communication_loop() {
  while (btSerial.available()) { // If input available from Bluetooth unit
    char c = btSerial.read();    // Read character from from Bluetooth unit
    
    btSerial.write("BTSERIAL");             // Write that character to Serial Monitor
    btSerial.write(c);
    if(c == 'a'){

      if(speedMode == 400) {
        speedMode = 50;
      } else {
        speedMode = 400;
        speed = speedMode;
      }
    }
  };
  while (Serial.available()) { // If input available from Serial Monitor
    char c = Serial.read();    // Read character from from Serial Monitor
    if(c == 'a'){
        btSerial.write("Ragemode activated!");
    }
    btSerial.write(c);         // Write that character to Bluetooth unit
  };
}


