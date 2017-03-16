#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#define LED 13
// this might need to be tuned for different lighting conditions, surfaces, etc.
#define QTR_THRESHOLD 300 //

// these might need to be tuned for different motor types
#define REVERSE_SPEED 400 // 0 is stopped, 400 is full speed
#define TURN_SPEED 400
#define FORWARD_SPEED 400
#define REVERSE_DURATION 200 // ms
#define TURN_DURATION 300 // ms
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];
ZumoReflectanceSensorArray sensors;

void setup()
{
 button.waitForButton();
 initSensors();
}

void loop()
{
  lineTrackerLoop();
}
