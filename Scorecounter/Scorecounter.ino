
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

/*------------------------------------------
           
               Main body of code
                
 ------------------------------------------*/

void setup()   {                
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.display();
  display.clearDisplay();

}
 void loop()
 {
  display.clearDisplay();
  display.display();
  int score=48;
  double prevRead=analogRead(A0);
  double curRead=0;
  double scoreTime=0;
  while(true)
  {
    for(int i=0; i<100; i++)
  { 
    curRead=curRead+analogRead(A0);
    delayMicroseconds(5);
  }
    
    
     if(myAbs(curRead-prevRead)/prevRead>0.05 && millis()-scoreTime>1500)
     {
      if(score-48>9) score=48;
      display.clearDisplay();  
      display.drawChar(60,28,char(score++),WHITE, BLACK, 2);
      display.display();
      scoreTime=millis();
     }
     //Serial.println(curRead);
    // delay(200);
    Serial.print(75000);
  Serial.print("\t");
  Serial.print(10000);
  Serial.print("\t");
  Serial.println(curRead); 
     prevRead=curRead;
     curRead=0;
  }
 }

 int myAbs(int numIn)
{
  if(numIn>=0)return numIn;
  else return -1*numIn;
}


