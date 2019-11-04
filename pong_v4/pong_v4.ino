
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


/*----------------------------------------------------------------------------------

          Paddle class

----------------------------------------------------------------------------------*/
class PowerUp;
class Paddle
{
  private:
    int xPos;
    int yPos;
    int width;
    int pin;
    int point;

  public:
    Paddle();
    Paddle(int xin, int pinIn);
    ~Paddle();
    int GetY() {return yPos;}
    int GetWidth() {return width;}
    int GetX() {return xPos;}
    int GetPoint() {return point;}
    void Update();
    void SetWidth(int widthIn) {width = widthIn;}
    void SetPoint(int pointIn) {point = pointIn;}
    void incrPoint() {point++;}
};

Paddle::Paddle()
{
  width = 10;
  yPos = 27;
  pin = 0;
  xPos = 0;
  point = 48;
}

Paddle::Paddle(int xin, int pinIn)
{
  width = 10;
  yPos = 27;
  pin = pinIn;
  xPos = xin;
  point = 48;
}

Paddle::~Paddle()
{
}

void Paddle::Update()
{
  yPos = analogRead(pin) / 19;
  display.drawFastVLine(xPos, yPos, width, WHITE);
}

/*----------------------------------------------------------------------------------

          Ball class

----------------------------------------------------------------------------------*/
class Ball
{
  private:
    int speedMod;
    
    int xPos;
    int yPos;
    int xSpeed;
    int ySpeed;

  public:
    Ball();
    ~Ball();
    bool persistant;
    int GetX(){return xPos;}
    int GetY(){return yPos;}
    void SetPer(bool perIn){persistant=perIn;}
    void SetMod(int modIn){speedMod=modIn;}
    void Update(Paddle& paddleRight, Paddle& paddleLeft);
    void WallCollide() {ySpeed= 0 - ySpeed;}
    void PaddleCollide(Paddle& paddleIn);
    void CheckPoint(Paddle& paddleRight, Paddle& paddleLeft);

  
    friend PowerUp Update(Ball& ballIn, Paddle& paddleRight, Paddle& paddleLeft);
    friend PowerUp PowerUp();
  
};

Ball::Ball()
{
    xPos = 64;
    yPos = 32;
    speedMod = 1;
    xSpeed=1;
    ySpeed=0;
    persistant=true;
}

Ball::~Ball()
{
}

void Ball::Update(Paddle& paddleRight, Paddle& paddleLeft)
{
  CheckPoint(paddleRight, paddleLeft);

  if (yPos <= 0 || yPos >= 64)WallCollide();

  if (xPos >= paddleRight.GetX()-xSpeed && xPos <= paddleRight.GetX())
  {
    PaddleCollide(paddleRight);
  }
  else if (xPos <= paddleLeft.GetX() - xSpeed && xPos >= paddleLeft.GetX())
  {
    PaddleCollide(paddleLeft);
  }

  xPos+=xSpeed*speedMod;
  yPos+=ySpeed*speedMod;
  
  display.drawPixel(xPos, yPos, WHITE);
}

void Ball::PaddleCollide(Paddle& paddleIn)
{
  int dif = yPos - paddleIn.GetY();
  int width = paddleIn.GetWidth();
  int seg = width/5;
  if (dif<width&&dif>=0)xSpeed=0-xSpeed;
  
  if (dif >= 0 && dif < seg)ySpeed=-2;
  else if (dif >= seg && dif < 2*seg)ySpeed=-1;
  else if  (dif>=2*seg && dif < width-2*seg)
  {
    xSpeed=xSpeed*2;
    ySpeed=0;
  }
  else if (dif >= width-2*seg && dif < width-seg)ySpeed=1;
  else if(dif>=width-seg && dif<width)ySpeed=2;
}

void Ball::CheckPoint(Paddle& paddleRight, Paddle& paddleLeft)
{
  if (xPos <= 0)
  {
    paddleRight.incrPoint();
    tone(12, 261);
    delay(50);
    noTone(12);
    if(persistant)
    {
      xPos = 64;
      yPos = 32;
      xSpeed=1;
      ySpeed=0;
    }
    else 
    {
      xPos=-1;
      yPos=-1;
      xSpeed=0;
      ySpeed=0;
    }
  }

  if (xPos >= 128)
  {
    paddleLeft.incrPoint();
    tone(12, 261);
    delay(50);
    noTone(12);
    if(persistant)
    {
      xPos = 64;
      yPos = 32;
      xSpeed=-1;
      ySpeed=0;
    }
    else 
    {
      xPos=-1;
      yPos=-1;
      xSpeed=0;
      ySpeed=0;
    }
  }
}


/*----------------------------------------------------------------------------------

          Power class

----------------------------------------------------------------------------------*/

class PowerUp
{
  private:

    int xPos;
    int yPos;
    Ball Extra;
    long int timer;
    char symbol;
    int sizeMod;
    bool visible;

   public:

    PowerUp();
    ~PowerUp();
    
    void Update(Ball& ballIn, Paddle& paddleRight, Paddle& paddleLeft);
    
};

PowerUp::PowerUp()
{
  char list[] = {'+', (char)19, (char)18, (char)21, '0', (char)14};
  symbol = list[random(0,5)];
  xPos=-1;
  yPos=-1;
  sizeMod=1;
  visible=false;
  timer=millis();
  Ball Extra;
  Extra.persistant=false;
}

PowerUp::~PowerUp()
{
}

void PowerUp::Update(Ball& ballIn, Paddle& paddleRight, Paddle& paddleLeft)
{
  
  if(millis()-timer>8000)
  {
    if(!visible)
    {
      char list[] = {'+', (char)19, (char)18, (char)21, '0', (char)14};
      xPos=random(20, 108);
      yPos=random(7, 57);
      symbol = list[random(0,5)];
      visible=true;
    }
    else
    {
      xPos=-1;
      yPos=-1;
      visible=false;
    }
    timer=millis();
  }
  
  if(ballIn.GetX() >= xPos && ballIn.GetX() <= xPos+5*sizeMod && ballIn.GetY()>= yPos && ballIn.GetY()<= yPos+8*sizeMod)
  {
    visible=false;
    display.drawChar(xPos, yPos, symbol, WHITE, BLACK, sizeMod);
    switch(symbol)
    {
  /*     case '+':
          Extra.xPos=64;
          Extra.yPos=32;
          Extra.xSpeed=2;
          break;
     /*   case (char)19:
          ballIn.speedMod++;
          break; 
        case (char)18:
          if(ballIn.xSpeed>0)paddleLeft.SetWidth(14);
          else paddleRight.SetWidth(14);
          break;
        case (char)21:
     /*    ballIn.ySpeed=4;
          break;
        case '0':
          /*if(ballIn.xSpeed>0)paddleLeft.SetPoint(0);
          else paddleRight.SetPoint(0);
          break;*/
        case (char)14:
          tone(12, 261);
          delay(1000);
          tone(12, 330);
          delay(1000);
          tone(12, 261);
          delay(1000);
          tone(12, 330);
          delay(1000);
          tone(12, 392);
          delay(800);
          noTone(12);
          delay(200);
          tone(12, 392);
          delay(1000);
          noTone(12);
          break;     
    }
  }
  if(visible)display.drawChar(xPos, yPos, symbol, WHITE, BLACK, sizeMod);
  
}

/*-----------------------------------------------------------------------------------------------

               Main body of code

-----------------------------------------------------------------------------------------------*/

void setup()   {
  Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  pinMode(12, OUTPUT);

}
void loop()
{

  Paddle left(5, 0);
  Paddle right(123, 1);
  Ball myBall;
  PowerUp myPower;

  while (true)
  {
    left.Update();
    right.Update();
    myBall.Update(right, left);
    myPower.Update(myBall, right, left);
    display.drawChar(10, 10, char(left.GetPoint()), WHITE, BLACK, 1);
    display.drawChar(118, 10, char(right.GetPoint()), WHITE, BLACK, 1);
    if (left.GetPoint() == 57 || right.GetPoint() == 57)
    {
      left.SetPoint(48);
      right.SetPoint(48);
    }
    display.display();
    display.clearDisplay();
  }
}


