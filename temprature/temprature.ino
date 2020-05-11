#include<dht.h>
dht DHT;
#define dht11_pin 5
int 
led1 = 10, //Connect LED 1 To Pin #13 
led2 = 9, //Connect LED 2 To Pin #12 
led3 = 8; //Connect LED 2 To Pin #11
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(4,OUTPUT);
    pinMode(led3,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led1,OUTPUT);

    //IR
    pinMode(7,INPUT);
    pinMode(11,OUTPUT);
}
void allon(){
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     delay(1000); 
     }
     
void alloff(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW); 
     delay(1000);
     
}
void loop() {
  // put your main code here, to run repeatedly:
  double x,y;
   int z;
  Serial.println("Relay ON.....");
  digitalWrite(4,LOW);
  delay(1000);
  
  for(int i=0;i<6;i++)
  {
    if(i==0) {allon();} 
  else if(i==1){alloff();}  
  else if(i==2) { digitalWrite(led3,HIGH);delay(1000);digitalWrite(led3,LOW);}
  else if(i==3) {digitalWrite(led2,HIGH);delay(1000);digitalWrite(led2,LOW);}
  else  if(i==4){z=digitalRead(7);
                Serial.print("IR OUTPUT:");Serial.println(z);delay(1000);
                if(z==1){digitalWrite(11,LOW);
                          delay(1000);
                          Serial.println("No OBStcle Detected.....LED OFF");}
                else{digitalWrite(11,HIGH);delay(1000);
                Serial.println("OBstacle Ahead....\nLED ON");}
  }
  else{
    delay(1000);
      digitalWrite(led1,HIGH);
      Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
      Serial.flush();
      Serial.print("DHT11, \t");
      int chk = DHT.read11(dht11_pin);
      switch (chk)
      {
        case DHTLIB_OK:  
        Serial.print("OK,\t"); 
        break;
        case DHTLIB_ERROR_CHECKSUM: 
        Serial.print("Checksum error,\t"); 
        break;
        case DHTLIB_ERROR_TIMEOUT: 
        Serial.print("Time out error,\t"); 
        break;
         }
         // DISPLAY DATA
      Serial.print(DHT.humidity, 1);
      Serial.print(",\t");
      Serial.println(DHT.temperature, 1);
      
    }
  }
  

  delay(5000);
   
  Serial.flush();
  Serial.println("Relay OFF......");
  Serial.println(".................Restarting.........................");
  Serial.println("\n\n\n");
  digitalWrite(4,HIGH);
  delay(1000);
 
}
