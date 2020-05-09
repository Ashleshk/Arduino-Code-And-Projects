void setup() {
  // put your setup code here, to run once:
   pinMode(6,OUTPUT);
   pinMode(5,INPUT);
   Serial.begin(9600);
    
}

void loop() {
  // put your main code here, to run repeatedly:
   int potvalue= analogRead(5);
   int led_out = map(potvalue,0,1023,0,255);
  Serial.print ("pot value:");
   Serial.println( potvalue);delay(1000);
    Serial.print ("led value:");
   Serial.print( led_out);delay(1000);
   analogWrite(6,led_out);
    
}
