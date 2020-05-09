void setup() {
  // put your setup code here, to run once:
 pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<256;i++)
  {
     analogWrite(6,i);
     delay(100);
      
  }
}
