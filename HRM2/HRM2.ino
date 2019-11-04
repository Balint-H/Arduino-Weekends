#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

boolean current;
boolean previous;
int beatN=0;
unsigned long lastDebounce;
unsigned long debounceDelay = 50;
unsigned long currentTime;
float beats[10];
unsigned long measureStart=0;
int inPin = 12;
float sum=0;
int average=0;
boolean toggle=0;

void setup() {
  lcd.begin (20,4);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  pinMode(inPin, INPUT);
  lcd.clear();
  lcd.print(F("Beats per minute:"));


}

void loop() {
  
  while (beatN < 5){
    current = digitalRead(inPin);
    currentTime = millis();
    
    if (current != previous){    //checks if there is change in input
      lastDebounce = currentTime;
      toggle = true;
    }
    
    if (currentTime-lastDebounce > debounceDelay && current == HIGH && toggle == true){   //checks if enough time has passed for HIGH to be an actual beat
      beats[beatN++] = currentTime-measureStart;
      measureStart = currentTime;
      toggle = false;
        
    }

    previous = current;
  }
  
  for(int i=0; i<5; i++){ 
    sum= sum + beats[i];
  }
  average = sum/5;
  lcd.setCursor(0,1);
  lcd.print(F("                    "));
  lcd.setCursor(0,1);
  lcd.print(60000/average, DEC);
  beatN = 0;
  sum=0;
}
