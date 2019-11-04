
String inputString = "";  
char input[800];
boolean stringComplete = false;
int countProgress = 0;
int prevcountProgress = -1;
int wordLength = 0;
int printProgress=0;
int lineProgress = 0; 
int lastprevcountProgress=0;
int o = 1;
int line = 0;
boolean go = false;

void setup()   
{
  Serial.begin(9600);  
  Serial.println(F("    --- 20x4 scroll code writer ---"));
  Serial.println(F("Type a string of letters above! The Arduino"));
  Serial.println(F("will convert it into a convenient piece of"));
  Serial.println(F("code, almost ready for LCD display."));
  Serial.println(F("Terminate input with #!"));
  Serial.println(F("Don't forget to change \" sign to"));
  Serial.println(F("quotation marks!"));
  Serial.print('\n');
  Serial.println(F("You are welcome, future me."));
  Serial.print('\n');
  Serial.println(F("Code:"));
  Serial.print('\n');
  Serial.print('\n');
  Serial.print('\n');
  inputString.reserve(800);
  Serial.println(F("if (o==0)"));
  Serial.println(F("{"));
  Serial.println(F("lcd.home ();"));
  Serial.print(F("lcd.print(F(\""));
}


void loop()                                
{
  if(stringComplete) 
  { 
    inputString.toCharArray(input,inputString.length()+1);
    stringComplete = false;
    
//    for(int i=0; i<inputString.length(); i++)
//    {
//      Serial.print(input[i]);
//    }
    go=true;
  }
  while(printProgress<inputString.length()-1&& go==true)
  {
    linePrint();
    newLine();
  }
}


void linePrint()
{
 while(lineProgress<=20)
 {
 bool toggle=0;
  while(toggle==0) 
  {
    if(input[countProgress]!=' ')
      { 
//        Serial.print("countProgress is:");
//        Serial.println(countProgress, DEC);
//        Serial.print('\n');
//        delay(200);
        countProgress=countProgress+1;
       
      }
      if(input[countProgress]==' ')
      {
//        Serial.print("countProgress is:");
//        Serial.println(countProgress, DEC);
//        Serial.println("Found space!");
//        delay(200);
        toggle=1;
    }
  }
//  delay(1000);
  wordLength= countProgress-prevcountProgress-1;
//  Serial.print("Done counting word! Length:");
//  Serial.print(wordLength, DEC);
//  delay(2000);
  lastprevcountProgress=prevcountProgress;
  prevcountProgress= countProgress;
  countProgress = countProgress+1;
//  delay(50);
  
  if(lineProgress+wordLength>20)
  {
    for(int i=0; i<20-lineProgress; i++)
    {
      Serial.print(' ');
    }
    lineProgress=0;
    countProgress= countProgress-wordLength-1;
    prevcountProgress= lastprevcountProgress;
    break;
  }

    if(lineProgress+wordLength==20)
  {
   for(int i=0; i<wordLength; i++)                                         
      {
        Serial.print(input[printProgress++]);
      }
      lineProgress=0;
      printProgress= printProgress+1;
//      Serial.print("(");
//    Serial.print(wordLength, DEC);
//    Serial.print(")");
      break;   
  }

  
  if(lineProgress+wordLength<20)
  {
    for(int i=0; i<wordLength+1; i++)                                         
      {
        Serial.print(input[printProgress++]);
      }
//    Serial.print("(");
//    Serial.print(wordLength, DEC);
//    Serial.print(")");
    lineProgress = lineProgress + wordLength+1;
//    Serial.print(lineProgress, DEC);
  }

  

  toggle=0;
 }
}
 
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '#') {
      stringComplete = true;
    }
  }
}







void newLine()
{
  if(line<3)
    {
    
    Serial.println(F("\"));"));
    Serial.print(F("lcd.setCursor (0,"));
    Serial.print(line+1, DEC);
    Serial.println(F(");"));
    Serial.print(F("lcd.print(F(\""));
    }
line++;
      if(line==4)
    {
     Serial.println(F("\"));"));
     Serial.println(F("}"));
     Serial.print('\n');
     Serial.print(F("if(o=="));
     Serial.print(o, DEC);
     Serial.println(F(")"));
     Serial.println(F("{"));
     Serial.println(F("lcd.home();"));
     Serial.print(F("lcd.print(F(\""));
     line=0;
     o++;
    }
}


