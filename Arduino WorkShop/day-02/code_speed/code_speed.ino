void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   for(int i=0;i<256;i++)
   {
      analogWrite(10,i);
   }
   digitalWrite(9,HIGH);
   digitalWrite(8,LOW);
   int a= analogRead(A0);
    int out=map(a,0,1023,0,255);
    analogWrite(10,out);
   delay(3000);
  
   
   
}
