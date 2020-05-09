int LED=9;
int SWITCH=8;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(SWITCH,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   char c =digitalRead(SWITCH);
   if(Serial.available())
   {  
    if(c==0)
    {
      digitalWrite(LED,HIGH);
      Serial.write("ASHLESH KHAJBAGE");
    }
   else
   {
    digitalWrite(LED,LOW); 
    Serial.write("2508");
   }
   }
 
  
}  
