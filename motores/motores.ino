const int dirPin = 8;
const int stepPin = 9;

const int arriba = 3;
const int abajo = 2;

const int fc0 = 4;
const int fc1 = 5;


int readArriba = HIGH;
int readAbajo = HIGH;
int readFc0 = HIGH;
int readFc1 = HIGH;

int piso = 0;

bool flagArriba = false;
bool flagAbajo = false;

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
  Serial.begin(9600);
 Serial.println("buscando abajo");
 
  while(readFc0==true){
  digitalWrite(dirPin, LOW);
  stepMotor();
  readFc0 = digitalRead(fc0);
    
    }
   flagAbajo = true;
  Serial.println("INICIO");
  

}
void loop() {

  readArriba = digitalRead(arriba);
  readAbajo = digitalRead(abajo);
  readFc0 = digitalRead(fc0);
  readFc1 = digitalRead(fc1);

  if (readArriba == LOW ) {
    
    if (readArriba == LOW) {
        
        flagAbajo=false;
        digitalWrite(dirPin, HIGH);
        if(flagArriba==false){
         stepMotor();
        }


    }
  }


  if (readAbajo == LOW  ) {
   
    if (readAbajo == LOW) {
       flagArriba=false;
      digitalWrite(dirPin, LOW);
       if(flagAbajo==false){
         stepMotor();
        }
      
       
    }
  }





    if (readFc0 == LOW  ) {
      delay(debounceDelay);
      if (readFc0 == LOW) {
        flagAbajo = true;
        Serial.println("FC0");
      }
    }
  


 


    if (readFc1 == LOW  ) {
      delay(debounceDelay);
      if (readFc1 == LOW) {
        flagArriba==true;
        Serial.println("FC1");
      }
    }

  








}

void stepMotor() {

  digitalWrite(stepPin, HIGH);
  delayMicroseconds(microPausa);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(microPausa);
}
