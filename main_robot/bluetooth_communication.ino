#include <SoftwareSerial.h>
#include <PLabBTSerial.h>

#define txPin 4  // Tx pin on Bluetooth unit
#define rxPin 5  // Rx pin on Bluetooth unit

PLabBTSerial btSerial(txPin, rxPin);

void bluetooth_communication_setup() {
    btSerial.begin(9600); // Open serial communication to Bluetooth unit
}

void bluetooth_communication_loop() {
  
  while (btSerial.available()) { // If input available from Bluetooth unit
    char c = btSerial.read();    // Read character from from Bluetooth unit
    
    btSerial.println("BTSERIAL");             // Write that character to Serial Monitor
    btSerial.println(c);
    if(c == 'a'){
        btSerial.println("BTSerial: BTSerial 'a' triggered");
        Serial.println("Serial: BTSerial 'a' triggered");
    }
    Serial.println(c);
    btSerial.println(c);
  }
  
  while (Serial.available()) { // If input available from Serial Monitor
    char c = Serial.read();    // Read character from from Serial Monitor
    if(c == 'a'){
        btSerial.println("BTSerial: Serial 'a' triggered");
        Serial.println("Serial: Serial 'a' triggered");
    }
    Serial.println(c);
    btSerial.println(c);
  };
}


