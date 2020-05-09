#include<LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
  void setup() {
  // put your setup code here, to run once:
   lcd.begin(16,2);
   
   lcd.print("PICT  PUNE");
   //lcd.scrollDisplayLeft();
   //lcd.rightToLeft();
   delay(1000);
   lcd.setCursor(3,1);
   lcd.print("LCD INTERface");   //ECAF
   //lcd.scrollDisplayRight();
   // delay(1000);
   //lcd.leftToRight();
    lcd.setCursor(2,1);
    delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  /* lcd.noDisplay();
   delay(2000);
   lcd.display();
   delay(2000);*/
   lcd.noBlink();
   delay(3000);
   lcd.blink();
   delay(3000);
   
   
}
