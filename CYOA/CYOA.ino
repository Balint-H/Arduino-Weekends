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
//SDA->A4 SCL->A5

int bookmark = 0;
int page=0;
int pageMax=0;
bool a = 0;
bool b = 0;
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
void intro();
void setup()
{
  pinMode(7, INPUT);
  pinMode(12, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  lcd.begin (20,4);
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
    
    intro();
    lcd.clear();
    lcd.home ();
    bookmark=-1;
    lcd.print(F("1) Backstory        "));
    lcd.setCursor (0,1);
    lcd.print(F("2) Start the game   "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  
  
  while (bookmark==-1)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=0;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
}

  }
}
void loop()
{
  while(bookmark==0){
    Bookmark0(page);
  }
  while(bookmark==1){
    Bookmark1(page);
  }
  while(bookmark==2){
    Bookmark2(page);
  }
  while(bookmark==3){
    Bookmark3(page);
  }
  while(bookmark==4){
    Bookmark4(page);     
  }
  while(bookmark==5){
    Bookmark5(page);
  }
  while(bookmark==6){
    Bookmark6(page);     
  }
  while(bookmark==7){
    Bookmark7(page);
  }
  while(bookmark==8){
    Bookmark8(page);
  }
  while(bookmark==9){
    Bookmark9(page);
  }
  while(bookmark==10){
    Bookmark10(page);
  }
  while(bookmark==11){
    Bookmark11(page);
  }
  while(bookmark==12){
    Bookmark12(page);
  }
  while(bookmark==13){
    Bookmark13(page);
  }
  while(bookmark==14){
    Bookmark14(page);
  }
}

//                                                                                         --Example bookmark--
//void Bookmark(int o)
//{
//  if (o==0)
//  {
//    
//    lcd.home ();
//    lcd.print(F("This is page one"));  
//  }
//
//  if(o==1)
//  {
//    
//    lcd.home ();
//    lcd.print(F("This is page two"));  
//  }
//
//  if(o==2)
//  {
//    
//    lcd.home ();
//    lcd.print(F("This is page three"));  
//  }
//
//  if(o==3)
//  {
//    
//    lcd.home ();
//    lcd.print(F("This is page four"));  
//  }
//
//                                                                                          --Example choice--
//  if (page==pageMax)
//    {
//      
//      lcd.home ();
//      lcd.print(F("[1] Choice one    "));
//      lcd.setCursor (0,1);
//      lcd.print(F("[2] Choice two"));
//    }
//  
//  while (page==pageMax)
//  {
//    if (digitalRead(4)==HIGH)
//    {
//      bookmark=destination
//      page=0
//      delay(5)
//    }
//    
//    if (digitalRead(2)==HIGH)
//    {
//      bookmark=destination
//      page=0
//      delay(5)
//    }
//    pageUp()
//    pageDown()
//  }

//                                                                                           --Turning pages--
void pageUp()
{
  if (digitalRead(12)==HIGH && a==LOW)
  {
    if( page < pageMax)
    {
    page++;
    }
    a = 1;
  }

   if (digitalRead(12)==0)
  {
    a = 0;
  }
}

void pageDown()
{
  if (digitalRead(7)==1 && b==0)
  {
   if (page>0)
   {
    page--;
   }
    b = 1;
  }
  if (digitalRead(7)==0)
  {
    b = 0;
  }
}
//                                                                                               --Bookmarks--
void Bookmark0(int o)
{
  pageMax=8;
  if (o==0)
  {
    lcd.home ();
    lcd.print(F("You are a postman by"));  
    lcd.setCursor (0,1);
    lcd.print(F("trade. You spend    "));
    lcd.setCursor (0,2);
    lcd.print(F("your days travelling"));
    lcd.setCursor (0,3);
    lcd.print(F("between one perilous"));
  }

  if(o==1)
  {
    lcd.home ();
    lcd.print(F("destination and     ")); 
    lcd.setCursor (0,1);
    lcd.print(F("another. Your most  "));
    lcd.setCursor (0,2);
    lcd.print(F("recent job has you  "));
    lcd.setCursor (0,3);
    lcd.print(F("travelling to Khare,"));
  }
  if(o==2)
  {
    lcd.home ();
    lcd.print(F("a city filled with ")); 
    lcd.setCursor (0,1);
    lcd.print(F("unsavoury folk. The"));
    lcd.setCursor (0,2);
    lcd.print(F("road has been      "));
    lcd.setCursor (0,3);
    lcd.print(F("uneventful, but it  "));
  }   
  if(o==3)
  {
    lcd.home ();
    lcd.print(F("leads you now       ")); 
    lcd.setCursor (0,1);
    lcd.print(F("through the infamous"));
    lcd.setCursor (0,2);
    lcd.print(F("Forest of Thieves.  "));
    lcd.setCursor (0,3);
    lcd.print(F("While you have      "));
  }    
   if(o==4)
  {
    lcd.home ();
    lcd.print(F("little in terms of  ")); 
    lcd.setCursor (0,1);
    lcd.print(F("weapons, you do have"));
    lcd.setCursor (0,2);
    lcd.print(F("a magic scroll in   "));
    lcd.setCursor (0,3);
    lcd.print(F("your pouch.         "));
  }  
   if(o==5)
  {
    lcd.home ();
    lcd.print(F("The old woman who   ")); 
    lcd.setCursor (0,1);
    lcd.print(F("gave it to you along"));
    lcd.setCursor (0,2);
    lcd.print(F("her letters swears  "));
    lcd.setCursor (0,3);
    lcd.print(F("it can cast the     "));
  }          
   if(o==6)
  {
    lcd.home ();
    lcd.print(F("spell 'Fireball',   ")); 
    lcd.setCursor (0,1);
    lcd.print(F("but then again, she "));
    lcd.setCursor (0,2);
    lcd.print(F("is sending her      "));
    lcd.setCursor (0,3);
    lcd.print(F("letters to a cat, so"));
  }        
   if(o==7)
  {
    lcd.home ();
    lcd.print(F("her claim sounds a  ")); 
    lcd.setCursor (0,1);
    lcd.print(F("bit dubious.        "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }                          
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) Start            "));
    lcd.setCursor (0,1);
    lcd.print(F("                    "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark1(int o)
{
  pageMax=7;
  if (o==0)
  {
    lcd.home ();
    lcd.print(F("You are walking     "));  
    lcd.setCursor (0,1);
    lcd.print(F("along a peaceful    "));
    lcd.setCursor (0,2);
    lcd.print(F("forest path, when   "));
    lcd.setCursor (0,3);
    lcd.print(F("suddenly two bandits"));
  }

  if(o==1)
  {
    lcd.home ();
    lcd.print(F("land before you,    ")); 
    lcd.setCursor (0,1);
    lcd.print(F("leaping from the    "));
    lcd.setCursor (0,2);
    lcd.print(F("canopies of trees   "));
    lcd.setCursor (0,3);
    lcd.print(F("lining the path.    "));
  }

  if(o==2)
  {
    lcd.home ();
    lcd.print(F("'Hey man, this is  "));
    lcd.setCursor (0,1);
    lcd.print(F("like, larceny or   "));
    lcd.setCursor (0,2);
    lcd.print(F("something similar.'"));
    lcd.setCursor (0,3);
    lcd.print(F("-says a bandit     "));
  }

  if(o==3)
  {
    lcd.home ();
    lcd.print(F("wearing a makeshift ")); 
    lcd.setCursor (0,1);
    lcd.print(F("mask depicting a    "));
    lcd.setCursor (0,2);
    lcd.print(F("frozen skull.       "));
    lcd.setCursor (0,3);
    lcd.print(F("'I think you mean   ")); 
  }

if(o==4)
  {
    lcd.home ();
    lcd.print(F("robbery, boss.'     ")); 
    lcd.setCursor (0,1);
    lcd.print(F("-interjects the     "));
    lcd.setCursor (0,2);
    lcd.print(F("the other ruffian.  "));
    lcd.setCursor (0,3);
    lcd.print(F("'Shut up! You aren't")); 
  }

  if(o==5)
  {
    lcd.home ();
    lcd.print(F("always right,       ")); 
    lcd.setCursor (0,1);
    lcd.print(F("Jerry!'             "));
    lcd.setCursor (0,2);
    lcd.print(F("-the boss retorts.  "));
    lcd.setCursor (0,3);
    lcd.print(F("He is fuming with   ")); 
  }

  if(o==6)
  {
    lcd.home ();
    lcd.print(F("anger.              ")); 
    lcd.setCursor (0,1);
    lcd.print(F("                    "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    ")); 
  }
                                                                                          
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) Side with Jerry  "));
    lcd.setCursor (0,1);
    lcd.print(F("2) Shoot a fireball "));
    lcd.setCursor (0,2);
    lcd.print(F("   while they are   "));
    lcd.setCursor (0,3);
    lcd.print(F("   distracted!      "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=2;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=3;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark2(int o)
{
  pageMax=7;
  if (o==0)
  {
    lcd.home ();
    lcd.print(F("'You obviously just "));
    lcd.setCursor (0,1);
    lcd.print(F("want to show off you"));
    lcd.setCursor (0,2);
    lcd.print(F("know the word       "));
    lcd.setCursor (0,3);
    lcd.print(F("'larceny'. And      "));
  }

  if(o==1)
  {  
    lcd.home ();
    lcd.print(F("besides that, Jerry "));  
    lcd.setCursor (0,1);
    lcd.print(F("is right; this is   "));
    lcd.setCursor (0,2);
    lcd.print(F("just plain robbery.'"));
    lcd.setCursor (0,3);
    lcd.print(F("-you add to the     "));
  }

  if(o==2)
  {
    lcd.home ();
    lcd.print(F("conversation.       "));  
    lcd.setCursor (0,1);
    lcd.print(F("'Face it boss. I'm  "));
    lcd.setCursor (0,2);
    lcd.print(F("right, once again'  "));
    lcd.setCursor (0,3);
    lcd.print(F("-Jerry says.        "));
  }

  if(o==3)
  {
    lcd.home ();
    lcd.print(F("'Well, I see NO     ")); 
    lcd.setCursor (0,1);
    lcd.print(F("REASON why I should "));
    lcd.setCursor (0,2);
    lcd.print(F("STAND here and take "));
    lcd.setCursor (0,3);
    lcd.print(F("this from YOU two!' ")); 
  }

  if(o==4)
  {
    lcd.home ();
    lcd.print(F("-shouts the boss.   ")); 
    lcd.setCursor (0,1);
    lcd.print(F("He throws down his  "));
    lcd.setCursor (0,2);
    lcd.print(F("mask and stomps     "));
    lcd.setCursor (0,3);
    lcd.print(F("away. Jerry turns   ")); 
  }
  
  if(o==5)
  {
    lcd.home ();
    lcd.print(F("to you:             ")); 
    lcd.setCursor (0,1);
    lcd.print(F("'You are a pretty   "));
    lcd.setCursor (0,2);
    lcd.print(F("chill dude. Are you "));
    lcd.setCursor (0,3);
    lcd.print(F("headed to the city? ")); 
  }
if(o==6)
  {
    lcd.home ();
    lcd.print(F("If so I'd like to   ")); 
    lcd.setCursor (0,1);
    lcd.print(F("tag along.'         "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    ")); 
  }
                                                                                          
  if (page==pageMax)
  {
    lcd.home ();
    lcd.print(F("1)'Yeah, sure'      "));
    lcd.setCursor (0,1);
    lcd.print(F("2)'No way, dipshit' "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=14;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=4;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark3(int o)
{
  pageMax=10;
  if (o==0)
  {
    lcd.home ();
    lcd.print(F("You unleash your    ")); 
    lcd.setCursor (0,1);
    lcd.print(F("inner arcane power  "));
    lcd.setCursor (0,2);
    lcd.print(F("in the form of a    "));
    lcd.setCursor (0,3);
    lcd.print(F("mighty fireball.    ")); 
  }

  if(o==1)
  { 
    lcd.home ();
    lcd.print(F("The smouldering     "));  
    lcd.setCursor (0,1);
    lcd.print(F("projectile soars    "));
    lcd.setCursor (0,2);
    lcd.print(F("through the air,    "));
    lcd.setCursor (0,3);
    lcd.print(F("only to be absorbed "));
  }

  if(o==2)
  {
    lcd.home ();
    lcd.print(F("by the mask of the  "));  
    lcd.setCursor (0,1);
    lcd.print(F("bandit boss.        "));
    lcd.setCursor (0,2);
    lcd.print(F("'See Jerry? Mask of "));
    lcd.setCursor (0,3);
    lcd.print(F("protection from     "));
  }

  if(o==3)
  {
    lcd.home ();
    lcd.print(F("fireballs. I knew   "));  
    lcd.setCursor (0,1);
    lcd.print(F("it would come in    "));
    lcd.setCursor (0,2);
    lcd.print(F("handy. Now, you     "));
    lcd.setCursor (0,3);
    lcd.print(F("imbecile! Prepare to"));
  }

 if(o==4)
  {
    lcd.home ();
    lcd.print(F("be liquid dated!'   "));  
    lcd.setCursor (0,1);
    lcd.print(F("'Boss, it's one     "));
    lcd.setCursor (0,2);
    lcd.print(F("word'.              "));
    lcd.setCursor (0,3);
    lcd.print(F("'Sorry?'            "));
  }
  if(o==5)
  {
    lcd.home ();
    lcd.print(F("'Liquidate. One word"));  
    lcd.setCursor (0,1);
    lcd.print(F("'GODDAMMIT JERRY!   "));
    lcd.setCursor (0,2);
    lcd.print(F("Can't you just let  "));
    lcd.setCursor (0,3);
    lcd.print(F("me have this one?   "));
  }       
 if(o==6)
  {
    lcd.home ();
    lcd.print(F("Gah, let's just kill"));  
    lcd.setCursor (0,1);
    lcd.print(F("this idiot.'        "));
    lcd.setCursor (0,2);
    lcd.print(F("Without the aid of  "));
    lcd.setCursor (0,3);
    lcd.print(F("magic, you are      "));
  }
 if(o==7)
  {
    lcd.home ();
    lcd.print(F("promptly dispatched."));  
    lcd.setCursor (0,1);
    lcd.print(F("You die bleeding out"));
    lcd.setCursor (0,2);
    lcd.print(F("from multiple wounds"));
    lcd.setCursor (0,3);
    lcd.print(F("while the two       "));
  }
 if(o==8)
  {
    lcd.home ();
    lcd.print(F("highwaymen argue    "));  
    lcd.setCursor (0,1);
    lcd.print(F("about vocabulary.   "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }
    if(o==9)
  {
    lcd.home ();
    lcd.print(F("|    GAME OVER     |"));  
    lcd.setCursor (0,1);
    lcd.print(F("                    "));
    lcd.setCursor (0,2);
    lcd.print(F("-Ending 1/6         "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }                                                                               
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) Try again?       "));
    lcd.setCursor (0,1);
    lcd.print(F("2) Try again.       "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark4(int o)
{
  pageMax=4;
  if (o==0)
  {
    lcd.home ();
    lcd.print(F("'Oh. I uh, see.'    "));  
    lcd.setCursor (0,1);
    lcd.print(F("                    "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }

  if(o==1)
  {
    lcd.home ();
    lcd.print(F("                    ")); 
    lcd.setCursor (0,1);
    lcd.print(F("       '...'        "));
    lcd.setCursor (0,2);
    lcd.print(F("Jerry awkwardly     "));
    lcd.setCursor (0,3);
    lcd.print(F("kicks at the ground."));
  }

  if(o==2)
  {
    lcd.home ();
    lcd.print(F("He looks at you:   "));
    lcd.setCursor (0,1);
    lcd.print(F("'Yeah. Good times. "));
    lcd.setCursor (0,2);
    lcd.print(F("Listen, I'm gonna  "));
    lcd.setCursor (0,3);
    lcd.print(F("go now, alright?'  "));
  }

  if(o==3)
  {
    lcd.home ();
    lcd.print(F("He quickly snatches ")); 
    lcd.setCursor (0,1);
    lcd.print(F("the mask off the    "));
    lcd.setCursor (0,2);
    lcd.print(F("ground. He winks at "));
    lcd.setCursor (0,3);
    lcd.print(F("you.                ")); 
  }
                                               
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) Wink back        "));
    lcd.setCursor (0,1);
    lcd.print(F("2) 'Wait, what's    "));
    lcd.setCursor (0,2);
    lcd.print(F("   the deal with the"));
    lcd.setCursor (0,3);
    lcd.print(F("   mask?'           "));
    bookmark=2;
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=7;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=5;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark5(int o)
{
  pageMax=2;
  if (o==0)
  {
    lcd.home ();
    lcd.print(F("'This is how we tell"));  
    lcd.setCursor (0,1);
    lcd.print(F("which bandit guild  "));
    lcd.setCursor (0,2);
    lcd.print(F("you belong to. If   "));
    lcd.setCursor (0,3);
    lcd.print(F("you are travelling  "));
  }

  if(o==1)
  {
    lcd.home ();
    lcd.print(F("without one we just ")); 
    lcd.setCursor (0,1);
    lcd.print(F("assume you are free "));
    lcd.setCursor (0,2);
    lcd.print(F("game for mugging and"));
    lcd.setCursor (0,3);
    lcd.print(F("killing. Yup.'      "));
  }
                                               
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) 'I'm going to    "));
    lcd.setCursor (0,1);
    lcd.print(F("   take that, thank "));
    lcd.setCursor (0,2);
    lcd.print(F("   you.            '"));
    lcd.setCursor (0,3);
    lcd.print(F("2) 'Cool. Bye!'     "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=6;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=7;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark6(int o)
{
  pageMax=4;
  if (o==0)
  {
    lcd.home ();
    lcd.print(F("Push turns to shove,"));  
    lcd.setCursor (0,1);
    lcd.print(F("and you find        "));
    lcd.setCursor (0,2);
    lcd.print(F("yourself wrestling  "));
    lcd.setCursor (0,3);
    lcd.print(F("on the ground with  "));
  }

  if(o==1)
  {
    lcd.home ();
    lcd.print(F("Jerry. He manages to")); 
    lcd.setCursor (0,1);
    lcd.print(F("bite the end of your"));
    lcd.setCursor (0,2);
    lcd.print(F("ear off, but in the "));
    lcd.setCursor (0,3);
    lcd.print(F("end you hold the    "));
  }
  if(o==2)
  {
    lcd.home ();
    lcd.print(F("mask in your hands. ")); 
    lcd.setCursor (0,1);
    lcd.print(F("Jerry turns back as "));
    lcd.setCursor (0,2);
    lcd.print(F("he flees: 'If I run "));
    lcd.setCursor (0,3);
    lcd.print(F("into my friends, we "));
  }   
  if(o==3)
  {
    lcd.home ();
    lcd.print(F("are going to hunt   ")); 
    lcd.setCursor (0,1);
    lcd.print(F("you down, asshole!' "));
    lcd.setCursor (0,2);
    lcd.print(F("He is legging it    "));
    lcd.setCursor (0,3);
    lcd.print(F("towards the city.   "));
  }                                          
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) Fry him with your"));
    lcd.setCursor (0,1);
    lcd.print(F("   fireball         "));
    lcd.setCursor (0,2);
    lcd.print(F("2) 'Good riddance!' "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=8;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=9;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark7(int o)
{
  pageMax=6;
  if (o==0)
  {
    lcd.home ();
    lcd.print(F("Good times, good    "));  
    lcd.setCursor (0,1);
    lcd.print(F("times. You are about"));
    lcd.setCursor (0,2);
    lcd.print(F("a mile down the road"));
    lcd.setCursor (0,3);
    lcd.print(F("when suddenly you   "));
  }

  if(o==1)
  {
    lcd.home ();
    lcd.print(F("are transformed into")); 
    lcd.setCursor (0,1);
    lcd.print(F("a pincushion by a   "));
    lcd.setCursor (0,2);
    lcd.print(F("dozen crossbow bolts"));
    lcd.setCursor (0,3);
    lcd.print(F("piercing your soft, "));
  }
  if(o==2)
  {
    lcd.home ();
    lcd.print(F("tender torso.       ")); 
    lcd.setCursor (0,1);
    lcd.print(F("'This one better    "));
    lcd.setCursor (0,2);
    lcd.print(F("have some money on  "));
    lcd.setCursor (0,3);
    lcd.print(F("him, or else... well"));
  }   
  if(o==3)
  {
    lcd.home ();
    lcd.print(F("he's already dead.' ")); 
    lcd.setCursor (0,1);
    lcd.print(F("-you hear as your   "));
    lcd.setCursor (0,2);
    lcd.print(F("lungs are filling   "));
    lcd.setCursor (0,3);
    lcd.print(F("with blood. And     "));
  }   
    if(o==4)
  {
    lcd.home ();
    lcd.print(F("indeed, you are very")); 
    lcd.setCursor (0,1);
    lcd.print(F("much dead.          "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }                                  
    if(o==5)
  {
    lcd.home ();
    lcd.print(F("|    GAME OVER     |")); 
    lcd.setCursor (0,1);
    lcd.print(F("                    "));
    lcd.setCursor (0,2);
    lcd.print(F("-Ending 2/6         "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }        
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) Try again?       "));
    lcd.setCursor (0,1);
    lcd.print(F("2) Try again.       "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark8(int o)
{
  pageMax=7;
  if (o==0)
  {
    lcd.home ();
    lcd.print(F("A surge of mystical "));  
    lcd.setCursor (0,1);
    lcd.print(F("power leaves your   "));
    lcd.setCursor (0,2);
    lcd.print(F("fingertips as a ball"));
    lcd.setCursor (0,3);
    lcd.print(F("of rolling inferno  "));
  }

  if(o==1)
  {
    lcd.home ();
    lcd.print(F("goes barreling      ")); 
    lcd.setCursor (0,1);
    lcd.print(F("down the forest     "));
    lcd.setCursor (0,2);
    lcd.print(F("path, reducing      "));
    lcd.setCursor (0,3);
    lcd.print(F("everything in it's  "));
  }
  if(o==2)
  {
    lcd.home ();
    lcd.print(F("wake into mere ashes")); 
    lcd.setCursor (0,1);
    lcd.print(F("(This does indeed   "));
    lcd.setCursor (0,2);
    lcd.print(F("include Jerry.)     "));
    lcd.setCursor (0,3);
    lcd.print(F("You put on the mask."));
  }   
  if(o==3)
  {
    lcd.home ();
    lcd.print(F("You are about a mile")); 
    lcd.setCursor (0,1);
    lcd.print(F("down the road, when "));
    lcd.setCursor (0,2);
    lcd.print(F("you see a group     "));
    lcd.setCursor (0,3);
    lcd.print(F("waving at you.      "));
  }   
    if (o==4)
{
lcd.home ();
lcd.print(F("'Hey boss, we had a "));
lcd.setCursor (0,1);
lcd.print(F("good haul today. A  "));
lcd.setCursor (0,2);
lcd.print(F("caravan braved one  "));
lcd.setCursor (0,3);
lcd.print(F("of our \"shortcuts\".'"));
}

if(o==5)
{
lcd.home();
lcd.print(F("The man speaking    "));
lcd.setCursor (0,1);
lcd.print(F("motions to a cart   "));
lcd.setCursor (0,2);
lcd.print(F("surrounded by a     "));
lcd.setCursor (0,3);
lcd.print(F("dozen bandits. As he"));
}

if(o==6)
{
lcd.home();
lcd.print(F("glances back he     "));
lcd.setCursor (0,1);
lcd.print(F("adjusts his mask.   "));
lcd.setCursor (0,2);
lcd.print(F("'Huh. Where is      "));
lcd.setCursor (0,3);
lcd.print(F("Jerry?'             "));
}
        
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) He, uh,          "));
    lcd.setCursor (0,1);
    lcd.print(F("   abs-conded       "));
    lcd.setCursor (0,2);
    lcd.print(F("2) None of your damn"));
    lcd.setCursor (0,3);
    lcd.print(F("   business!        "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=10;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=11;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark9(int o){
  pageMax=6;
  if (o==0)
{
lcd.home ();
lcd.print(F("You secure the mask "));
lcd.setCursor (0,1);
lcd.print(F("on your face. About "));
lcd.setCursor (0,2);
lcd.print(F("a mile down the road"));
lcd.setCursor (0,3);
lcd.print(F("you spot a group of "));
}

if(o==1)
{
lcd.home();
lcd.print(F("a dozen bandits.    "));
lcd.setCursor (0,1);
lcd.print(F("Their leader is     "));
lcd.setCursor (0,2);
lcd.print(F("wearing a mask not  "));
lcd.setCursor (0,3);
lcd.print(F("unlike yours, if    "));
}

if(o==2)
{
lcd.home();
lcd.print(F("maybe a bit less    "));
lcd.setCursor (0,1);
lcd.print(F("impressive looking  "));
lcd.setCursor (0,2);
lcd.print(F("one. They are       "));
lcd.setCursor (0,3);
lcd.print(F("standing over a     "));
}

if(o==3)
{
lcd.home();
lcd.print(F("body, scratching    "));
lcd.setCursor (0,1);
lcd.print(F("their heads. One of "));
lcd.setCursor (0,2);
lcd.print(F("them notices you.   "));
lcd.setCursor (0,3);
lcd.print(F("'Oh Boss! I swear,  "));
}

if(o==4)
{
lcd.home();
lcd.print(F("this idiot Jerry was"));
lcd.setCursor (0,1);
lcd.print(F("running in the woods"));
lcd.setCursor (0,2);
lcd.print(F("alone, no mask, no  "));
lcd.setCursor (0,3);
lcd.print(F("warnings. So we shot"));
}

if(o==5)
{
lcd.home();
lcd.print(F("him out of reflex.  "));
lcd.setCursor (0,1);
lcd.print(F("How did you get     "));
lcd.setCursor (0,2);
lcd.print(F("separated?'         "));
lcd.setCursor (0,3);
lcd.print(F("                    "));
}

if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) Bluff            "));
    lcd.setCursor (0,1);
    lcd.print(F("                    "));
    lcd.setCursor (0,2);
    lcd.print(F("2) NOW it's fireball"));
    lcd.setCursor (0,3);
    lcd.print(F("   time!            "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=12;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=13;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark10(int o)
{
  pageMax=4;
  if (o==0)
{
lcd.home ();
lcd.print(F("'Wow boss! I'm sure "));
lcd.setCursor (0,1);
lcd.print(F("impressed with all  "));
lcd.setCursor (0,2);
lcd.print(F("these complicated   "));
lcd.setCursor (0,3);
lcd.print(F("words you know.     "));
}

if(o==1)
{
lcd.home();
lcd.print(F("Alright, see you    "));
lcd.setCursor (0,1);
lcd.print(F("tomorrow.' They     "));
lcd.setCursor (0,2);
lcd.print(F("bought it. Nice. It "));
lcd.setCursor (0,3);
lcd.print(F("doesn't take you    "));
}

if(o==2)
{
lcd.home();
lcd.print(F("long to get to the  "));
lcd.setCursor (0,1);
lcd.print(F("gates of Khare from "));
lcd.setCursor (0,2);
lcd.print(F("here.               "));
lcd.setCursor (0,3);
lcd.print(F("                    "));
}

if(o==3)
{
lcd.home();
lcd.print(F("-0-   CONGRATS   -0-"));
lcd.setCursor (0,1);
lcd.print(F("You did the thing.  "));
lcd.setCursor (0,2);
lcd.print(F("-Ending 3/6         "));
lcd.setCursor (0,3);
lcd.print(F("Thanks for playing. "));
}
if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("PLAY AGAIN?         "));
    lcd.setCursor (0,1);
    lcd.print(F("1) Yes.             "));
    lcd.setCursor (0,2);
    lcd.print(F("2) No, I just like  "));
    lcd.setCursor (0,3);
    lcd.print(F("   pressing buttons."));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }
    
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark11(int o){
  pageMax=4;
  if (o==0)
{
lcd.home ();
lcd.print(F("'I had it, I won't  "));
lcd.setCursor (0,1);
lcd.print(F("stand for this kind "));
lcd.setCursor (0,2);
lcd.print(F("of treatment! It's  "));
lcd.setCursor (0,3);
lcd.print(F("uh like, time to    "));
}

if(o==1)
{
lcd.home();
lcd.print(F("rebel?'  One of the "));
lcd.setCursor (0,1);
lcd.print(F("bandits exclaims.   "));
lcd.setCursor (0,2);
lcd.print(F("'You mean mutiny?'  "));
lcd.setCursor (0,3);
lcd.print(F("-you suggest.  A    "));
}

if(o==2)
{
lcd.home();
lcd.print(F("minute later you are"));
lcd.setCursor (0,1);
lcd.print(F("in small,           "));
lcd.setCursor (0,2);
lcd.print(F("pocket-sized pieces."));
lcd.setCursor (0,3);
lcd.print(F("                    "));
}

if(o==3)
  {
    lcd.home ();
    lcd.print(F("|    GAME OVER     |")); 
    lcd.setCursor (0,1);
    lcd.print(F("                    "));
    lcd.setCursor (0,2);
    lcd.print(F("-Ending 4/6         "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }        
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) Try again?       "));
    lcd.setCursor (0,1);
    lcd.print(F("2) Try again.       "));
    lcd.setCursor (0,2);
    lcd.print(F("                    "));
    lcd.setCursor (0,3);
    lcd.print(F("                    "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }

    if (digitalRead(2)==HIGH)
    {
    bookmark=1;
    page=0;
    delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark12(int o){
  pageMax==0;
  if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("1) He, uh,          "));
    lcd.setCursor (0,1);
    lcd.print(F("   abs-conded       "));
    lcd.setCursor (0,2);
    lcd.print(F("2) None of your damn"));
    lcd.setCursor (0,3);
    lcd.print(F("   business!        "));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=10;
      page=0;
      delay(5);
    }
    
    if (digitalRead(2)==HIGH)
    {
      bookmark=11;
      page=0;
      delay(5);
    }
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();

}

void Bookmark13(int o){
  pageMax=6;
  if (o==0)
{
lcd.home ();
lcd.print(F("You release a       "));
lcd.setCursor (0,1);
lcd.print(F("roaring boulder of  "));
lcd.setCursor (0,2);
lcd.print(F("liquid flame, which "));
lcd.setCursor (0,3);
lcd.print(F("consumes the closest"));
}

if(o==1)
{
lcd.home();
lcd.print(F("bandit, leaving     "));
lcd.setCursor (0,1);
lcd.print(F("nothing but cinders."));
lcd.setCursor (0,2);
lcd.print(F("You give an angry   "));
lcd.setCursor (0,3);
lcd.print(F("glance at the rest  "));
}

if(o==2)
{
lcd.home();
lcd.print(F("of the bandits, who,"));
lcd.setCursor (0,1);
lcd.print(F("wearing a look of   "));
lcd.setCursor (0,2);
lcd.print(F("disbelief, flee for "));
lcd.setCursor (0,3);
lcd.print(F("their lives. You hop"));
}

if(o==3)
{
lcd.home();
lcd.print(F("on one of the carts "));
lcd.setCursor (0,1);
lcd.print(F("laden with precious "));
lcd.setCursor (0,2);
lcd.print(F("goods, and set the  "));
lcd.setCursor (0,3);
lcd.print(F("horses going. It is "));
}

if(o==4)
{
lcd.home();
lcd.print(F("a smooth ride to    "));
lcd.setCursor (0,1);
lcd.print(F("Khare from here.    "));
lcd.setCursor (0,2);
lcd.print(F("                    "));
lcd.setCursor (0,3);
lcd.print(F("                    "));
}

if(o==5)
{
lcd.home();
lcd.print(F("-0-   CONGRATS   -0-"));
lcd.setCursor (0,1);
lcd.print(F("You did the thing.  "));
lcd.setCursor (0,2);
lcd.print(F("-Ending 5/6         "));
lcd.setCursor (0,3);
lcd.print(F("Thanks for playing. "));
}
if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("PLAY AGAIN?         "));
    lcd.setCursor (0,1);
    lcd.print(F("1) Yes.             "));
    lcd.setCursor (0,2);
    lcd.print(F("2) No, I just like  "));
    lcd.setCursor (0,3);
    lcd.print(F("   pressing buttons."));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }
    
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
}

void Bookmark14(int o){
  pageMax=4;
  if (o==0)
{
lcd.home ();
lcd.print(F("Jerry's face lights "));
lcd.setCursor (0,1);
lcd.print(F("up. 'Cool, it's time"));
lcd.setCursor (0,2);
lcd.print(F("to turn a new       "));
lcd.setCursor (0,3);
lcd.print(F("leaf!'. He puts on  "));
}

if(o==1)
{
lcd.home();
lcd.print(F("the mask and the two"));
lcd.setCursor (0,1);
lcd.print(F("of you make the trek"));
lcd.setCursor (0,2);
lcd.print(F("safely to Khare.    "));
lcd.setCursor (0,3);
lcd.print(F("Huh. That was easier"));
}

if(o==2)
{
lcd.home();
lcd.print(F("than expected.      "));
lcd.setCursor (0,1);
lcd.print(F("                    "));
lcd.setCursor (0,2);
lcd.print(F("                    "));
lcd.setCursor (0,3);
lcd.print(F("                    "));
}

if(o==3)
{
lcd.home();
lcd.print(F("-0-   CONGRATS   -0-"));
lcd.setCursor (0,1);
lcd.print(F("You did the thing.  "));
lcd.setCursor (0,2);
lcd.print(F("-Ending 6/6         "));
lcd.setCursor (0,3);
lcd.print(F("Thanks for playing. "));
}
if (page==pageMax)
  {
    
    lcd.home ();
    lcd.print(F("PLAY AGAIN?         "));
    lcd.setCursor (0,1);
    lcd.print(F("1) Yes.             "));
    lcd.setCursor (0,2);
    lcd.print(F("2) No, I just like  "));
    lcd.setCursor (0,3);
    lcd.print(F("   pressing buttons."));
  }
  
  while (page==pageMax)
  {
    if (digitalRead(4)==HIGH)
    {
      bookmark=1;
      page=0;
      delay(5);
    }
    
    pageUp();
    pageDown();
  }
  pageUp();
  pageDown();
  }
  
//                                                                                           --Intro--
void intro()
{
    lcd.home ();
    lcd.print(F("|     WELCOME!     |"));
    delay(1225);
    lcd.clear();
    lcd.setCursor (0,1);
    lcd.print(F("|     -to the-     |"));
    delay(1225);
    lcd.clear();
    lcd.setCursor (0,1);
    lcd.print(F("           ADVENTURE"));
    delay(100);
    for (int positionCounter = 0; positionCounter < 8; positionCounter++) 
    {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    delay(50);
    }
    lcd.clear();
    lcd.setCursor (0,1);
    lcd.print(F("   ADVENTURE        "));
    delay(200);
    lcd.setCursor (0,0);
    lcd.print(F("             ZONE   "));
    delay(80);
    lcd.setCursor (0,0);
    lcd.print(F("                    "));
    lcd.setCursor (0,1);
    lcd.print(F("   ADVENTURE ZONE   "));
    delay(80);
    lcd.setCursor (0,1);
    lcd.print(F("   ADVENTURE        "));
    lcd.setCursor (0,2);
    lcd.print(F("             ZONE   "));
    delay(125);
    lcd.setCursor (2,0);
    lcd.print(F("|"));
    lcd.setCursor (17,3);
    lcd.print(F("|"));
    delay(125);
    lcd.setCursor (2,1);
    lcd.print(F("|"));
    lcd.setCursor (17,2);
    lcd.print(F("|"));
    delay(125);
    lcd.setCursor (2,2);
    lcd.print(F("|"));
    lcd.setCursor (17,1);
    lcd.print(F("|"));
    delay(125);
    lcd.setCursor (2,3);
    lcd.print(F("|"));
    lcd.setCursor (17,0);
    lcd.print(F("|"));
    delay(125);
    lcd.setCursor (3,3);
    lcd.print(F("-"));
    lcd.setCursor (16,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (4,3);
    lcd.print(F("-"));
    lcd.setCursor (15,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (5,3);
    lcd.print(F("-"));
    lcd.setCursor (14,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (6,3);
    lcd.print(F("-"));
    lcd.setCursor (13,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (7,3);
    lcd.print(F("-"));
    lcd.setCursor (12,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (8,3);
    lcd.print(F("-"));
    lcd.setCursor (11,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (9,3);
    lcd.print(F("-"));
    lcd.setCursor (10,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (10,3);
    lcd.print(F("-"));
    lcd.setCursor (9,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (11,3);
    lcd.print(F("-"));
    lcd.setCursor (8,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (12,3);
    lcd.print(F("-"));
    lcd.setCursor (7,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (13,3);
    lcd.print(F("-"));
    lcd.setCursor (6,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (14,3);
    lcd.print(F("-"));
    lcd.setCursor (5,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (15,3);
    lcd.print(F("-"));
    lcd.setCursor (4,0);
    lcd.print(F("-"));
    delay(25);
    lcd.setCursor (16,3);
    lcd.print(F("-"));
    lcd.setCursor (3,0);
    lcd.print(F("-"));
    delay(75);
    lcd.setCursor (0,0);
    lcd.print(F("<"));
    lcd.setCursor (19,0);
    lcd.print(F(">"));
    delay(75);
    lcd.setCursor (1,1);
    lcd.print(F(">"));
    lcd.setCursor (18,1);
    lcd.print(F("<"));
    delay(75);
    lcd.setCursor (0,2);
    lcd.print(F("<"));
    lcd.setCursor (19,2);
    lcd.print(F(">"));
    delay(75);
    lcd.setCursor (1,3);
    lcd.print(F(">"));
    lcd.setCursor (18,3);
    lcd.print(F("<"));
    delay(2000);
}
