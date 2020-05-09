int static var =0;
long static vaa= 0;

void setup() {
  // put your setup code here, to run once:
pinMode(12,INPUT);
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  var =digitalRead(12);
  Serial.println(var);
  Serial.println();
  vaa=analogRead(A0);
  //Serial.println(vaa);
}
