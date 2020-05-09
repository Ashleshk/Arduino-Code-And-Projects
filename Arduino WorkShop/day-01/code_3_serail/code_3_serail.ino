void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);/*  to begin communication of the serail with aurdino*/
   pinMode(13,OUTPUT);
 int statusLED=0;
}

void loop() {
  // put your main code here, to run repeatedly:
static int   statusLED=0;
    digitalWrite(13,HIGH);
    Serial.println("LED IS ON"); /*  to print communication to the serail from aurdino*/
    delay(1000);
    digitalWrite(13,LOW);
    Serial.println("LED IS OFF");
    delay(1000);
      statusLED++;
 if(statusLED==10)
  {
   Serial.end(); /*  to end communication of the serail with aurdino*/
  }    
    
}
