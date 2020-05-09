const int IR_Sensor=2;

void setup() {

// initialize the digital pin as an output.

// Pin 13 has an LED  on  Arduino boards:

pinMode(13, OUTPUT);

//Pin 2 is connected to the output of IR_Sensor

pinMode(IR_Sensor,INPUT);

}

void loop() {

if(digitalRead(IR_Sensor)==HIGH)      //Check the sensor output

{

digitalWrite(13, LOW);   // set the LED on

}

else

{

digitalWrite(13, HIGH);    // set the LED off

}

delay(1000);              // wait for a second

}
