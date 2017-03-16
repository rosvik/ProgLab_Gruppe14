const int echoPin = A4;
const int triggerPin = A4;
const int maxDistance = 50;

const int servoPin = 6;

PLab_ZumoMotors plab_Motors;
NewPing sonar(triggerPin, echoPin, maxDistance);
NewServo myServo; 

int degreesServo = 0;
int degreesStep = 10;

void setupAttack() {
  Serial.begin(9600);
  myServo.attach(servoPin); 
  myServo.write(90);
  button.waitForButton(); // start when button pressed
}

void stepServo() {
   degreesServo = degreesServo + degreesStep;
   if (degreesServo > 160) {
       degreesStep = -degreesStep;
       degreesServo = 160;
   } else if (degreesServo < 0) {
       degreesStep = -degreesStep;
       degreesServo = 20;
   } 
   myServo.write(degreesServo);
}

float sonarDistance() {
  // Gjør ett ping, og beregn avstanden
  unsigned int time = sonar.ping();
  float distance = sonar.convert_cm(time);
  Serial.println(distance);
  
   return distance;
}

int speed = 400;
int findAndAttack(int tries) {
   int dir = 0;
   int dist = 999;
   for(int i = tries;i>0; i--){
     stepServo();
     int distance = sonarDistance();
     if(distance < dist && distance > 0.5 && distance < 50){
       dir = degreesServo;
       dist = distance;
     }
   }
   if(dist != 999){
        if(degreesServo < 90){
          plab_Motors.turnRight(400, abs(dir));
        }else {
           plab_Motors.turnLeft(400, abs(90-dir));
        }
        
        motors.setSpeeds(speed,speed);
        return dir;
       
   }
   
   
   plab_Motors.turnLeft(400, 90);
   return 360;
}


