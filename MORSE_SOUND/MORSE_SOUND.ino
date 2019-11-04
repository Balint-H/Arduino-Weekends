
char input[1][140];
int prog = 0;
int letternumber = 0;

//Unit of time:
int u = 100;

void setup()   
{
  Serial.begin(9600);  
  Serial.println("       --- Morse loop control ---");
  Serial.println("Type a string of capital letters above!");
  Serial.println("Every new word is added to the chain.");
  Serial.println("Press reset button to start a new chain.");
  Serial.print('\n');
  Serial.println("Maximum chain length: 140 characters");
  Serial.print("Unit speed is: ");
  Serial.print(u);
  Serial.print(" ms");
  Serial.print('\n');
  Serial.print('\n');
  Serial.println("                |ALPHABET|");
  Serial.println("A: .-    B: -...  C: -.-.  D: -..   E: . ");
  Serial.println("F: ..-.  G: --.   H: ....  I: ..    J: .--- ");
  Serial.println("K: -.-   L: .-..  M: --    N: -.    O: --- ");
  Serial.println("P: .--.  Q: --.-  R: .-.   S: ...   T: - ");
  Serial.println("U: ..-   V: ...-  W: .-.   X: -..-  Y: --.. ");
  Serial.println("                  Z: -.-.");
  
  pinMode(12, OUTPUT);
}


void loop()   //Assigning every input character to their respective place in the array
{
  while(Serial.available() > 0 && letternumber<140)
  {
    input[0][letternumber] = Serial.read();
    letternumber = letternumber+1;
  } 
  
   //Checking for every single letter for every character
  while ( prog <= letternumber)
  {
    if(input[0][prog]== 'A') 
    {
      A();
    }
    
    if(input[0][prog]== 'B')
    {
      B();
    }

    if(input[0][prog]== 'C') 
    {
      C();
    }
    
    if(input[0][prog]== 'D')
    {
      D();
    }

    if(input[0][prog]== 'E') 
    {
      E();
    }
    
    if(input[0][prog]== 'F')
    {
      letterF();
    }

    if(input[0][prog]== 'G')
    {
      G();
    }

    if(input[0][prog]== 'H') 
    {
      H();
    }
    
    if(input[0][prog]== 'I')
    {
      I();
    }

    if(input[0][prog]== 'J') 
    {
      J();
    }
    
    if(input[0][prog]== 'K')
    {
      K();
    }

    if(input[0][prog]== 'L') 
    {
      L();
    }
    
    if(input[0][prog]== 'M')
    {
      M();
    }

    if(input[0][prog]== 'N') 
    {
      N();
    }
    
    if(input[0][prog]== 'O')
    {
      O();
    }

    if(input[0][prog]== 'P') 
    {
      P();
    }
    
    if(input[0][prog]== 'Q')
    {
      Q();
    }

    if(input[0][prog]== 'R') 
    {
      R();
    }

    if(input[0][prog]== 'S') 
    {
      S();
    }
    
    if(input[0][prog]== 'T')
    {
      T();
    }

    if(input[0][prog]== 'U') 
    {
      U();
    }
    
    if(input[0][prog]== 'V')
    {
      V();
    }

    if(input[0][prog]== 'W') 
    {
      W();
    }
    
    if(input[0][prog]== 'X')
    {
      X();
    }

    if(input[0][prog]== 'Y') 
    {
      Y();
    }
    
    if(input[0][prog]== 'Z')
    {
      Z();
    }

    if(input[0][prog]== ' ') 
    {
      space();
    }
    
    prog = prog+1;

  }
  prog=0;
  space();  
}

//---Declaring standard components--- 

void dot()
{
  tone(12, 261);
  delay(u);
  noTone(12);
  delay(u);    
}

void dash()
{
  tone(12, 330);
  delay(3*u);
  noTone(12);
  delay(u);    
}

void letterend()
{
  delay(2*u);
}

void space()
{
  delay(4*u);
}

//---Declaring alphabet---

void A()
{
  dot();
  dash();
  letterend();
}

void B()
{
  dash();
  dot();
  dot();
  dot();
  letterend();
}

void C()
{
  dash();
  dot();
  dash();
  dot();
  letterend();
}

void D()
{
  dash();
  dot();
  dot();
  letterend();
}

void E()
{
  dot();
  letterend();
}

void letterF()
{
  dot();
  dot();
  dash();
  dot();
  letterend();
}

void G()
{
  dash();
  dash();
  dot();
  letterend();
}

void H()
{
  dot();
  dot();
  dot();
  dot();
  letterend();
}

void I()
{
  dot();
  dot();
  letterend();
}

void J()
{
  dot();
  dash();
  dash();
  dash();
  letterend();
}

void K()
{
  dash();
  dot();
  dash();
  letterend();
}

void L()
{
  dot();
  dash();
  dot();
  dot();
  letterend();
}

void M()
{
  dash();
  dash();
  letterend();
}

void N()
{
  dash();
  dot();
  letterend();
}

void O()
{
  dash();
  dash();
  dash();
  letterend();
}

void P()
{
   dot();
  dash();
  dash();
  dot();
  letterend();
}

void Q()
{
  dash();
  dash();
  dot();
  dash();
  letterend();
}

void R()
{
  dot();
  dash();
  dot();
  letterend();
}

void S()
{
  dot();
  dot();
  dot();
  letterend();
}

void T()
{
  dash();
  letterend();
}

void U()
{
  dot();
  dot();
  dash();
  letterend();
}

void V()
{
  dot();
  dot();
  dot();
  dash();
  letterend();
}

void W()
{
  dot();
  dash();
  dash();
  letterend();
}

void X()
{
  dash();
  dot();
  dot();
  dash();
  letterend();
}

void Y()
{
  dash();
  dot();
  dash();
  dash();
  letterend();
}

void Z()
{
  dash();
  dash();
  dot();
  dot();
  letterend();
}

