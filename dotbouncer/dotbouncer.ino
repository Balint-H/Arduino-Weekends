
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 


/*-----------------------------
     
          Paddle class
     
-----------------------------*/

class Paddle
{
  private:
    int width;
    int pos;
    int pin;
    int x;
    int point;
    
  public:
    Paddle();
    Paddle(int xin, int pinIn);
    ~Paddle();
    int GetPos(){return pos;}
    int GetWidth(){return width;}
    int GetX(){return x;}
    void Update();
    void SetWidth(int widthIn){width=widthIn;}
    void incrPoint(){point++;}
};

Paddle::Paddle()
{
  width=10;
  pos=27;
  pin=0;
  x=0;
  point=0;
}

Paddle::Paddle(int xin, int pinIn)
{
  width=10;
  pos=27;
  pin=pinIn;
  x=xin;
  point=0;
}

Paddle::~Paddle()
{
}

void Paddle::Update()
{
  pos=analogRead(pin)/19;
  display.drawFastVLine(x, analogRead(pin)/16, width, WHITE);
}

/*-----------------------------
      
          Ball class
      
-----------------------------*/
class Ball
{
  private:
    int xPos;
    int yPos;
    int drag;
    int angle;
    long int prev;

   public:
    Ball();
    ~Ball();

    void Update(Paddle& paddleRight, Paddle& paddleLeft);
    void WallCollide(){angle=0-angle;}
    void PaddleCollide(Paddle& paddleIn);
    void CheckPoint(Paddle& paddleRight, Paddle& paddleLeft);
};

Ball::Ball()
{
  xPos=64;
  yPos=32;
  drag=10;
  angle=0;
  prev=0;
}

Ball::~Ball()
{ 
}

void Ball::Update(Paddle& paddleRight, Paddle& paddleLeft)
{
  if (yPos<=0 || yPos>=64)WallCollide();
  
  if(xPos==paddleRight.GetX()-1)
  {
    PaddleCollide(paddleRight);
  }
  else if(xPos==paddleLeft.GetX()+1)
  {
    PaddleCollide(paddleLeft);
  }
  
  switch(angle)
    {
      case 1:
        xPos++;
        break;
        
      case 2:
        xPos++;
        yPos++;
        break;
        
      case 3:
        xPos--;
        yPos++;
        break;
        
      case -1:
        xPos--;
        break;
        
      case -2:
        xPos++;
        yPos--;
        break;
        
      case -3:
        xPos--;
        yPos--;
        break; 
    }
    display.drawPixel(xPos, yPos, WHITE);
}

void Ball::PaddleCollide(Paddle& paddleIn)
{
  int dif=yPos-paddleIn.GetPos();
  if(angle>0)
  {
    if(dif>=0 && dif<3)angle=3;
    else if(dif>=3 && dif<7)angle=-1;
    else if(dif>=7 && dif<10)angle=-3;
  }
  else
  {
    if(dif>=0 && dif<3)angle=2;
    else if(dif>=3 && dif<7)angle=1;
    else if(dif>=7 && dif<10)angle=-2;
  }
}

void Ball::CheckPoint(Paddle& paddleRight, Paddle& paddleLeft)
{
  if (xPos<=0)
  {
    paddleLeft.incrPoint();
    xPos=64;
    yPos=32;
  }
}

/*------------------------------------------
           
               Main body of code
                
 ------------------------------------------*/

void setup()   {                
  Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.display();
  display.clearDisplay();

}
 void loop()
 {

  
 

  
  while(true)
  {
    
  }
 }


