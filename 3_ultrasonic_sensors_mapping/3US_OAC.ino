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
#define trig1_left A2 //analog input 2
#define echo1_left A3 //analog input 3
#define trig1_right A4 //analog input 4
#define echo1_right A5 //analog input 5

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
  pinMode(trig_left, OUTPUT);
  pinMode(echo_left, INPUT);
  pinMode(trig_right, OUTPUT);
  pinMode(trig_right, INPUT);
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
  long duration_left;
  long distance_left;
  long duration_right;
  long distance_right;

//Calculating distance

digitalWrite(trig_front, LOW);
delay(2);
digitalWrite(trig_front, HIGH);
delay(10);
digitalWrite(trig_front, LOW);
duration_front = pilseIN(echo_front, HIGH);
distance_front = duration_front*0.034/2;

digitalWrite(trig_left, LOW);
delay(2);
digitalWrite(trig_left, HIGH);
delay(10);
digitalWrite(trig_left, LOW);
duration_left = pilseIN(echo_front, HIGH);
distance_left = duration_front*0.034/2;

digitalWrite(trig_right, LOW);
delay(2);
digitalWrite(trig_right, HIGH);
delay(10);
digitalWrite(trig_right, LOW);
duration_right = pilseIN(echo_front, HIGH);
distance_right = duration_front*0.034/2;
  
Serial.print("front = ");
Serial.println(distance_front);
Serial.print("Left = ");
Serial.println(distance_left);
Serial.print("Right = ");
Serial.println(distance_right);  
delay(50);

if (distance_front >20){

    forward();
    
    if(distance_left > 10&& distance_left<20){
      forward();
    }
    if(distance_left >=20){
       left();
       delay(30);
       forward();
    }
    if(distance_left<10 && distance_left>0){
      right();
      delay(30);
      forward();
    }
 } 
  
  if(distance_front<=20&& distance_right > 20){
    Stop();
    delay(1000);
    right();
    delay(400);
    
  }

  if(distance_front<=20 && distance_right<20){
    Stop();
    delay(1000);
    right();
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

