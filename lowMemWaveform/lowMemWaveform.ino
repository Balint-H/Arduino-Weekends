#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//DEFINING CONSTANTS
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
#define buttonPin 3
#define displayWidth 128

//DEFINING REGISTER SETTING FUNCTIONS
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

//DEFINING VARIABLES
volatile boolean trigger=false;
volatile int scale=1;
void drawFastVLine(uint16_t x0, uint16_t y0, uint16_t length, uint16_t color);
volatile int buff[displayWidth];

//DEFINING INTERRUPTS
void button() {
  delayMicroseconds(200);
  if(digitalRead(buttonPin)==HIGH)
  {
    scale=(scale*2)%15;
  }
}

ISR (ANALOG_COMP_vect)
  {
   trigger=true;
  }

void setup() {
//CONFIGURING REGISTERS FOR LOWER RESOLUTION, FASTER SPEED
  sbi(ADCSRA,ADPS2); 
  sbi(ADCSRA,ADPS1);
  sbi(ADCSRA,ADPS0);
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
  sbi(ACSR,ACIS1);
  sbi(ACSR,ACIS0);

  attachInterrupt(digitalPinToInterrupt(buttonPin), button, RISING);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();
  display.display();
}

void loop() {
  while(1){
    if(trigger){
      cbi(ACSR,ACIE);
      display.clearDisplay();
    //FILL BUFFER AS QUICK AS POSSIBLE
        if(scale==1)
        {
          for(int i=0; i<displayWidth; i++)
          {
            buff[i]=analogRead(A0);      
          }
        }

        else 
        {
          for(int i=0; i<displayWidth; i++)
          {
            for(int j = 0; j<scale*2; j++)
			{
			  analogRead(A0);
			}
            buff[i]=analogRead(A0);      
          }
        }
  
        }    
    //SCALE MEASUREMENTS
        for(int s=0; s<displayWidth; s++)
        {
          buff[scale*s]=buff[scale*s]*0.0625;
        }
    
    //DISPLAY
        for(int c=0; c<displayWidth; c++)
        {
          display.drawFastVLine(c, 64-buff[c]*0.0625, buff[c]*0.0625, WHITE);
        }
          display.display();
          trigger=false;
          sbi(ACSR,ACIE);
    }
  }

}
