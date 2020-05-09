void setup() // Put your setup or configuration code in the setup function, it will only run once during the startup.
{
  pinMode (13,OUTPUT); // Initialize digital pin 7 as an output.
  pinMode (7,INPUT); // Initialize digital pin 2 as an input.
}

void loop() //Put your main code in void loop() function to run repeatedly.
{
  //int i=digitalRead(7); // Reads the digital pin 2 of Arduino
  if (digitalRead(7)==HIGH)             // Checks for motion detection.
  {
    digitalWrite(13, HIGH); // If motion detected, turns ON the LED which is connected to digital pin 7.
  }
  else                    
  {
    digitalWrite (13                                                          , LOW); // If motion not detected then turns OFF the LED which is connected to digital pin 7.
  }
}
