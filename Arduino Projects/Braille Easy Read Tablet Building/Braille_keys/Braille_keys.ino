void setup() {
  // put your setup code here, to run once:
pinMode(26,INPUT);
pinMode(27,INPUT);
pinMode(28,INPUT);
pinMode(29,INPUT);
pinMode(30,INPUT);
pinMode(31,INPUT);
Serial.begin(9600);
Serial.println("Testing Started");
}

void loop() {
    int b1,b2,b3,b4,b5,b6;
    Serial.println("Select Auto:Training");
    Serial.println("Select Key:pressing");
    delay(500);
//    lcd.clear();
    do{
        b1=digitalRead(27);
        b2=digitalRead(26);
        b3=digitalRead(29);
        b4=digitalRead(28);
        b5=digitalRead(31);
        b6=digitalRead(30);
      delay(2000);
      Serial.write("b1 :  ");Serial.println(b1);
      Serial.write("b2 :  ");Serial.println(b2);
      Serial.write("b3 :  ");Serial.println(b3);
      Serial.write("b4 :  ");Serial.println(b4);
      Serial.write("b5 :  ");Serial.println(b5);
      Serial.write("b6:  ");Serial.println(b6);
      Serial.write("fd df kdhkf hdska ");
      delay(2000);
    }while(1);
    
}
