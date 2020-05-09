#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 3, 2, 14, 15); 
int b1,b2,b3,b4,b5,b6,data=0;

//data and datav
const char charac[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
const int charv[]={0b000001,0b000101,0b000011,0b001011,0b001001,0b000111,0b001111,0b001101,0b000110,0b001110,0b010001,0b010101,0b010011,0b011011,0b011001,0b010111,0b011111,0b011101,0b010110,0b011110,0b110001,0b110101,0b101110,0b110011,0b111011,0b111001};
const int charhv[]={0b000001,0b011010,0b000110,0b011000,0b110001,0b101101,0b001001,0b010010,0b011001,0b100110,0b010001,0b100010,0b001111,0b100101,0b110010,0b000011,0b100001,0b001110,0b111000,0b001100,0b111110,0b101110,0b100111,0b111111,0b111010,0b011110,0b101011,0b001011,0b110110,0b011011,0b010111,0b011100,0b000101,0b001010,0b010011,0b111011,0b011101,0b010101,0b110101,0b101010,0b100011,0b110111,0b010110,0b001101,0b011111,0b101001,0b000010,0b101111,0b100000,0b100100};
static int lang_key=0;
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
    
     
    Serial.write("b1 :  ");Serial.println(b1);
    Serial.write("b2 :  ");Serial.println(b2);
    Serial.write("b3 :  ");Serial.println(b3);
    Serial.write("b4 :  ");Serial.println(b4);
    Serial.write("b5 :  ");Serial.println(b5);
    Serial.write("b6:  ");Serial.println(b6);

    //cascade content it a particular value
    data=(b1)|(b2<<1)|(b3<<2)|(b4<<3)|(b5<<4)|(b6<<5);

    Serial.write("data :  ");Serial.println(data);

    //till here we have the data what user want ?    
    delay(1000);
    lcd.clear();

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
                    Serial.println("we have the hindi character");
                    Serial.println("index: ");Serial.print(x);  
                }
                //not found at this index .... go for next index   
            }
            //not found at--- all   ..  i.e exist 0(no)
            if(exist==0)
            {
                Serial.println("Invalid Input!!");
                lcd.print("Aanuchit Akshar");
            }
            if(exist==1)
            { 
                //set back to default for next char detection....
                exist=0;
            }
        }
  
} 
void setup() {

pinMode(26,INPUT);
pinMode(27,INPUT);
pinMode(28,INPUT);
pinMode(29,INPUT);
pinMode(30,INPUT);
pinMode(31,INPUT);

lcd.begin(16,2);
lcd.clear(); 
lcd.print("Select Auto:Training");
lcd.setCursor(0,1);
 lcd.print("Select Key:pressing");
 delay(1000);

Serial.begin(9600);
Serial.println("Testing Started");
lcd.clear();
}

void loop() {
     
    Serial.println("Select Auto:Training");
    Serial.println("Select Key:pressing");
    delay(500);

    do{
       
  lcd.print("key-pressing");
  lcd.setCursor(0,1);
      keypad_Sense();
      delay(1000);
    }while(1);
    
}
