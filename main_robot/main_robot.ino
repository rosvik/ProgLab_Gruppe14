#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

void setup()
{
 button.waitForButton();
 initSensors();
}

void loop()
{
  lineTrackerLoop();
}
