const int c1 =  A0; 
const int c2 =  A1;
const int c3=  A5;
const int c4 =  A4;
const int c5 =  A3;
const int c6 =  A2;

const int ledPin1 =  A6; 
const int ledPin2 =  A7;
const int ledPin3 =  A11;
const int ledPin4 =  A10;
const int ledPin5 =  A9;
const int ledPin6 =  A8;

const char charac[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0'};
 const int charv[]={0b000001,0b000101,0b000011,0b001011,0b001001,
                    0b000111,0b001111,0b001101,0b000110,0b001110,
                    0b010001,0b010101,0b010011,0b011011,0b011001,
                    0b010111,0b011111,0b011101,0b010110,0b011110,
                    0b110001,0b110101,0b101110,0b110011,0b111011,0b111001,
                    0b000001,0b000101,0b000011,0b001011,0b001001,
                    0b000111,0b001111,0b001101,0b000110,0b001110,};
  

//hindi_braille
const int charhv[]={0b000001,0b011010,0b000110,0b011000,0b110001,0b101101,0b001001,0b010010,0b011001,0b100110,0b101000,0b100000, 
                    0b010001,0b100010,0b001111,0b100101,0b110010,0b000011,0b100001,0b001110,0b111000,0b001100,
                    0b111110,0b101110,0b100111,0b111111,0b111010,0b011110,0b101011,0b001011,0b110110,0b011011,
                    0b010111,0b011100,0b000101,0b001010,0b010011,0b111011,0b011101,0b010101,0b110101,0b101010,
                    0b100011,0b110111,0b010110,0b001101,0b011111,0b101001 };

const char eng_no[]={0b111010,0b101000,0b100000};
 void Char_or_no(const int charx) //all characters
{
   
    
    digitalWrite(c1, !(charx&1));
    digitalWrite(c4, !(charx&2));
    digitalWrite(c2, !(charx&4));
    digitalWrite(c5, !(charx&8));
    digitalWrite(c3, !(charx&16));
    digitalWrite(c6, !(charx&32));
    delay(1000);
    setDefualt();
    delay(500);
  
}
void Char_sol(const int charx) //all characters
{
   
    
    digitalWrite(ledPin1, !(charx&1));
    digitalWrite(ledPin4, !(charx&2));
    digitalWrite(ledPin2, !(charx&4));
    digitalWrite(ledPin5, !(charx&8));
    digitalWrite(ledPin3, !(charx&16));
    digitalWrite(ledPin6, !(charx&32));
    delay(1000);
    setDefualt();
    delay(500);
  
}
void hindi_sol(const int charhd) 
{
   
    
    digitalWrite(ledPin1, !(charhd&1));
    digitalWrite(ledPin4, !(charhd&2));
    digitalWrite(ledPin2, !(charhd&4));
    digitalWrite(ledPin5, !(charhd&8));
    digitalWrite(ledPin3, !(charhd&16));
    digitalWrite(ledPin6, !(charhd&32));
    delay(1000);
    setDefualt();
    delay(500);
   
}
void  solonoidTest( )
{
   digitalWrite(ledPin1, 0);
 delay(500);
 digitalWrite(ledPin1, 1);
 delay(500);
  digitalWrite(ledPin2, 0);
 delay(500);
 digitalWrite(ledPin2, 1);
 delay(500);
 digitalWrite(ledPin3, 0);
 delay(500);
 digitalWrite(ledPin3, 1);
 delay(500);
 digitalWrite(ledPin4, 0);
 delay(500);
 digitalWrite(ledPin4, 1);
 delay(500);
 digitalWrite(ledPin5, 0);
 delay(500);
 digitalWrite(ledPin5, 1);
 delay(500);
 digitalWrite(ledPin6, 0);
 delay(500);
 digitalWrite(ledPin6, 1);
 delay(500);
 
 delay(500);                      
}
void  Char_No_Test( )
{
   digitalWrite(c1, 0);
 delay(500);
 digitalWrite(c1, 1);
 delay(500);
  digitalWrite(c2, 0);
 delay(500);
 digitalWrite(c2, 1);
 delay(500);
 digitalWrite(c3, 0);
 delay(500);
 digitalWrite(c3, 1);
 delay(500);
 digitalWrite(c4, 0);
 delay(500);
 digitalWrite(c4, 1);
 delay(500);
 digitalWrite(c5, 0);
 delay(500);
 digitalWrite(c5, 1);
 delay(500);
 digitalWrite(c6, 0);
 delay(500);
 digitalWrite(c6, 1);
 delay(500);
 
 delay(500);                      
}
void setDefualt()
{
  digitalWrite(ledPin1, 1);
  digitalWrite(ledPin2, 1);  
  digitalWrite(ledPin3, 1);
  digitalWrite(ledPin4, 1);
  digitalWrite(ledPin5, 1);
  digitalWrite(ledPin6, 1); 
  
  digitalWrite(c1, 1);
  digitalWrite(c2, 1);  
  digitalWrite(c3, 1);
  digitalWrite(c4, 1);
  digitalWrite(c5, 1);
  digitalWrite(c6, 1); 
   delay(2000);
 
}
void setup() {
   pinMode(ledPin1, OUTPUT); 
    pinMode(ledPin2, OUTPUT); 
    pinMode(ledPin3, OUTPUT);  
    pinMode(ledPin4, OUTPUT);  
    pinMode(ledPin5, OUTPUT); 
    pinMode(ledPin6, OUTPUT); 

    pinMode(c1, OUTPUT); 
    pinMode(c2, OUTPUT); 
    pinMode(c3, OUTPUT);  
    pinMode(c4, OUTPUT);  
    pinMode(c5, OUTPUT); 
    pinMode(c6, OUTPUT);
 
}
 
void loop() {
 // setDefualt();
 solonoidTest();
 Char_No_Test();
}
