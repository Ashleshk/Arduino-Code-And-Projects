 
int val = 0;     // variable for reading the pin status
int ledpin=0;
void setup() {
  pinMode(13, OUTPUT);  // declare LED as output
  pinMode(A0,INPUT);
  pinMode(12, OUTPUT);  // declare LED as output
 pinMode(A1,INPUT);
  pinMode(11, OUTPUT);  // declare LED as output
 pinMode(A2,INPUT);
  pinMode(10, OUTPUT);  // declare LED as output
   pinMode(A3,INPUT);
  pinMode(9, OUTPUT);  // declare LED as output
  pinMode(A4,INPUT);
  pinMode(8, OUTPUT);  // declare LED as output
  pinMode(A5,INPUT);
}

void loop(){
   
  
  for(int i=0;i<=5;i++){
     
     int vl=vl+i;
    val=analogRead(vl);
    ledpin=13-i;
    if (val >= 4) {         // check if the input is HIGH (button released)
    digitalWrite(ledpin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledpin, HIGH);  // turn LED ON
  }
  }
  
 
}
