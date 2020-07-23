#include <Servo.h>          //standard library for the servo
#include <NewPing.h>        //for the Ultrasonic sensor function library.const int frontEchoPin = 7;

//L298N motor control pins
const int ENA = 5;
const int RightMotorForward = 4;
const int RightMotorBackward = 3;
const int LeftMotorForward = 9;
const int LefttMotorBackward = 10;
const int ENB = 11;

//sensor pins
#define trig_front A0 //analog input 0
#define echo_front A1 //analog input 1
#define trig_L1 A2 //analog input 2
#define echo_L1 A3 //analog input 3
#define trig_R1 A4 //analog input 4
#define echo_R1 A5 //analog input 5
#define trig_L2 A6 //analog input 6
#define echo_L2 A7 //analog input 7
#define trig_R2 A8 //analog input 8
#define echo_R2 A9 //analog input 9

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor;

void setup() {
  // serial
  Serial.begin(9600);
  
  // ultrasonic
  pinMode(trig_front, OUTPUT);
  pinMode(echo_front, INPUT);
  pinMode(trig_L1, OUTPUT);
  pinMode(echo_L1, INPUT);
  pinMode(trig_R1, OUTPUT);
  pinMode(echo_R1, INPUT);
  pinMode(trig_L2, OUTPUT);
  pinMode(echo_L2, INPUT);
  pinMode(trig_R2, OUTPUT);
  pinMode(echo_R2, INPUT);
  analogWrite(ENA, 80);
  analogWrite(ENB, 88);
  
  // motors
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(ENA, OUTPUT)
  pinMode(RightMotorForward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  Serial.begin(9600);
  
  long duration_front;
  long distance_front;
  long duration_L1;
  long distance_L1;
  long duration_R1;
  long distance_R1;
  long duration_L2;
  long distance_L2;
  long duration_R2;
  long distance_R2;


//Calculating distance

digitalWrite(trig_front, LOW);
delay(2);
digitalWrite(trig_front, HIGH);
delay(10);
digitalWrite(trig_front, LOW);
duration_front = pulseIN(echo_front, HIGH);
distance_front = duration_front*0.034/2;

digitalWrite(trig_L1, LOW);
delay(2);
digitalWrite(trig_L1, HIGH);
delay(10);
digitalWrite(trig_L1, LOW);
duration_left = pulseIN(echo_L1, HIGH);
distance_left = duration_front*0.034/2;

digitalWrite(trig_R1, LOW);
delay(2);
digitalWrite(trig_R1, HIGH);
delay(10);
digitalWrite(trig_R1, LOW);
duration_right = pulseIN(echo_R1, HIGH);
distance_right = duration_front*0.034/2;

digitalWrite(trig_L2, LOW);
delay(2);
digitalWrite(trig_L2, HIGH);
delay(10);
digitalWrite(trig_L2, LOW);
duration_right = pulseIN(echo_L2, HIGH);
distance_right = duration_front*0.034/2;

digitalWrite(trig_R2, LOW);
delay(2);
digitalWrite(trig_R2, HIGH);
delay(10);
digitalWrite(trig_R2, LOW);
duration_right = pulseIN(echo_R2, HIGH);
distance_right = duration_front*0.034/2;
  

if (distance_front <=  20){

    moveStop();
    delay(30);
    moveForward();
    
    if(distance_L1 > 10 && distance_L1 < 20 && distance_L2 <20){
      moveForward();
    }
    if(distance_L1 && distance_L2>= 20){
       turnLeft();
       delay(30);
       moveForward();
    }
    if(distance_L1 < 10 && distance_L1 > 0 && distance_R2 > 0){
      turnRight;
      delay(30);
      moveForward();
    }
 } 
  
  if(distance_front <= 20 && distance_R1 > 20 && distance_R2 >20){
    moveStop();
    delay(1000);
    moveStop();
    delay(400);
    
  }

  if(distance_front <= 20 && distance_R1 < 20 && distance_R2 <20){
    moveStop();
    delay(1000);
    turnRight;
    delay(800);
   
  }
  
  
}


void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

