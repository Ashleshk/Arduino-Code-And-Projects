void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMOde(13,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 
 if(digitalRead(13))
 {
 Serial.println("hi");
 while(digitalRead(13));
 }
 }
