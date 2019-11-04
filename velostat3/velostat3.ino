double back[3]={0}; //0: running average; 1:current; 2:previous
long int start=0;
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void setup() 
{
  sbi(ADCSRA,ADPS2); 
  sbi(ADCSRA,ADPS1);
  sbi(ADCSRA,ADPS0);
  Serial.begin(9600);  
  pinMode(13, OUTPUT);
}

void loop()
{

  for(int i=0; i<100; i++)
  { 
    back[0]=back[0]+analogRead(A0);
    delayMicroseconds(5);
  }

  Serial.print(72000);
  Serial.print("\t");
  Serial.print(45000);
  Serial.print("\t");
  Serial.println(back[0]);  
  if((back[0]-back[1])<-1500 && millis()>start+2000)
  {
    start=millis();
    digitalWrite(13, HIGH);
  }
  if(millis()>start+2000)
  {
    digitalWrite(13, LOW);
  }
  
  back[1]=back[0];
  back[0]=0;

}
