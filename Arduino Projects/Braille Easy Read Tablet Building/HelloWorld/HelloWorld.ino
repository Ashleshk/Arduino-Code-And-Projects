          //common code: entry&1 entry&2 entry&4 entry&8 entry&16 entry&32
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
 
int data=0;
 

//data and datav
const char charac[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
const int charv[]={0b000001,0b000011,0b001001,0b011001,0b010001,0b001011,0b011011,0b010011,0b001010,0b011010,0b000101,0b000111,0b001101,0b011101,0b010101,0b001111,0b011111,0b010111,0b001110,0b011110,0b100101,0b100111,0b111010,0b101101,0b111101,0b110101};
const int charhv[]={0b000001,0b011100,0b001010,0b010100,0b100101,0b110011,0b010001,0b001100,0b010101,0b101010,0b000101,0b101000,0b011011,0b100011,0b101100,0b001001,0b100001,0b011010,0b110100,0b010010,0b111110,0b111010,0b101011,0b111111,0b111100,0b011110,0b111001,0b011001,0b101110,0b011101,0b001111,0b010110,0b000011,0b011000,0b001101,0b111101,0b010111,0b000111,0b100111,0b111000,0b101001,0b101111,0b001110,0b010011,0b011111,0b110001,0b001000,0b111011,0b100000,0b100010};

//vyanjan and swarr(c37)
byte c0[8]= {  0b00000,  0b11011,  0b00101,  0b00101,  0b01111,  0b00101,  0b11001,  0b00000};
byte c1[8]= {  0b00000,  0b11111,  0b00100,  0b01000,  0b00110,  0b01010,  0b01100,  0b00010};
byte c2[8]= {  0b00110,  0b00100,  0b00100,  0b01000,  0b00110,  0b01010,  0b01100,  0b00010};
byte c3[8]= {  0b00000,  0b11111,  0b01100,  0b00010,  0b01100,  0b00010,  0b01100,  0b00000};
byte c4[8]= {  0b00000,  0b11111,  0b11000,  0b00100,  0b11011,  0b00101,  0b11001,  0b00000};
byte c5[8]= {  0b00000,  0b11111,  0b10010,  0b10010,  0b01000,  0b00100,  0b00010,  0b00000};
byte c6[8]= {  0b01000,  0b00100,  0b10010,  0b10010,  0b01000,  0b00100,  0b00010,  0b00000};
byte c7[8]= {  0b00000,  0b11111,  0b00100,  0b01110,  0b10101,  0b01110,  0b00100,  0b00000};
byte c8[8]= {  0b00000,  0b11111,  0b01001,  0b01011,  0b10101,  0b10011,  0b01101,  0b00000};
byte c9[8]= {  0b00000,  0b11111,  0b01001,  0b00101,  0b00101,  0b10101,  0b01001,  0b00000};
byte c10[8]={  0b00000,  0b11111,  0b01001,  0b10001,  0b01001,  0b10011,  0b01101,  0b00000};
byte c11[8]={  0b00000,  0b11111,  0b00100,  0b01001,  0b00100, 0b10010,  0b01100,  0b00000};
byte c12[8]={  0b00000,  0b11111,  0b00001,  0b11101,  0b01001,  0b00111,  0b00001,  0b00000};
byte c13[8]={  0b00000,  0b11111,  0b01001,  0b10010,  0b01001,  0b10011,  0b01101,  0b00000};
byte c14[8]={  0b00000,  0b11111,  0b00001,  0b10111,  0b10101,  0b11101, 0b00001,  0b00000};
byte c15[8]={  0b00000,  0b11111,  0b01001,  0b10001,  0b01011,  0b00101,  0b11001,  0b01000};
byte c16[8]={  0b00000,  0b11111,  0b00001,  0b01101,  0b00011,  0b01101,  0b00001,  0b00000};
byte c17[8]={  0b00000,  0b11111,  0b00010,  0b00110,  0b01000,  0b01000,  0b00110,  0b00000};
byte c18[8]={  0b00000,  0b11111,  0b00100,  0b00100,  0b01010,  0b01010,  0b00100,  0b00000};
byte c19[8]={  0b00000,  0b11111,  0b00100,  0b01000,  0b00110,  0b10001,  0b01110,  0b00000};
byte c20[8]={  0b00000,  0b11111,  0b00100,  0b01000,  0b10010,  0b10101,  0b01110,  0b00000};
byte c21[8]={  0b00000,  0b11111,  0b10101,  0b10101,  0b10101,  0b10101,  0b01001,  0b00000};
byte c22[8]={  0b00000,  0b11111,  0b00001,  0b00111,  0b01001,  0b01001,  0b01001,  0b00000};
byte c23[8]={  0b00000,  0b11111,  0b01001,  0b10101,  0b01001,  0b10011,  0b01101,  0b00000};
byte c24[8]={  0b00000,  0b11111,  0b00010,  0b00110,  0b01000,  0b01010,  0b00110,  0b00001};
byte c25[8]={  0b00000,  0b01011,  0b10101,  0b01001,  0b10001,  0b10011,  0b01101,  0b00000};
byte c26[8]={  0b00000,  0b11111,  0b00001,  0b00001,  0b01111,  0b10101,  0b01001,  0b00000};
byte c27[8]={  0b00000,  0b11111,  0b01001,  0b01001,  0b00111,  0b00001,  0b00001,  0b00000};
byte c28[8]={  0b00000,  0b11111,  0b10100,  0b10100,  0b01111,  0b00101,  0b00101,  0b00000};
byte c29[8]={  0b00000,  0b11111,  0b00001,  0b00111,  0b01101,  0b01011,  0b00111,  0b00001};
byte c30[8]={  0b00000,  0b01011,  0b10101,  0b01101,  0b00101,  0b01111,  0b10101,  0b01001};
byte c31[8]={  0b00000,  0b11111,  0b00101,  0b00101,  0b01111,  0b10101,  0b01001,  0b00000};
byte c32[8]={  0b10010,  0b01100,  0b10010,  0b10010,  0b01000,  0b00100,  0b00010,  0b00000};
byte c33[8]={  0b00000,  0b11111,  0b01100,  0b00010,  0b00100,  0b01000,  0b00100,  0b00000};
byte c34[8]={  0b00000,  0b11111,  0b00010,  0b11010,  0b10101,  0b10101,  0b01010,  0b00000};
byte c35[8]={  0b00000,  0b11111,  0b00001,  0b00111,  0b01001,  0b01001,  0b00111,  0b00001};
byte c36[8]={  0b00000,  0b11111,  0b00001,  0b01011,  0b10101,  0b10001,  0b01001,  0b00000};
byte c37[8]={  0b00000,  0b01011,  0b10101,  0b01101,  0b00101,  0b11101,  0b01001,  0b00100};
byte c38[8]={  0b00000,  0b11111,  0b01101,  0b01011,  0b00111,  0b00001,  0b00001,  0b00000};
byte c39[8]={  0b00000,  0b11111,  0b10001,  0b01001,  0b10111,  0b01001,  0b00101,  0b00000};
byte c40[8]={  0b00000,  0b11111,  0b00100,  0b01000,  0b01100,  0b10010,  0b10000,  0b01100};
byte c41[8]={  0b00000,  0b01011,  0b10101,  0b01001,  0b10011,  0b10101,  0b01001,  0b00100};
byte c42[8]={  0b00000,  0b11111,  0b00001,  0b00111,  0b10101,  0b11001,  0b01001,  0b00000};
byte c43[8]={  0b00000,  0b00000,  0b00000,  0b00000,  0b00000,  0b01000,  0b00100,  0b00010};
byte c44[8]={  0b00000,  0b11111,  0b00100,  0b01001,  0b00100,  0b10010,  0b01100,  0b00100};
byte c45[8]={  0b00000,  0b11111,  0b01001,  0b01001,  0b10001,  0b10011,  0b01101,  0b00000};



//double cell swarrs
byte dcp0[8]={  0b00000,  0b00000,  0b01110,  0b00001,  0b01110,  0b00001,  0b01110,  0b00000};

byte dcp1[8]={  0b00000,  0b00000,  0b11111,  0b01010,  0b11010,  0b01010,  0b01010,  0b00000};
byte dcp2[8]={  0b00100,  0b00010,  0b11111,  0b01010,  0b11010,  0b01010,  0b01010,  0b00000};
byte dcp3[8]={  0b00101,  0b00010, 0b11111,  0b01010,  0b11010,  0b01010,  0b01010,  0b00000};
byte dcp4[8]={  0b00000,  0b00000,  0b11100,  0b01010,  0b11000,  0b01010,  0b01000,  0b00000};

//digits
byte d0[8]{  0b00000,  0b00100,  0b01010,  0b01010,  0b01010,  0b01010,  0b00100,  0b00000};
byte d1[8]{  0b00000,  0b00100,  0b01010,  0b00100,  0b01000,  0b00100,  0b00010,  0b00000};
byte d2[8]{  0b00000,  0b01100,  0b00010,  0b00100,  0b01000,  0b00100,  0b00010,  0b00000};
byte d3[8]{  0b00000,  0b01100,  0b00010,  0b01100,  0b00010,  0b01010,  0b01100,  0b00100};
byte d4[8]{  0b00000,  0b10001,  0b10001,  0b01010,  0b00100,  0b01010,  0b00100,  0b00000};
byte d5[8]{  0b00000,  0b10000,  0b10010,  0b10011,  0b01110,  0b00010,  0b00010,  0b00000};
byte d6[8]{  0b00000,  0b00110,  0b01000,  0b00110,  0b01000,  0b01010,  0b00110,  0b00010};
byte d7[8]{  0b00000,  0b10000,  0b10000,  0b10010,  0b10101,  0b10011,  0b01110,  0b00000};
byte d8[8]{  0b00000,  0b00010,  0b00100,  0b01000,  0b10000,  0b10000,  0b01110,  0b00000};
byte d9[9]{  0b00000,  0b01000,  0b10100,  0b11000,  0b01000,  0b00100,  0b00010,  0b00100};

//blank cells
byte b01[8]
{
   0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000  
}; 
 
byte *array[50] = {c0,b01,c1,c2,c3,
                  c4,c5,c6,b01,b01, 
                  c7,c8,c9,c10,c11,
                  c12,c13,c14,c15,c16,
                  c17,c18,c19,c20,c21,
                  c22,c23,c24,c25,c26,
                  c27,c28,c29,c30,c31,
                  c32,c33,c34,c35,c36,
                  c37,c38,c39,c40,c41,
                  c42,c43,c44,b01,c45
                   };
                  
byte *array2[8]={ dcp0,dcp1,
                  dcp0,dcp2,
                  dcp0,dcp3,
                  dcp0,dcp4};

byte *array3[10]={d0,d1,d2,d3,d4,d5,d6,d7,d8,d9};

 
//TODO simply this stuff  including led*[]
int lc1[]={1,0,0,0,0,0 }; int lc2[]={0,1,0,1,1,0 };int lc3[]={0,1,1,0,0,0 };int lc4[]={0,0,0,1,1,0 };int lc5[]={1,0,0,0,1,1 };
int lc6[]={1,0,1,1,0,1 }; int lc7[]={1,0,0,1,0,0 };int lc8[]={0,1,0,0,1,0 };int lc9[]={1,0,0,1,1,0 };int lc10[]={0,1,1,0,0,1 };
int lc11[]={1,0,0,0,1,0 };int lc12[]={0,1,0,0,0,1 };int lc13[]={1,1,1,1,0,0 };int lc14[]={1,0,1,0,0,1 };int lc15[]={0,1,0,0,1,1 };
int lc16[]={1,1,0,0,0,0 };int lc17[]={1,0,0,0,0,1 };int lc18[]={0,1,1,1,0,0 };int lc19[]={0,0,0,1,1,1 };int lc20[]={0,0,1,1,0,0 };
int lc21[]={0,1,1,1,1,1 };int lc22[]={0,1,1,1,0,1 };int lc23[]={1,1,1,0,0,1 };int lc24[]={1,1,1,1,1,1 };int lc25[]={0,1,0,1,1,1 };
int lc26[]={0,1,1,1,1,0 };int lc27[]={1,1,0,1,0,1 };int lc28[]={1,1,0,1,0,0 };int lc29[]={0,1,1,0,1,1 };int lc30[]={1,1,0,1,1,0 };
int lc31[]={1,1,1,0,1,0 };int lc32[]={0,0,1,1,1,0 };int lc33[]={1,0,1,0,0,0 };int lc34[]={0,1,0,1,0,0 };int lc35[]={1,1,0,0,1,0 };
int lc36[]={1,1,0,1,1,1 };int lc37[]={1,0,1,1,1,0 };int lc38[]={1,0,1,0,1,0 };int lc39[]={1,0,1,0,1,1 };int lc40[]={0,1,0,1,0,1 };
int lc41[]={1,1,0,0,0,1 };int lc42[]={1,1,1,0,1,1 };int lc43[]={0,1,1,0,1,0 };int lc44[]={1,0,1,1,0,0 };int lc45[]={1,1,1,1,1,0 };
int lc46[]={1,0,0,1,0,1 };int lc47[]={0,1,0,0,0,0 };int lc48[]={1,1,1,1,0,1 };int lc49[]={0,0,0,0,0,1 };int lc50[]={0,0,1,0,0,1 };
 
int *led[]={
          lc1,lc2,lc3,lc4,lc5,
          lc6,lc7,lc8,lc9,lc10,
          lc11,lc12,lc13,lc14,lc15,
          lc16,lc17,lc18,lc19,lc20,
          lc21,lc22,lc23,lc24,lc25,
          lc26,lc27,lc28,lc29,lc30,
          lc31,lc32,lc33,lc34,lc35,
          lc36,lc37,lc38,lc39,lc40,
          lc41,lc42,lc43,lc44,lc45,
          lc46,lc47,lc48,lc49,lc50
 
           };

// button i/p at anlog i/p
const int b1 = A7;
const int b2 = A6;
const int b3 = A5;
const int b4 = A4;                                                                                     
const int b5 = A3;
const int b6 = A2;
 


// variables will change:
static int buttonState = 0;         // variable for reading the pushbutton status
static int buttonState1 = 0;
static int buttonState2 = 0;
static int buttonState3 = 0; 
static int buttonState4 = 0;
static int buttonState5 = 0;

//control key that might change in time
static int auto_key=0;
static int eng_key=0;
static int signal_key=0;
static int freq_key=0;
static int aplha_key=0;

/*******************************************************************************************************/
void setdefualt()
{
    auto_key=0;
    eng_key=0;
    signal_key=0;
    freq_key=0;
    aplha_key=0;
}
void Check_Auto_Manual_status()                                                // Check_Auto_Manual_status
{  
    if(analogRead(A1) > 512) 
    { 
        auto_key = 1;
    }
    else 
    {
        auto_key =0 ; 
    }
 
}
void Check_Eng_hindi_status()                                                // Check_Auto_Manual_status
{ 
      
    if(analogRead(A0) > 512) 
    { 
        eng_key = 1;
    }
    else 
    {
        eng_key =0 ; 
    }
 
     
}
/*
void Check_signal_status()                                                // Check_Auto_Manual_status
{ 
     
    if(analogRead(A8) > 512) 
    { 
        signal_key = 1;
    }
    else 
    {
        signal_key =0 ; 
    }
 
      
}
void Check_freq_status()                                                // Check_Auto_Manual_status
{ 
     
    if(analogRead(A9) > 512) 
    { 
        freq_key = 1;
    }
    else 
    {
        freq_key =0 ; 
    }
 
    
}*/
void Check_alpha_num_status()                                                // Check_Auto_Manual_status
{ 
      
    if(analogRead(A10) > 512) 
    { 
        aplha_key = 1;
    }
    else 
    {
        aplha_key =0 ; 
    }
 
    
}
void numberControl()
{
    lcd.clear();
    lcd.print("Select language");
    delay(1000);
    lcd.clear();
    lcd.print("0 => Eng");
    lcd.setCursor(0,1);
    lcd.print("1 => Hindi");
    delay(3000);
        
    Check_Eng_hindi_status();
    Serial.write("eng_key :  ");Serial.println(eng_key);
    
    //
    //eng_key=1;
    //Serial.write("aplha_key :  ");Serial.println(aplha_key);
    //
    if(eng_key == 0)
    {   
        lcd.clear();
        lcd.print("ENGLISH NUM");
        Serial.println("english-num-auto");
        delay(2000);
        lcd.clear();
        number_all();
    }
    else
    {
        lcd.clear();
        lcd.print("MARATHI NUM ");
        Serial.println("marathi-num-auto");
         
        delay(2000);
        lcd.clear();
        number_hindi();
        //Vyanjan();
    }
}
void langControl()
{
    lcd.clear();
    lcd.print("Select language");
    delay(1000);
    lcd.clear();
    lcd.print("0 => Eng");
    lcd.setCursor(0,1);
    lcd.print("1 => Hindi");
    delay(3000);
        
    Check_Eng_hindi_status();
    Serial.write("eng_key :  ");Serial.println(eng_key);

    if(eng_key == 0)
    {   
        lcd.clear();
        lcd.print("ENGLISH ");
        Serial.println("english-auto");
        lcd.setCursor(0,1);
        lcd.print("ALPHABETS.....");
        delay(2000);
        lcd.clear();
        Char_all();
    }
    if(eng_key==1)
    {
        lcd.clear();
        lcd.print("MARATHI ");
        Serial.println("marathi-auto");
        lcd.setCursor(0,1);
        lcd.print("BARAKHADHI .....");
        delay(2000);
        lcd.clear();
        Vyanjan();
    }
        
}
void Char_all(void)                                                             //all characters
{ 
    lcd.clear();
    for(int x=0;x<26;x++)
    {
        lcd.print(charac[x]);
        Serial.println(charac[x]);
        
        delay(1000);
        lcd.clear();
        Check_Auto_Manual_status();
        Check_Eng_hindi_status();
        Check_alpha_num_status();
        if (auto_key == 1) break;
        if(eng_key==1)break;
        if(aplha_key==1)break;
    }
}
void number_all(void)
{
    lcd.clear();
    for(int x=26;x<36;x++)
    {
        lcd.print(charac[x]);
        Serial.println(charac[x]);
        
        delay(1000);
        lcd.clear();
        Check_Auto_Manual_status();
        Check_Eng_hindi_status();
        Check_alpha_num_status();
        if (auto_key == 1) break;
        if(eng_key==1)break;
        if(aplha_key==1) break;
         
    }
}
void number_hindi(void)
{
    lcd.clear();
    for(int x=0;x<10;x++)
    {
        lcd.createChar(1,array3[x]); 
        lcd.setCursor(0,0);
        lcd.write(1);
        Serial.println("printing.");
        
        delay(1000);
        lcd.clear();
        Check_Auto_Manual_status();
        Check_Eng_hindi_status();
        Check_alpha_num_status();
        if (auto_key == 1) break;
        if(eng_key==0)break;
        if(aplha_key==0) break;
         
    } 
}
void Vyanjan()
{
    lcd.clear();
    for(int row=0;row<50;row++)
   {
         
        if(row==1)
        {
            int db=0;
            lcd.createChar(1,array2[db]);
            lcd.createChar(2,array2[db+1]);
            lcd.setCursor(0,0);
            lcd.write(1);
            lcd.write(2);
            displayLEDMatrix(led[row]);
            delay(1000);    
        }
        else if(row==8)
        {
            int db=0;
            lcd.createChar(1,array2[db+2]);
            lcd.createChar(2,array2[db+3]);
            lcd.setCursor(0,0);
            lcd.write(1);
            //lcd.setCursor(1,0);
            lcd.write(2);
            delay(1000);    
        }
        else if(row==9)
        {
            int db=0;
            lcd.createChar(1,array2[db+4]);
            lcd.createChar(2,array2[db+5]);
            lcd.setCursor(0,0);
            lcd.write(1);
            //lcd.setCursor(1,0);
            lcd.write(2);
            delay(1000);    
        }
        else if(row==48)
        {
            int db=0;
            lcd.createChar(1,array2[db+6]);
            lcd.createChar(2,array2[db+7]);
            lcd.setCursor(0,0);
            lcd.write(1);
            //lcd.setCursor(1,0);
            lcd.write(2);
            delay(1000);    
        }
        else{
            lcd.createChar(1,array[row]); 
            lcd.setCursor(0,0);
            lcd.write(1);
            
        }
       //interrupt if user chnged to auto
        Check_Auto_Manual_status();
        Check_Eng_hindi_status();
         
         if(aplha_key==1) break;
        if (auto_key == 1) break;
        if(eng_key==0)  break ;
        
        delay(500);
        displayLEDMatrix(led[row]);
        delay(1000);
        
        lcd.clear();
    }
} 
void keypad_sense( )
{   
    // variable for existence of data in datav[]
    int exist=0;   //0 for no ... 1 for yes
    lcd.clear();
    lcd.print("key pressing");
    delay(2000);
    
    while(auto_key ==1)
    {
         
         //till her we have Auto_manual key pressed 

        //read what user has input through 6 button assembly
        buttonState = digitalRead(b1);
        buttonState1 = digitalRead(b2);
        buttonState2 = digitalRead(b3);
        buttonState3 = digitalRead(b4);
        buttonState4 = digitalRead(b5);
        buttonState5 = digitalRead(b6);

        Serial.println(buttonState);Serial.println(buttonState1);Serial.println(buttonState2);Serial.println(buttonState3);Serial.println(buttonState4);Serial.println(buttonState5);
        
        //cascade content it a particular value
        data=(buttonState)|(buttonState1<<1)|(buttonState2<<2)|(buttonState3<<3)|(buttonState4<<4)|(buttonState5<<5);
        
        Serial.write("data :  ");Serial.println(data);

        //till here we have the data waht user want ?    
        delay(1000);
        lcd.clear();

        //user decided to quit manual and shift to auto_key
        //check for Check_Auto_Manual_status
         
         
         Check_Auto_Manual_status();
        Check_Eng_hindi_status();

        Serial.write("auto-key :  ");Serial.println(auto_key);
        Serial.write("eng-key :  ");Serial.println(eng_key);
         
        if(auto_key ==0 )
          { break;}
 
        //check the language of the input 
        if(eng_key==0 )    //english
        {
            // ckeck firsthand whether we have data of it or not
            //time for display it 
            for(int x=0;x<26;x++)
            {   
                // here the binary-format changes implicity to int and then 
                //comapre to data
                if (charv[x]==data)
                { 
                    //success finding character
                    exist =1 ;   //yes we have the character
                    Serial.println("we have the english character");
                    lcd.print(charac[x]);
                    Serial.println(charac[x]);
                }
                //not found at this index .... go for next index   
            }
            //not found at--- all   ..  i.e exist 0(no)
            if(exist==0)
            {
                Serial.println("Invalid Input!!");
                lcd.print("Invalid Char");
            }
            if(exist==1)
            {
                
                //set back to default for next char detection....
                exist=0;
            }
        }
        else if(eng_key==1)   //hindi
        {
            // ckeck firsthand whether we have data of it or not
            //time for display it 
            for(int x=0;x<50;x++)
            {   
                // here the binary-format changes implicity to int and then 
                //comapre to data
                if (charhv[x]==data)
                { 
                    //success finding character
                    exist =1 ;   //yes we have the character
                    Serial.println("we have the hindi character");
                    generate_print(x);
                     
                }
                //not found at this index .... go for next index   
            }
            //not found at--- all   ..  i.e exist 0(no)
            if(exist==0)
            {
                Serial.println("Invalid Input!!");
                lcd.print("Invalid Char");
            }
            if(exist==1)
            {
                
                //set back to default for next char detection....
                exist=0;
            }
        }
        //user decided to quit manual and shift to auto_key
        //check for Check_Auto_Manual_status
         Check_Auto_Manual_status();
        if(auto_key ==0)
           loop();
   
          
    }     
}
void generate_print(int row)
{
    lcd.clear();
    if(row==1)
    {
        int db=0;
        lcd.createChar(1,array2[db]);
        lcd.createChar(2,array2[db+1]);
        lcd.setCursor(0,0);
        lcd.write(1);
        lcd.write(2);
        displayLEDMatrix(led[row]);
        delay(1000);    
    }
    else if(row==8)
    {
        int db=0;
        lcd.createChar(1,array2[db+2]);
        lcd.createChar(2,array2[db+3]);
        lcd.setCursor(0,0);
        lcd.write(1);
        lcd.write(2);
        delay(1000);    
    }
    else if(row==9)
    {
        int db=0;
        lcd.createChar(1,array2[db+4]);
        lcd.createChar(2,array2[db+5]);
        lcd.setCursor(0,0);
        lcd.write(1);
        lcd.write(2);
        delay(1000);    
    }
    else if(row==48)
    {
        int db=0;
        lcd.createChar(1,array2[db+6]);
        lcd.createChar(2,array2[db+7]);
        lcd.setCursor(0,0);
        lcd.write(1);
        lcd.write(2);
        delay(1000);    
    }
    else{
        lcd.createChar(1,array[row]); 
        lcd.setCursor(0,0);
        lcd.write(1);
        
    }

    delay(500);
    displayLEDMatrix(led[row]);
    delay(1000);
    lcd.clear();
}
void  displayLEDMatrix(int arr[])
{
   digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH); 
    delay(500);
   
    
      if(arr[0]==1)
          digitalWrite(7, LOW);  
     if(arr[1]==1)
          digitalWrite(6, LOW); 
     if(arr[2]==1)
          digitalWrite(5, LOW); 
     if(arr[3]==1)
          digitalWrite(4, LOW); 
     if(arr[4]==1)
          digitalWrite(3, LOW); 
   if(arr[5]==1)
          digitalWrite(2, LOW); 
       
    delay(1000);
   
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);     
                 
}

/********************************************************************************************************/
void setup() {
    // TODO: initialize the LED pin as an output:
    //TODO: add display_led_matrix function my code
    // initialize the pushbutton pin as an input:
    pinMode(b1, INPUT); 
    pinMode(b2, INPUT); 
    pinMode(b3, INPUT); 
    pinMode(b4, INPUT); 
    pinMode(b5, INPUT); 
    pinMode(b6, INPUT); 

    
    lcd.begin(16, 2);
    Serial.begin(9600);
    Serial.println("Testing Started");
    delay(500);
    lcd.print("Select Auto:Training");
    lcd.setCursor(0,1);
    lcd.print("Select Key:pressing");
    delay(1000);
}
void loop() 
{
     
    Serial.println("Select Auto:Training");
    Serial.println("Select Key:pressing");
    delay(500);
    lcd.clear();
    do{
    // menu  button
    setdefualt();

    
    Serial.write("auto-key :  ");Serial.println(auto_key);
    Serial.write("eng_key :  ");Serial.println(eng_key);
    Serial.write("freq_key :  ");Serial.println(freq_key);
    Serial.write("signal_key :  ");Serial.println(signal_key);
    Serial.write("aplha_key :  ");Serial.println(aplha_key);
    
    Check_Auto_Manual_status();       //for auto/manual
    Check_Eng_hindi_status();
    //Check_signal_status();    //TODO          //sine/square/tri
    //Check_freq_status();        //TODO          //freq 
     
     

    Serial.write("auto-key :  ");Serial.println(auto_key);
    Serial.write("eng_key :  ");Serial.println(eng_key);
    //Serial.write("freq_key :  ");Serial.println(freq_key);
    //Serial.write("signal_key :  ");Serial.println(signal_key);
     

    if (auto_key == 0)
    {
        lcd.print("Auto Mode");
        delay(1000);
        lcd.clear();
        Serial.println("Alphabets or numbers ?");
        lcd.print("0 => Alphabets");
        lcd.setCursor(0,1);
        lcd.print("1 => Numbers");
        delay(3000);
        
        Check_alpha_num_status();
        //Serial.write("aplha_key :  ");Serial.println(aplha_key);
        //aplha_key=1;
        Serial.write("aplha_key :  ");Serial.println(aplha_key);
        
        if(aplha_key==0)
            langControl();
        else
            numberControl(); 

    }
    else if(auto_key ==1)
    { 
        Serial.println("keymode");

        lcd.setCursor(0,1);
        delay(1000);
        lcd.clear();
        lcd.print("Select language");
        delay(1000);
        lcd.clear();
        lcd.print("0 => Eng");
        lcd.setCursor(0,1);
        lcd.print("1 => Hindi");
        delay(3000);
        Check_Eng_hindi_status();
        Serial.write("eng_key :  ");Serial.println(eng_key);
        lcd.clear();
         
        keypad_sense( );
    }

   }while(1);

}




