static int val=0;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
   val = analogRead(A1);
 
   Serial.println(analogRead(A1));
   delay(1000);
}
