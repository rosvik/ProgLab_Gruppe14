/*
 * 
 */

#include <SoftwareSerial.h>
#include <PLabBTSerial.h>

#define txPinCon 2  // Tx pin on Bluetooth unit
#define rxPinCon 3  // Rx pin on Bluetooth unit

char BTName[] = "BesteRoboten";
char ATCommand[] = "AT+NAMEPLab_";
PLabBTSerial btSerialCon(txPinCon, rxPinCon);

void bluetooth_connector_setup()
{
    Serial.begin(9600);   // Open serial communication to Serial Monitor
    btSerialCon.begin(9600); // Open serial communication to Bluetooth unit
}


void bluetooth_connector_loop() {
    Serial.print("Setting new name for device to: PLab_"); 
    Serial.println(BTName);

    btSerialCon.write(ATCommand); 
    btSerialCon.write(BTName);
    btSerialCon.write(0x0D);
    btSerialCon.write(0x0A);
    delay(1000);
}
