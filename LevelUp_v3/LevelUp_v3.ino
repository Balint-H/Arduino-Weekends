#include <Encoder.h>
#include <Wire.h>

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10; //speed
int in1 = 9;  //on-off and direction
int in2 = 8; //on-off and direction
int upPin = 0;
int downPin = 1;
int shakePin = 7;
volatile bool bUp=false;
volatile bool bDown=false;
volatile bool bShake=false;

Encoder myEnc(2, 3);

double sens[2]={0}; //0: running total; 1:previous

void buttonUp()
{
  delayMicroseconds(100);
  if(digitalRead(upPin)==HIGH)bUp=true;
}

 void buttonDown()
 {
  delayMicroseconds(100);
  if(digitalRead(downPin)==HIGH)bDown=true;
 }
 
 void buttonShake()
 {
  delayMicroseconds(100);
  if(digitalRead(shakePin)==HIGH)bShake=true;
 }


void setup()
{
  // set all the motor control pins to outputs
  sbi(ADCSRA,ADPS2); 
  sbi(ADCSRA,ADPS1);
  sbi(ADCSRA,ADPS0);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  analogWrite(enA, 400);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(upPin), buttonUp, RISING);
  attachInterrupt(digitalPinToInterrupt(downPin), buttonDown, RISING);
  attachInterrupt(digitalPinToInterrupt(shakePin), buttonShake, RISING);
  for(int i=0; i<100; i++)
  { 
    sens[1]=sens[1]+analogRead(A0);
    delayMicroseconds(5);
  }
}

void loop()
{
  for(int i=0; i<100; i++)
  { 
    sens[0]=sens[0]+analogRead(A0);
    delayMicroseconds(5);
  }
  Serial.println(myEnc.read());
  
  if(myAbs(sens[0]-sens[1])>7000)
  {
    driveMotor(in1, in2, -10000);
  }

  if(bUp)
  {
    driveMotor(in1, in2, 10000);
    bUp=false;
  }

  if(bDown)
  {
    driveMotor(in1, in2, -10000);
    bDown=false;
  }

  if (bShake)
  {
    driveMotor(in1, in2, 5000);
    driveMotor(in1 ,in2, -5000);
    bShake=false;
  }
  
  sens[1]=sens[0];
  sens[0]=0;
}

void driveMotor(int in1, int in2, long dur)
{
  double origDeg=myEnc.read();
  double curDeg=myEnc.read();
  bool dir = dur > 0;
  
  while(curDeg < (origDeg+dur-2) || curDeg > (origDeg+dur+2))
  {
    analogWrite(enA, 400);

    curDeg=myEnc.read();
    Serial.println(curDeg);
    if(curDeg < origDeg+dur)
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }
    else
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }   
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

double myAbs(double in)
{
  if (in<0) return -in;
  else return in;
}

