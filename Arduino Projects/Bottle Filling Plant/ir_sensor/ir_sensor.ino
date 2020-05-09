const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  12;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);     
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);    

  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  Serial.println("TSOP IR Sensor Testing" );
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {    
    // turn LED off:   
    digitalWrite(ledPin, LOW); 
  }
  else {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.println(" sensor Active " );
  }
}
