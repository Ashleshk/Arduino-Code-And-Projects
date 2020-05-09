#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte p00[8] = {
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,  
};

byte p01[8] = {
  B01000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,  
  B00000,
};

byte p02[8] = {
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte p12[8] = {
  B00000,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte p22[8] = {
  B00000,
  B00000,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte p21[8] = {
  B00000,
  B00000,
  B01000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte p20[8] = {
  B00000,
  B00000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte p10[8] = {
  B00000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
 byte p11[8] = {
  B00000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
// 3x3 Two-dimesional array of pointers to arrays of 8 bytes.
byte *array[9] = {p00,p01,p02,p10,p11,p12,p20,p21,p22};

void setup()
{
}

void loop()
{
  for (int row=0; row<9;row++)
  {
   
      lcd.createChar(1,array[row]);  // Value is a pointer to an array of 8 bytes
      lcd.setCursor(0,0);
      lcd.write(1);
    }
  
}
