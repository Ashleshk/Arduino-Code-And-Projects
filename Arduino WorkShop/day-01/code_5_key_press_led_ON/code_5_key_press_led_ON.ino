char inp,choice;
int r=5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  do
  {
  inp=Serial.read();
  if(inp=='a')
  {
      Serial.write(" you turn ON \'LED\'");
      digitalWrite(13,HIGH);
      
    Serial.println(r);
    Serial.write(r);
    }
    if(inp=='z')
  {
      Serial.write(" you turn OFF \'LED\'");
      digitalWrite(13,LOW);
      
    Serial.println();
    }
     
}while(1);
}

