#include <ZumoMotors.h>



ZumoMotors motors;

void setup(){

  motors.setLeftSpeed(200);
  motors.setRightSpeed(200);

  delay(1000);

  motors.setLeftSpeed(-100);
  motors.setRightSpeed(100);

  delay(1000);
  
  motors.setLeftSpeed(200);
  motors.setRightSpeed(200);

  delay(1000);

  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);



}

void loop()
{
//  // run left motor forward
//
//  
//  for (int speed = 0; speed <= 400; speed++)
//  {
//    motors.setLeftSpeed(speed);
//    delay(2);
//  }
//
//  for (int speed = 400; speed >= 0; speed--)
//  {
//    motors.setLeftSpeed(speed);
//    delay(2);
//  }
//  
//  // run left motor backward
//  
//  digitalWrite(LED_PIN, LOW);
//  
//  for (int speed = 0; speed >= -400; speed--)
//  {
//    motors.setLeftSpeed(speed);
//    delay(2);
//  }
//  
//  for (int speed = -400; speed <= 0; speed++)
//  {
//    motors.setLeftSpeed(speed);
//    delay(2);
//  }
//
//  // run right motor forward
//  
//  digitalWrite(LED_PIN, HIGH);
//  
//  for (int speed = 0; speed <= 400; speed++)
//  {
//    motors.setRightSpeed(speed);
//    delay(2);
//  }
//
//  for (int speed = 400; speed >= 0; speed--)
//  {
//    motors.setRightSpeed(speed);
//    delay(2);
//  }
//  
//  // run right motor backward
//  
//  digitalWrite(LED_PIN, LOW);
//  
//  for (int speed = 0; speed >= -400; speed--)
//  {
//    motors.setRightSpeed(speed);
//    delay(2);
//  }
//  
//  for (int speed = -400; speed <= 0; speed++)
//  {
//    motors.setRightSpeed(speed);
//    delay(2);
//  }
//  
//  delay(500);
}
