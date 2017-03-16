void lineTrackerLoop() {
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

void initSensors() {
   sensors.init();
}

