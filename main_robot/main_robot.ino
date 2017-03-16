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
 sensors.init();
 button.waitForButton();
}

void loop()
{
 sensors.read(sensor_values);
 if (sensor_values[0] < QTR_THRESHOLD)
 {
 // if leftmost sensor detects line, reverse and turn to the right
 motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
 delay(REVERSE_DURATION);
 motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
 delay(TURN_DURATION*random(5,15)/10);
 motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
 }
 else if (sensor_values[5] < QTR_THRESHOLD)
 {
 // if rightmost sensor detects line, reverse and turn to the left
 motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
 delay(REVERSE_DURATION);
 motors.setSpeeds(-TURN_SPEED, TURN_SPEED);
 delay(TURN_DURATION);
 motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
 }
}
