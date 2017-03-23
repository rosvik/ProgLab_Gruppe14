const int echoPin = A4;
const int triggerPin = A4;
const int maxDistance = 50;

const int servoPin = 6;
int speed = 400;
bool running = false;
PLab_ZumoMotors plab_Motors;
NewPing sonar(triggerPin, echoPin, maxDistance);
NewServo myServo; 

int offset = -55;
int degreesServo = 90;
int degreesStep = 5;

void setupAttack() {
  myServo.attach(servoPin); 
  myServo.write(degreesServo + offset);
}

void stepServo() {
   degreesServo = degreesServo + degreesStep;
   if (degreesServo > 180) {
       degreesStep = -degreesStep;
       degreesServo = 180;
   } else if (degreesServo < 60) {
       degreesStep = -degreesStep;
       degreesServo = 60;
   }
}

float sonarDistance() {
  // Gjør ett ping, og beregn avstanden
  unsigned int time = sonar.ping();
  float distance = sonar.convert_cm(time);  
  return distance;
}

void findAndAttack() {
   int distance = sonarDistance();
     if(distance > 0 && distance < 70){
        motors.setSpeeds(speed,speed);
     running = true;
     return;
   }
   if(running){
        if(random(3) == 2) 
          motors.setSpeeds(400,50);
        else if(random(1,3) == 1) 
          motors.setSpeeds(400,200);      
        else 
          motors.setSpeeds(50,400);    
   }
   running = false;
   return;

}


