#include <Wire.h>



// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif
volatile int count=0;
volatile boolean triggered=false;
ISR (ANALOG_COMP_vect)
  {
  triggered = !triggered;
  count++;
  }
void setup()
{
 // set prescale to 16
  sbi(ADCSRA,ADPS2) ;
  sbi(ADCSRA,ADPS1) ;
  sbi(ADCSRA,ADPS0) ;
  sbi(DIDR0,ADC5D);
  sbi(DIDR0,ADC4D);
  sbi(DIDR0,ADC3D);
  sbi(DIDR0,ADC2D);
  sbi(DIDR0,ADC1D);
  sbi(DIDR0,ADC0D);
  cbi(ACSR,ACD);
  cbi(ACSR,ACBG);
  sbi(ACSR,ACIE);
  cbi(ACSR,ACIC);
  cbi(ACSR,ACIS1);
  cbi(ACSR,ACIS0);

  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT);
  
}

void loop() {

    if (triggered)
    {
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(12, LOW);
    delay(100);
    }

    if (count>6)
    {
    sbi(ACSR,ACIS1);
    sbi(ACSR,ACIS0);
    }

    

}
