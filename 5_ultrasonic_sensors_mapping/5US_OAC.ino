/*  OBSTACLE AVOIDANCE ROBOT */
int echoPinRight = A1;         // PIN A1 TO RECEIVE ECHO FROM RIGHT SENSOR
int trigerPinRight = A2;       // PIN A2 TO TRIGER THE RIGHT SENSOR
int echoPinMiddle = A3;        // PIN A3 TO RECEIVE ECHO FROM MIDDLE SENSOR
int trigerPinMiddle = A4;      // PIN A4 TO TRIGER THE MIDDLE SENSOR
int echoPinLeft = A5;         // PIN A5 TO RECEIVE ECHO FROM LEFT SENSOR
int trigerPinLeft = A6;       // PIN A6 TO TRIGER THE LEFT SENSOR
int echoPinSideRight = A7;        // PIN A7 TO RECEIVE ECHO FROM SIDE RIGHT SENSOR
int trigerPinSideRight = A8;      // PIN A8 TO TRIGER THE SIDE RIGHT SENSOR
int echoPinSideLeft = A9;         // PIN A9 TO RECEIVE ECHO FROM SIDE LEFT SENSOR
int trigerPinSideLeft = A10;       // PIN A10 TO TRIGER THE SIDE LEFT SENSOR
int motorRF = 2;              // PIN 2 FOR CONTROLLING MOTOR A1
int motorRB = 3;              // PIN 3 FOR CONTROLLING MOTOR A2
int motorLF = 4;              // PIN 4 FOR CONTROLLING MOTOR B1
int motorLB = 5;              // PIN 4 FOR CONTROLLING MOTOR B1
int motorSpeed = 11;          // ARDUINO PWM PIN 11 TO CONTROL MOTORS SPEED
double echoValueright, echoValuemiddle, echoValueleft, echoValueSideLeft, echoValueSideRight;  
// INITIALIZING VARIABLE TO RECEIVE ECHO FROM THE SENSORS
float cmRight, cmMiddle, cmLeft, cmSLeft, cmSRight;                           
 // INITIALIZING VARIABLES TO STORE DISTANCE MEASURED OF SENSORS IN CENTIMETERS
void setup()
{
  Serial.begin(9600);                                     // STARTING SERIAL COMMUNICATION TO PRINT VALUES RECEIVED BY SENSOR ON SERIAL MONITER
  pinMode(echoPinLeft, INPUT);                           // SETTING ARDUINO PIN AS INPUT
  pinMode(trigerPinLeft, OUTPUT);                       // SETTING ARDUINO PIN AS OUTPUT
  pinMode(echoPinMiddle, INPUT);                        // SETTING ARDUINO PIN AS INPUT
  pinMode(trigerPinMiddle, OUTPUT);                    // SETTING ARDUINO PIN AS OUTPU
  pinMode(echoPinRight, INPUT);                        // SETTING ARDUINO PIN AS INPUT
  pinMode(trigerPinRight, OUTPUT);                     // SETTING ARDUINO PIN AS OUTPU
  pinMode(echoPinSideLeft, INPUT);                        // SETTING ARDUINO PIN AS INPUT
  pinMode(trigerPinSideLeft, OUTPUT);                     // SETTING ARDUINO PIN AS OUTPU
  pinMode(echoPinSideRight, INPUT);                        // SETTING ARDUINO PIN AS INPUT
  pinMode(trigerPinSideRight, OUTPUT);                     // SETTING ARDUINO PIN AS OUTPU
  pinMode(motorSpeed, OUTPUT);          // SETTING ARDUINO PIN AS OUTPUT TO CONTROL MOTOR SPEED
}
void loop()
{
  float cmR, cmM, cmL, cmSL, cmSR;                                      // INITIALIZING VARIABLES TO STORE DISTANCE OBTAINED FROM SENSORS IN CM
  int maxRange = 30;                                        // SETTING MAX RANGE 
  analogWrite(motorSpeed, 90);                              // SETTING MOTORS SPEED YOU CAN SET SPEED BETWEEN 0-255
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorRB, LOW);
  digitalWrite(motorLF, HIGH);
  digitalWrite(motorLB, LOW);

   
  cmR = sensorRight();
  cmM = sensorMiddle();
  cmL = sensorLeft();
  cmSL = sensorSideLeft();
  cmSR = sensorSideRight();
  Serial.println();
  Serial.print(cmL);
  Serial.print("        ");
  Serial.print(cmM);
  Serial.print("        ");
  Serial.print(cmR);
  Serial.print("        ");
  Serial.print(cmSL);
  Serial.print("        ");
  Serial.print(cmSR);
  if (cmR && cmSR < maxRange)
  {
    digitalWrite(motorRF, LOW);
    digitalWrite(motorRB, HIGH);
    digitalWrite(motorLF, HIGH);
    digitalWrite(motorLB, LOW);
  }
  if (cmL && cmSL< maxRange)
  {
    digitalWrite(motorRF, HIGH);
    digitalWrite(motorRB, LOW);
    digitalWrite(motorLF, LOW);
    digitalWrite(motorLB, HIGH);
  }

  if (cmM < maxRange) { if (cmL || cmSL > cmR && cmSR)
    {
      digitalWrite(motorRF, HIGH);
      digitalWrite(motorRB, LOW);
      digitalWrite(motorLF, LOW);
      digitalWrite(motorLB, HIGH);
    }
    else if (cmR || cmSR > cmL && cmSL)
    {
      digitalWrite(motorRF, LOW);
      digitalWrite(motorRB, HIGH);
      digitalWrite(motorLF, HIGH);
      digitalWrite(motorLB, LOW);
    }
    else if (cmR && cmSR < maxRange && (cmL && cmSL) < maxRange)
    {
      digitalWrite(motorRF, LOW);
      digitalWrite(motorRB, HIGH);
      digitalWrite(motorLF, LOW);
      digitalWrite(motorLB, HIGH);
    }
  }

  delay(500);
}
float sensorRight()               // FUUNCTION TO OPERATE RIGHT SENSOR
{
  digitalWrite(trigerPinRight, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPinRight, LOW);
  echoValueright = pulseIn(echoPinRight, HIGH);
  cmRight = echoValueright / 59;
  //inchesRight=cmRight/2.54;
  //Serial.print(cmRight);
  return (cmRight);
}
float sensorSideRight()               // FUUNCTION TO OPERATE RIGHT SENSOR
{
  digitalWrite(trigerPinSideRight, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPinSideRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPinSideRight, LOW);
  echoValueright = pulseIn(echoPinSideRight, HIGH);
  cmSRight = echoValueSideRight / 59;
  //inchesRight=cmRight/2.54;
  //Serial.print(cmRight);
  return (cmRight);
}
float sensorMiddle()              // FUNCTION TO OPERATE MIDDLE SENSOR
{
  digitalWrite(trigerPinMiddle, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPinMiddle, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPinMiddle, LOW);
  echoValuemiddle = pulseIn(echoPinMiddle, HIGH);
  cmMiddle = echoValuemiddle / 59;

  //inchesMiddle=cmMiddle/2.54;
  //Serial.print(cmMiddle);
  return (cmMiddle);
}
float sensorLeft()              // FUNCTION TO OPERATE LETT SENSOR
{
  digitalWrite(trigerPinLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPinLeft, LOW);
  echoValueleft = pulseIn(echoPinLeft, HIGH);
  cmLeft = echoValueleft / 59;
  //inchesLeft=cmLeft/2.54;
  //Serial.print(cmLeft);
  return (cmLeft);
}

float sensorSideLeft()              // FUNCTION TO OPERATE LETT SENSOR
{
  digitalWrite(trigerPinSideLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPinSideLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPinSideLeft, LOW);
  echoValueleft = pulseIn(echoPinSideLeft, HIGH);
  cmSLeft = echoValueSideLeft / 59;
  //inchesLeft=cmLeft/2.54;
  //Serial.print(cmLeft);
  return (cmLeft);
}
