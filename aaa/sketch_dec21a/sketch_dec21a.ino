#include <LiquidCrystal.h> 
#include <Keypad.h> 
/////////////////////////////////////////////////////////////////////////////////
const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns

// Defining the Keypad
char keys[ROWS][COLS] = {

  {'7','8','9','D'},

  {'4','5','6','C'},

  {'1','2','3','B'},

  {'*','0','#','A'}

};

byte rowPins[ROWS] = { 0, 1, 2, 3 };// Connecting rows to the digital pins in the arduino 0:3
byte colPins[COLS] = { 4, 5, 6, 7 }; // Connecting columns to the digital pins in the arduino 4:7

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Creating the Keypad

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; // connected pins from LCD to arduino digital pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 long Num1,Num2,Number;
 char key,action;
 boolean result = false;
 
void setup() {
  lcd.begin(16, 2); // (16 cols , 2 rows) LCD
  lcd.print("HI ENG/ AHMED !"); // intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, row 1 (where to show on the LCD)
  lcd.print("try me .. "); // intro message 

   delay(3000); // intro msg will last to 3s
    lcd.clear(); // clearing after intro
}

void loop() {
  
key = kpd.getKey(); //storing pressed key value in a char

if (key!=NO_KEY)
DetectButtons();

if (result==true)
CalculateResult(); // a function to calculate the result

DisplayResult();   // a function to display the result
}

void DetectButtons()
{ 
     lcd.clear(); // Clear button to set LCD to default
    if (key=='*') // Clear
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}
    
     if (key == '1') 
    {Serial.println ("Button 1"); 
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1; // if Pressed twice
    }
    
     if (key == '4') 
    {Serial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; 
    }
    
     if (key == '7') 
    {Serial.println ("Button 7");
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7;
    } 
  

    if (key == '0')
    {Serial.println ("Button 0"); 
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; 
    }
    
     if (key == '2') 
    {Serial.println ("Button 2"); 
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; 
    }
    
     if (key == '5')
    {Serial.println ("Button 5"); 
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5;
    }
    
     if (key == '8')
    {Serial.println ("Button 8"); 
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; 
    }   
  

    if (key == '#') 
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result = true;
    }
    
     if (key == '3')
    {Serial.println ("Button 3"); 
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; 
    }
    
     if (key == '6')
    {Serial.println ("Button 6"); 
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; 
    }
    
     if (key == '9')
    {Serial.println ("Button 9");
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; 
    }  

      if (key == 'A' || key == 'B' || key == 'C' || key == 'D') // Column 4
  {
    Num1 = Number;    
    Number =0;
    if (key == 'A')
    {Serial.println ("Addition"); action = '+';}
     if (key == 'B')
    {Serial.println ("Subtraction"); action = '-'; }
     if (key == 'C')
    {Serial.println ("Multiplication"); action = '*';}
     if (key == 'D')
    {Serial.println ("Devesion"); action = '/';}  

    delay(100); // .1s to display the result
  }
  
}

void CalculateResult()
{

  if (action=='+')
    Number = Num1+Num2;

  else if (action=='-')
    Number = Num1-Num2;

  else if (action=='*')
    Number = Num1*Num2;

  else if (action=='/' && Num2 !=0)
     Number = Num1/Num2;
  else
     lcd.println(" error "); 
}

void DisplayResult()
{
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 0
  lcd.print(Num1); lcd.print(action); lcd.print(Num2); 
  
  if (result==true)
  {lcd.print(" ="); lcd.print(Number);} //Display the result
  
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
}

