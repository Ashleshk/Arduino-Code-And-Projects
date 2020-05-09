 
// include the library code:
#include <LiquidCrystal.h>
String voice;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, worldhkhvu!");
}

void loop() {
   while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
 
  if(voice == "*0") {lcd.clear();lcd.print("e1");delay(1000);} 
  else if(voice == "*1") {lcd.clear();lcd.print("e2");delay(1000);}
  else if(voice == "*2") {lcd.clear();lcd.print("e3");delay(1000);}
  else if(voice == "*3") {lcd.clear();lcd.print("e4");delay(1000);} 
  else if(voice == "*4") {lcd.clear();lcd.print("h1");delay(1000);}
  else if(voice == "*5") {lcd.clear();lcd.print("h2");delay(1000);}
  else if(voice == "*6") {lcd.clear();lcd.print("h3");delay(1000);}
  else if(voice == "*7") {lcd.clear();lcd.print("h4");delay(1000);}
 
 
//-----------------------------------------------------------------------//  
voice="";
}
}

