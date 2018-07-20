#ifndef Smartcar
#define Smartcar


void start(){
#include <Servo.h>
Servo myservo;      // create servo object to control servo

int Echo = A4;      // define ultrasonic 
int Trig = A5; 

#define ENA 5       // define motors/pins
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
}

void tweenmotors(int a, int b){ // Tweens both motors to set positions (linear)
  static int currentSpeedA;
  static int currentSpeedB;
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  bool aPos = false;
  bool bPos = false;
  bool aGoal = false;
  bool bGoal = false;
  int differenceA = currentSpeedA - a;
  int differenceB = currentSpeedB - b;
  if (differenceA > 0) {
    aPos = true;
  }
  if (differenceB > 0) {
    bPos = true;
  }
  do {
    if (a == currentSpeedA){
      aGoal = true;
    }
    else{
    if (aPos == true) {
        --currentSpeedA;
    }
    else {
        ++currentSpeedA;
    }}
    if (b == currentSpeedB){
      bGoal = true;
    }
    else{
    if (bPos == true) {
        --currentSpeedB;
    }
    else {
        ++currentSpeedB;
    }}
    analogWrite(ENA,currentSpeedA);
    analogWrite(ENB,currentSpeedB);
    delay(4);
  }
  while (aGoal == false or bGoal == false);
}

int motorDegToSec(int in){
  return in * 4;
}


void motorsOn(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}
void motorsOff(){
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}
void forward(int reqSpeed){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  tweenmotors(reqSpeed,reqSpeed);
}
void reverse(int reqSpeed){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  tweenmotors(reqSpeed,reqSpeed);
}
void left(){
  motorsOn();
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  tweenmotors(10,150);
}
void right(){
  motorsOn();
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  tweenmotors(150,10);
}
void stop(){
  motorsOff();
}
void slow(){
  tweenmotors(0,0);
}

int distanceTest() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance = Fdistance / 58;       
  return (int)Fdistance;
} 













#endif
