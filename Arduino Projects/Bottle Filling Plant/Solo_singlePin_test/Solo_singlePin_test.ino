void setup() {
  // put your setup code here, to run once:
  pinMode(A0,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(A0,HIGH);
   delay(2000);
   digitalWrite(A0,INPUT);
   delay(2000);
}
