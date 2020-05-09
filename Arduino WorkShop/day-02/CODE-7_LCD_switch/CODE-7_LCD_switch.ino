#include<LiquidCrystal.h>
#define switch 12
LiquidCrystal lcd(2,3,4,5,6,7);
  void setup() {
  // put your setup code here, to run once:
   lcd.begin(16,2);
   lcd.setCursor(2,0);
   lcd.print("PICT  PUNE");
    
    pinMode(switch,INPUT);
   delay(3000);
   
  
}

void loop() {
  // put your main code here, to run repeatedly:

   delay(2000);
   lcd.display();
   delay(2000);*/
 /*  lcd.noBlink();
   delay(3000);
   lcd.blink();
   delay(3000);*/
   lcd.display();
   if(digitalRead(switch)==0)
   {
        lcd.clear();
         lcd.setCursor(4,0);
        lcd.print("SWITCH IS ");
        lcd.setCursor(5,2);
        lcd.print("PRESSED");
    
    }
    else
    {
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("SWITCH IS ");
         lcd.setCursor(3,2);
        lcd.print("NOT_PRESSED");
      }
   delay(30);
   lcd.noDisplay();
   
}
