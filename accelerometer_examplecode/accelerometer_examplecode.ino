
const int xpin = A2; // x-axis of the accelerometer
const int ypin = A1; // y-axis
const int zpin = A0; // z-axis (only on 3-axis models)

const int btnpin = 3;
const int ledpin = 4; 
const int knobPin = 4;
int speakerOut = 2;
int lightVal = 0;
int knobVal = 0;
int btnstate = 0;
//int prevbtnstate = 0;
boolean washigh = false;
boolean ishigh = false;

boolean isrunning = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(speakerOut, OUTPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledpin, HIGH);
}

void loop() {
  int x = analogRead(xpin); //read from xpin
  int y = analogRead(ypin); //read from ypin
  int z = analogRead(zpin); //read from zpin

  btnstate = digitalRead(btnpin);

  if(btnstate == HIGH) {
    ishigh = true;
  } else {
    ishigh = false;
  }
  
  if(btnstate == HIGH && ishigh != washigh) {
    if(isrunning) {
      isrunning = false;
      digitalWrite(ledpin, LOW);
    } else {
      isrunning = true;
      digitalWrite(ledpin, HIGH);
    }
    delay(20);
  }

  if(btnstate == HIGH) {
    washigh = true;
  } else {
    washigh = false;
  }
  
  if (isrunning) {
    if(y > 600 || x > 600 || z > 600) {
      //lightVal = analogRead(lightPin);
      knobVal = analogRead(knobPin);
      Serial.println("Played!");
      //Serial.println(lightVal);
      Serial.println(knobVal);
      tone(speakerOut, 200, knobVal + 1); 
      delay(knobVal + 1);
    }
  }
}