#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 3, 2, 1, 0);
static int mode_key=0;
static int lang_key=0;
static int alphanum_key=0;                   
static int delay_key=0;  

/*******************************************************************************************************/
 
void Check_Mode_status()                                                 
{  
    if(digitalRead(25) ==1)  
    { 
        mode_key = 1;             //   manual
    }
    else 
    {
        mode_key =0 ;               //  Auto
    }
 
} 
void Check_Lang_status()                                               
{  
    if(digitalRead(22) ==1)  
    { 
        lang_key = 1;
    }
    else 
    {
        lang_key =0 ; 
    }
 
} void Check_Alphanum_status()                                                 
{  
    if(digitalRead(23) ==1)  
    { 
        alphanum_key = 1;
    }
    else 
    {
        alphanum_key =0 ; 
    }
 
} 
  void Check_Delay_status()                                                 
{  Serial.println(digitalRead(24));
    if(digitalRead(24) ==1)  
    { 
        delay_key = 0;
    }
    else 
    {
        delay_key =1; 
    }
 
} 
  
 
 
/********************************************************************************************************/
void setup() {
 

    pinMode(22,INPUT);
    pinMode(23,INPUT);
    pinMode(24,INPUT);
    pinMode(25,INPUT);
     
    Serial.begin(9600);
    lcd.begin(16, 2);
    Serial.println("Testing Started");
    delay(500);
    lcd.print("Select Mode:1. Auto");
    lcd.setCursor(0,1);
    lcd.print("2. Key-pressing");
    delay(1000);
     
}
void loop() 
{
    
    do{
 

    
    Serial.write("auto-key :  "); Serial.println(mode_key);
     delay(1000);
    
    Check_Mode_status();       //for auto/manual
    Check_Lang_status();
    Check_Alphanum_status(); 
    Check_Delay_status() ;    
  
     
 Serial.write("lang-key :  "); Serial.println(lang_key);
 delay(1000);
 Serial.write("alphanum-key :  "); Serial.println(alphanum_key);
     delay(1000); 
Serial.write("dealy-key :  "); Serial.println(delay_key);
     delay(1000);
   }while(1);

}




