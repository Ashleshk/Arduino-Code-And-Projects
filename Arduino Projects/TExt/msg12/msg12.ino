#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int i,msg[10]={012};
void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
  // Print a message to the lcd.
  lcd.print("Alphabets");
  delay(2000);
  lcd.clear();
}
void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("A ");
  delay(2000);
  lcd.print("B ");
  delay(2000);
  lcd.print("C ");
 delay(2000);
  lcd.print("D ");
 delay(2000);
  lcd.print("E ");
 delay(2000);
  lcd.print("F ");
 delay(2000);
  lcd.print("G ");
 delay(2000);
  lcd.print("H ");
 delay(2000);
 lcd.setCursor(0,1);
  lcd.print("I ");
 delay(2000);
  lcd.print("J ");
  delay(2000);
  lcd.print("K ");
 delay(2000);
  lcd.print("L ");
 delay(2000);
  lcd.print("M ");
 delay(2000);
  lcd.print("N ");
 delay(2000);
  lcd.print("O ");
 delay(2000);
  lcd.print("P ");
 delay(2000);
 lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("Q ");
 delay(2000);
  lcd.print("R ");
 delay(2000);
  lcd.print("S ");
 delay(2000);
  lcd.print("T ");
 delay(2000);
  lcd.print("U ");
 delay(2000);
  lcd.print("V ");
 delay(2000);
  lcd.print("W ");
 delay(2000);
  lcd.print("X ");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("Y ");
 delay(2000);
  lcd.print("z ");
delay(2000);
 lcd.clear();
 
}


