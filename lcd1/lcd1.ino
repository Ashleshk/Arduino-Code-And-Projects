// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// make some custom characters:
byte j1[8] = {
  0b11001,
  0b00101,
  0b00101,
  0b00101,
  0b11011,
  0b00101,
  0b00101,
  0b11001
};

byte j2[8] = {
  0b11110,
  0b00001,
  0b00001,
  0b00001,
  0b11110,
  0b00001,
  0b00001,
  0b11110
};
byte j3[8] = {
  0b01010,
  0b01010,
  0b01010,
  0b01010,
  0b11010,
  0b01010,
  0b01010,
  0b01010
};

byte j4[8] = {
  0b00010,
  0b00110,
  0b01000,
  0b00110,
  0b01001,
  0b10101,
  0b01110,
  0b00100
};
byte j5[8]= {
  0b00000,
  0b00000,
  0b00000,
  0b00110,
  0b01000,
  0b10000,
  0b01000,
  0b00100
};
byte j6[8]={
  0b00010,
  0b00110,
  0b01000,
  0b00110,
  0b01001,
  0b10101,
  0b01110,
  0b00100
};
byte j7[8]={
  0b01110,
  0b10001,
  0b00001,
  0b00001,
  0b11110,
  0b00001,
  0b00001,
  0b11110
};





void setup() {
  // create a new character
  lcd.createChar(1, j1);
  // create a new character
 lcd.createChar(2, j2);
  // create a new character
  lcd.createChar(3, j3);
  // create a new character
  lcd.createChar(4, j4); 
  // create a new character
  lcd.createChar(7, j5); 
  
  
  lcd.createChar(5,j6); 
  lcd.createChar(6,j7); 


  // set up the lcd's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the lcd.
  //lcd.print("I ");
  //lcd.write(1);
  //lcd.print(" Arduino! ");
  //lcd.write(2);

}

  void loop() {
  // read the potentiometer on A0:
  int sensorReading = analogRead(A0);
  // map the result to 200 - 1000:
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  // set the cursor to the bottom row, 5th position:
  lcd.setCursor(0, 1);
  lcd.write(1);
   delay(delayTime);

  
  lcd.setCursor(2, 1);
  // draw a frownie
  lcd.write(2);
 lcd.setCursor(3, 1);
  // draw him arms up:
  lcd.write(3);
   delay(delayTime);

   
  lcd.setCursor(5, 1);
  // draw a smiley
  lcd.write(4);
  delay(delayTime);

  
    lcd.setCursor(7, 0);
    lcd.write(5);
    lcd.setCursor(7, 1);
  lcd.write(6);
  delay(delayTime);

  
    lcd.setCursor(9,1);
  lcd.write(7);
   lcd.setCursor(11, 1);
 // lcd.write(8);
  delay(delayTime);

  
  //lcd.setCursor(0, 1);
  //lcd.write(9);
  //lcd.setCursor(1, 1);
  //lcd.write(10);
   //delay(delayTime);
  
  
}






