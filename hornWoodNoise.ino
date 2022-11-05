

const int motor1Pin = 5;    // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 4;    // H-bridge leg 2 (pin 7, 2A)
const int enablePin = 3;    // H-bridge enable pin

const int motor3Pin = 7;    // H-bridge leg 1 (pin 2, 1A)
const int motor4Pin = 8;    // H-bridge leg 2 (pin 7, 2A)
const int enable2Pin = 6;    // H-bridge enable pin

int motorSpeed = 0;

int noidPin = 9;
int noid2Pin = 10;

void setup() {

  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  digitalWrite(enablePin, HIGH);
  digitalWrite(enable2Pin, HIGH);

 
  Serial.begin(9600);

}

void loop() {

int noidValue = digitalRead(noidPin);
  Serial.println(noidValue);

  if (digitalRead (noidPin) == LOW)   {

    digitalWrite(motor1Pin, HIGH);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
    motorSpeed = 170;
    analogWrite(enablePin, motorSpeed);
  }
  else {

    digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
  }

if (digitalRead (noid2Pin) == LOW)   {

    digitalWrite(motor3Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor4Pin, HIGH);  // set leg 2 of the H-bridge high
    motorSpeed = 170;
    analogWrite(enable2Pin, motorSpeed);
  }
  else {

    digitalWrite(motor3Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor4Pin, LOW);  // set leg 2 of the H-bridge high
  }

}
