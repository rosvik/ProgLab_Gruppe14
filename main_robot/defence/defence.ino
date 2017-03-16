#include <ZumoMotors.h>

ZumoMotors motors;

// Taktikk - Når runden starter, kjør til hvit stripe, og bruk Mortens funksjon til å kjøre i ring.
// Bruk i tillegg ultralyd-sensor til å detektere hvor motstanderen er og unngå denne. 
// Hvis motstander er rett foran eller rett bak, kjør full fart inn i motstander.
// 
 
 /*
 * Reads the sensor value of an accelerometer and prints the value to serial console.
 * 
 * Circuit:
 *   1 x analogue accelerometer ADXL335B
 * How to connect curcuit can be seen here:
 * https://www.ntnu.no/wiki/display/plab/6.+Akselerometer+ADXL335B
 */
// these constants describe the pins. They won't change:
const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis
const int zpin = A2;                  // z-axis (only on 3-axis models)

void setup()
{
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop()
{
  // print the sensor values:
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  //Serial.print(analogRead(ypin));
  // print a tab between values:
  //Serial.print("\t");
//  Serial.print(analogRead(zpin));
 Serial.println();
  // delay before next reading:
  delay(100);
}


