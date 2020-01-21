const int dirPin = 8;
const int stepPin = 9;

const int arriba = 3;
const int abajo = 2;

const int fc0 = 4;
const int fc1 = 5;
const int fc2 = 6;
const int fc3 = 7;


int readArriba = HIGH;
int readAbajo = HIGH;
int readFc0 = HIGH;
int readFc1 = HIGH;
int readFc2 = HIGH;
int readFc3 = HIGH;

int piso = 0;

bool flagActivo = false;

long debounceDelay = 500;


int microPausa = 1000;
char option = '3';
int val = 0;

int periodo = 100;
unsigned long TiempoAhora = 0;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  pinMode(arriba, INPUT);
  pinMode(abajo, INPUT);
  pinMode(fc0, INPUT);
  pinMode(fc1, INPUT);
  pinMode(fc2, INPUT);
  pinMode(fc3, INPUT);

  Serial.begin(9600);

  flagActivo = true;
  digitalWrite(dirPin, LOW);
  Serial.println("Abajo");

}
void loop() {

  readArriba = digitalRead(arriba);
  readAbajo = digitalRead(abajo);
  readFc0 = digitalRead(fc0);
  readFc1 = digitalRead(fc1);
  readFc2 = digitalRead(fc2);
  readFc3 = digitalRead(fc3);

  if (readArriba == LOW && flagActivo == false) {
    delay(debounceDelay);
    if (readArriba == LOW) {
      if (piso <= 3) {
        piso++;
        flagActivo = true;
        digitalWrite(dirPin, HIGH);
        Serial.println("Arriba");
      }


    }
  }


  if (readAbajo == LOW && flagActivo == false ) {
    delay(debounceDelay);
    if (readAbajo == LOW) {
      piso = 0;
      flagActivo = true;
      digitalWrite(dirPin, LOW);
      Serial.println("Abajo");
    }
  }


  if (piso == 0) {


    if (readFc0 == LOW && flagActivo == true ) {
      delay(debounceDelay);
      if (readFc0 == LOW) {
        flagActivo = false;;
        Serial.println("FC0");
      }
    }
  }


  if (piso == 1) {


    if (readFc1 == LOW && flagActivo == true ) {
      delay(debounceDelay);
      if (readFc1 == LOW) {
        flagActivo = false;
        Serial.println("FC1");
      }
    }

  }


  if (piso == 2) {

    if (readFc2 == LOW && flagActivo == true ) {
      delay(debounceDelay);
      if (readFc2 == LOW) {
        flagActivo = false;
        Serial.println("FC2");
      }
    }
  }

  if (piso == 3) {


    if (readFc3 == LOW && flagActivo == true ) {
      delay(debounceDelay);
      if (readFc3 == LOW) {
        flagActivo = false;
        Serial.println("FC3");
      }
    }


  }



  if (flagActivo == false) {

    stepMotor();

  }


}

void stepMotor() {

  digitalWrite(stepPin, HIGH);
  delayMicroseconds(microPausa);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(microPausa);
}
