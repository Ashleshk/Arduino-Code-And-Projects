 
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6, 7, 5, 4, 3, 2); 
int b1,b2,b3,b4,b5,b6,data=0;

//data and datav
const char charac[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
const int charv[]={0b000001,0b000101,0b000011,0b001011,0b001001,0b000111,0b001111,0b001101,0b000110,0b001110,0b010001,0b010101,0b010011,0b011011,0b011001,0b010111,0b011111,0b011101,0b010110,0b011110,0b110001,0b110101,0b101110,0b110011,0b111011,0b111001};
const int charhv[]={0b000001,0b011010,0b000110,0b011000,0b110001,0b101101,0b001001,0b010010,0b011001,0b100110,0b010001,0b100010,0b001111,0b100101,0b110010,0b000011,0b100001,0b001110,0b111000,0b001100,0b111110,0b101110,0b100111,0b111111,0b111010,0b011110,0b101011,0b001011,0b110110,0b011011,0b010111,0b011100,0b000101,0b001010,0b010011,0b111011,0b011101,0b010101,0b110101,0b101010,0b100011,0b110111,0b010110,0b001101,0b011111,0b101001,0b000010,0b101111,0b100000,0b100100};
static int lang_key=1;

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


void keypad_Sense()
{
  int exist=0;   // user entered data exist in our arrays
  lcd.clear();
  delay(110);
  lcd.print("key-pressing");
  lcd.setCursor(0,1);
  delay(500);

  //we have manual button enabled till here
    b1=digitalRead(27);
    b2=digitalRead(26);
    b3=digitalRead(29);
    b4=digitalRead(28);
    b5=digitalRead(31);
    b6=digitalRead(30);
    
    delay(1000);
//    Serial.println();
//    Serial.write("b1 :  ");Serial.println(b1);
//    Serial.write("b2 :  ");Serial.println(b2);
//    Serial.write("b3 :  ");Serial.println(b3);
//    Serial.write("b4 :  ");Serial.println(b4);
//    Serial.write("b5 :  ");Serial.println(b5);
//    Serial.write("b6:  ");Serial.println(b6);

    //cascade content it a particular value
    data=(b1)|(b2<<1)|(b3<<2)|(b4<<3)|(b5<<4)|(b6<<5);

   // Serial.write("data :  ");Serial.println(data);

    //till here we have the data what user want ?    
    delay(1000);

    //check the language of the input 
        if(lang_key==0 )    //english
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
                    //Serial.println("we have the english character");
                    lcd.print(charac[x]);
                    //Serial.println(charac[x]);
                }
                //not found at this index .... go for next index   
            }
            //not found at--- all   ..  i.e exist 0(no)
            if(exist==0)
            {
                //Serial.println("Invalid Input!!");
                lcd.print("Invalid Char");
            }
            if(exist==1)
            {
                
                //set back to default for next char detection....
                exist=0;
            }
        }
        else if(lang_key==1)   //hindi
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
                    //Serial.println("we have the hindi character");
                    //Serial.println("index: ");Serial.print(x);
                    generate_print(x);  
                }
                //not found at this index .... go for next index   
            }
            //not found at--- all   ..  i.e exist 0(no)
            if(exist==0)
            {
                //Serial.println("Invalid Input!!");
                lcd.print("Aanuchit Akshar");
            }
            if(exist==1)
            { 
                //set back to default for next char detection....
                exist=0;
            }
        }
  
} 
void generate_print(int row)
{
    
    if(row==1)
    {
        int db=0;
        lcd.createChar(1,array2[db]);
        lcd.createChar(2,array2[db+1]);
        lcd.setCursor(0,1);
        lcd.write(1);
        lcd.write(2);
        
        delay(1000);    
    }
    else if(row==8)
    {
        int db=0;
        lcd.createChar(1,array2[db+2]);
        lcd.createChar(2,array2[db+3]);
        lcd.setCursor(0,1);
        lcd.write(1);
        lcd.write(2);
        delay(1000);    
    }
    else if(row==9)
    {
        int db=0;
        lcd.createChar(1,array2[db+4]);
        lcd.createChar(2,array2[db+5]);
        lcd.setCursor(0,1);
        lcd.write(1);
        lcd.write(2);
        delay(1000);    
    }
    else if(row==48)
    {
        int db=0;
        lcd.createChar(1,array2[db+6]);
        lcd.createChar(2,array2[db+7]);
        lcd.setCursor(0,1);
        lcd.write(1);
        lcd.write(2);
        delay(1000);    
    }
    else{
        lcd.createChar(1,array[row]); 
        lcd.setCursor(0,1);
        lcd.write(1);
        
    }

    delay(500);
    
}
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Select Auto:Training");
lcd.setCursor(0,1);
 lcd.print("Select Key:pressing");
 delay(1000);
}

void loop() {
do{
       
  lcd.print("key-pressing");
  lcd.setCursor(0,1);
      keypad_Sense();
      delay(1000);
    }while(1);
}

