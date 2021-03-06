/*  OBSTACLE AVOIDANCE ROBOT */
int echoPinRight = A1;         // PIN 6 TO RECEIVE ECHO FROM RIGHT SENSOR
int trigerPinRight = A2;       // PIN 7 TO TRIGER THE RIGHT SENSOR
int echoPinMiddle = A3;        // PIN 8 TO RECEIVE ECHO FROM MIDDLE SENSOR
int trigerPinMiddle = A4;      // PIN 9 TO TRIGER THE MIDDLE SENSOR
int echoPinLeft = A5;         // PIN 13 TO RECEIVE ECHO FROM LEFT SENSOR
int trigerPinLeft = A6;       // PIN 10 TO TRIGER THE LEFT SENSOR
int motorRF = 2;              // PIN 2 FOR CONTROLLING MOTOR A1
int motorRB = 3;              // PIN 3 FOR CONTROLLING MOTOR A2
int motorLF = 4;              // PIN 4 FOR CONTROLLING MOTOR B1
int motorLB = 5;              // PIN 4 FOR CONTROLLING MOTOR B1
int motorSpeed = 11;          // ARDUINO PWM PIN 11 TO CONTROL MOTORS SPEED
double echoValueright, echoValuemiddle, echoValueleft;  
// INITIALIZING VARIABLE TO RECEIVE ECHO FROM THE SENSORS
float cmRight, cmMiddle, cmLeft;                           
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
  pinMode(motorSpeed, OUTPUT);          // SETTING ARDUINO PIN AS OUTPUT TO CONTROL MOTOR SPEED
}
void loop()
{
  float cmR, cmM, cmL;                                      // INITIALIZING VARIABLES TO STORE DISTANCE OBTAINED FROM SENSORS IN CM
  int maxRange = 30;                                        // SETTING MAX RANGE 
  analogWrite(motorSpeed, 90);                              // SETTING MOTORS SPEED YOU CAN SET SPEED BETWEEN 0-255
  digitalWrite(motorRF, HIGH);
  digitalWrite(motorRB, LOW);
  digitalWrite(motorLF, HIGH);
  digitalWrite(motorLB, LOW);

   
  cmR = sensorRight();
  cmM = sensorMiddle();
  cmL = sensorLeft();
  Serial.println();
  Serial.print(cmL);
  Serial.print("        ");
  Serial.print(cmM);
  Serial.print("        ");
  Serial.print(cmR);
  if (cmR < maxRange)
  {
    digitalWrite(motorRF, LOW);
    digitalWrite(motorRB, HIGH);
    digitalWrite(motorLF, HIGH);
    digitalWrite(motorLB, LOW);
  }
  if (cmL < maxRange)
  {
    digitalWrite(motorRF, HIGH);
    digitalWrite(motorRB, LOW);
    digitalWrite(motorLF, LOW);
    digitalWrite(motorLB, HIGH);
  }

  if (cmM < maxRange) { if (cmL > cmR)
    {
      digitalWrite(motorRF, HIGH);
      digitalWrite(motorRB, LOW);
      digitalWrite(motorLF, LOW);
      digitalWrite(motorLB, HIGH);
    }
    else if (cmR > cmL)
    {
      digitalWrite(motorRF, LOW);
      digitalWrite(motorRB, HIGH);
      digitalWrite(motorLF, HIGH);
      digitalWrite(motorLB, LOW);
    }
    else if (cmR < maxRange && cmL < maxRange)
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
