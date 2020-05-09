// Arduino stepper motor control code

#include <Stepper.h>       // Include the header file
// change this to the number of steps on your motor
#define STEPS 32                            // create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);

int val = 0;                                

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(200);
}

void loop() {

  if (Serial.available()>0)
  {
    val = Serial.parseInt();               //for full rotation (32 steps) --> val=32*64=2048 (Enter on serial monitor)
    stepper.step(val);
    Serial.println(val); //for debugging
  }
 

}
