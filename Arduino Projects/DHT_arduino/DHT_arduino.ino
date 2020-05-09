#include<dht.h>                      // DHT11 humidity sensor library
dht DHT;                             //Creating sensor object
#define DHT11_PIN 2                  // Sensor is connected to Arduino pin 2
void setup()
{
  Serial.begin(9600); //setting baud rate
  Serial.println(" Temperarue and Humidity Detector (DHT 11)");
  Serial.println("");
}
void loop()                             //method used to run the code repeatedly
{
  int chk = DHT.read11(DHT11_PIN);      //Reading data from sensor
  Serial.print(" Humidity = ");         //prints on the serial monitor
  Serial.print(DHT.humidity);           // prints obtained humidity on serial port
  Serial.print(" g/m^3");
  Serial.print(" \tTemperature = "); //prints on the serial monitor
  Serial.print(DHT.temperature, 1);    //prints obtained temperature on serial port  ||1-> one digit after decimal point
  Serial.println(" degrees");
  
  delay(2000);//adding the delay of 2 seconds
  }
