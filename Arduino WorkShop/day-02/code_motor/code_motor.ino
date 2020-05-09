void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   /*for(int i=0;i<256;i++)
   {
      analogWrite(10,i);
   }*/

   digitalWrite(9,HIGH);
   digitalWrite(8,LOW);

   delay(3000);
  
   
   digitalWrite(9,LOW);
   digitalWrite(8,HIGH);
   delay(3000);
}
