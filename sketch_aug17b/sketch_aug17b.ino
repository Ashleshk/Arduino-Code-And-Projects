#include <LiquidCrystal.h>

// initialize the library  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Char_Cnt=5,i=0;
int Cursor_ptr=0;

byte c0[8] = {
  0b00000,
  0b00000,
  0b00100,
  0b01110,
  0b10101,
  0b01110,
  0b00100,
  0b00000
};

byte c1[8] = {
  0b00000,
  0b00000,
  0b10001,
  0b01010,
  0b10101,
  0b01011,
  0b00101,
  0b00000
};
byte c2[8] = {
  0b00000,
  0b00000,
  0b01001,
  0b00101,
  0b00101,
  0b10101,
  0b01001,
  0b00000
};
byte c3[8] = {
  0b00000,
  0b00000,
  0b01001,
  0b10001,
  0b01001,
  0b10011,
  0b01101,
  0b00000
};
byte c4[8] = {
  0b00000,
  0b00000,
  0b00100,
  0b01001,
  0b00100,
  0b10010,
  0b01100,
  0b00000
};
 
 
byte *arr[8];                                                           //var contains info all byte arrays
byte *doublevar[3];


//arr[0]=&c0;   arr[1]=&c1;     arr[2]=&c2;     arr[3]=&c3;     arr[4]=&c4;
//var[5]=&c5;   var[6]=&c6;     var[7]=&c7;     var[8]=&c8;     var[9]=&c9;
//var[10]=&c10; var[11]=&c11;   var[12]=&c12;   var[13]=&c13;   var[14]=&c4;
//var[15]=&c15; var[16]=&c16;   var[17]=&c17;   var[18]=&c18;   var[19]=&c9;
//var[20]=&c20; var[21]=&c21;   var[22]=&c22;   var[23]=&c23;   var[24]=&c4;
//var[25]=&c25; var[26]=&c26;   var[27]=&c27;   var[28]=&c28;   var[29]=&c9;
//var[30]=&c30; var[31]=&c31;   var[32]=&c32;   var[33]=&c33;   var[34]=&c4;
//var[35]=&c35; var[36]=&c36;   var[37]=&c37;   var[38]=&c38;   var[39]=&c9;
//var[40]=&c40; var[41]=&c41;   var[42]=&c42;   var[43]=&c43;   var[44]=&c4;

//doublevar[0]=&dc0;    doublevar[1]=&dc1;    doublevar[2]=&dc2;


void CreateCharacter()                                         //becoz createchar only provision for 8 new character
{
  //for(int i=0;i<44;i++)
  
    lcd.createChar(1, c0); 
}
void setup() {
     lcd.createChar(1, c0);  
  
  lcd.begin(16, 2);
  lcd.print("hello Welcome");    
}

void loop() {
  //lcd.clear();   // clear hello welcome
  while(Cursor_ptr<15 && Char_Cnt>0)
  { 
     OnLcd(Cursor_ptr);
    //Cursor_ptr++;
    Char_Cnt--;

  }
  
  if(Char_Cnt==0)
  {
    //set back values and cursor
  Char_Cnt=5;
  Cursor_ptr=0;
  lcd.setCursor(Cursor_ptr,0);
  }
  //lcd.print("swalla");
   //lcd.setCursor(2, 0);
   //lcd.write(2);
    
}
int SetCursorLoc(int Cursor_ptr)
{
  Cursor_ptr=Cursor_ptr + 2 ;
 // Serial.println(Cursor_ptr);
  }
void OnLcd(int Cursor_ptr)
{
  lcd.setCursor(Cursor_ptr, 0);
    SetCursorLoc(Cursor_ptr);
   GetCharacter();
   delay(100);
 
}
void  GetCharacter()
{  //TODO get character details like b00000
  CreateCharacter();
  i++;
  lcd.write(1);
  
     delay(1000);    
}
