void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);   // initialize digital pin13 as an output

}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(13,HIGH);    //set pin13 as high
   delay(1000);                    // keep it high
   digitalWrite(13,LOW);        //set pin 13 as low 
   delay(30);
   digitalWrite(13,HIGH);    //set pin13 as high
   delay(30);                    // keep it high
   digitalWrite(13,LOW);        //set pin 13 as low 
   delay(30);
   digitalWrite(13,HIGH);    //set pin13 as high
   delay(30);                    // keep it high
   digitalWrite(13,LOW);        //set pin 13 as low 
   delay(30);
}
