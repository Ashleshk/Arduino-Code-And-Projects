/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************

 
 **************************************************************/
#include<math.h>
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <SimpleTimer.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <Wire.h>
#include <dht.h>
dht DHT;
#define DHT11_PIN 6
/////////////////////////////////////////

/////////////////////////////////////////
 int Pm25 = 0;
 int Pm10 = 0;
/////////////////////////////////////////
//#define LEDPIN 8
unsigned char SEC1_flag; 
unsigned char led_cnt;
unsigned char x;

float Rl=20.0;
float approx=2373.315;
int GasSensorPin=2; //ATmega328P - 12
float Rs,Vout,count,ratio,GasConc;
int ppm;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "117a820688214b22b7baf59f8d63c492";

WidgetLCD lcd(V3);
WidgetLED led1(V1);
WidgetLED led2(V2);
WidgetLED led4(V4);
SimpleTimer timer;
WidgetRTC rtc;
BLYNK_ATTACH_WIDGET(rtc, V5);

void setup()
{
  
  Serial.begin(9600);
//  pinMode(LEDPIN, OUTPUT);
    SEC1_flag = 0;
    led_cnt = 0;
    // initialize Timer1
    cli();          // disable global interrupts
    TCCR1A = 0;     // set entire TCCR1A register to 0
    TCCR1B = 0;     // same for TCCR1B
 
    // set compare match register to desired timer count:
    OCR1A = 15624;
    // turn on CTC mode:
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler:
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);
    // enable timer compare interrupt:
    TIMSK1 |= (1 << OCIE1A);
    // enable global interrupts:
    sei();
  Blynk.begin(auth);

  while (Blynk.connect() == false) {
    // Wait until connected
  }
  rtc.begin();
  timer.setInterval(10000L, clockDisplay);
  lcd.clear(); //Use it to clear the LCD Widget
  
}

void clockDisplay()
{
  // You can call hour(), minute(), ... at any time
  // Please see Time library examples for details
  BLYNK_LOG("Current time: %02d:%02d:%02d %02d %02d %d",
            hour(), minute(), second(),
            day(), month(), year());
}

ISR(TIMER1_COMPA_vect)
{
    //digitalWrite(LEDPIN, !digitalRead(LEDPIN));
    x++;
    if(x==2)
    {
    SEC1_flag =1;
    x=0;
    }
}

void ProcessSerialData()
{
  uint8_t mData = 0;
  uint8_t i = 0;
  uint8_t mPkt[10] = {0};
  uint8_t mCheck = 0;
 while (Serial.available() > 0) 
  {  
    // from www.inovafitness.com
    // packet format: AA C0 PM25_Low PM25_High PM10_Low PM10_High 0 0 CRC AB
     mData = Serial.read();     delay(2);//wait until packet is received
    if(mData == 0xAA)//head1 ok
     {
        mPkt[0] =  mData;
        mData = Serial.read();
        if(mData == 0xc0)//head2 ok
        {
          mPkt[1] =  mData;
          mCheck = 0;
          for(i=0;i < 6;i++)//data recv and crc calc
          {
             mPkt[i+2] = Serial.read();
             delay(2);
             mCheck += mPkt[i+2];
          }
          mPkt[8] = Serial.read();
          delay(1);
	  mPkt[9] = Serial.read();
          if(mCheck == mPkt[8])//crc ok
          {
            Serial.flush();
            //Serial.write(mPkt,10);

            Pm25 = (uint16_t)mPkt[2] | (uint16_t)(mPkt[3]<<8);
            Pm10 = (uint16_t)mPkt[4] | (uint16_t)(mPkt[5]<<8);
            if(Pm25 > 999)//if(Pm25 > 9999)
             Pm25 = 999;
            if(Pm10 > 999)//if(Pm10 > 9999)
             Pm10 = 999;            
            //get one good packet
             return;
          }
        }      
     }
   } 
}



void loop()
{
  Blynk.run();
  timer.run();
  ProcessSerialData();
 
  int chk = DHT.read11(DHT11_PIN);
   
  //Serial.print(DHT.humidity, 1);
  //Serial.print(",\t");
  //Serial.println(DHT.temperature, 1);
    
  //ppm calibration
  count=analogRead(GasSensorPin);
  Vout=(count*4.88)/1000.0;
  Rs=((5.0*Rl)-(Rl*Vout))/Vout;
  ratio=Rs/approx;
  GasConc=146.15*(2.868-ratio)+10;
  ppm=GasConc;
  
  
  if(SEC1_flag == 1)
  {
  SEC1_flag = 0;
  led_cnt++;
  switch(led_cnt)
      {
	
	case 1:
	{
	//digitalWrite(LEDPIN, LOW);// use: (position X: 0-15, position Y: 0-1, "Message you want to print")
        lcd.clear();
        lcd.print(0, 0, "Pollution Meter"); 
        lcd.print(0, 1, "EFY DASH Board.");
        //led1.off();
        //led_cnt = 0;
	break;
	}
        case 2:
        {
        lcd.clear();
        lcd.print(0, 0, "Temp=");
        lcd.print(5,0,DHT.temperature);
        lcd.print(14,0,"C");
        lcd.print(0, 1, "RH=");
        lcd.print(3,1,DHT.humidity);
        if(DHT.temperature>40)
        {led2.on();}
        else
        {led2.off();}
        break;
        }
        case 3:
        {
        lcd.clear();
        lcd.print(0, 0, "PPM=");
        lcd.print(5, 0, ppm);
        break;
        }
        case 4:
        {
        lcd.clear();
        lcd.print(0, 0, "PM2.5="); 
        lcd.print(6,0,Pm25);
        lcd.print(0, 1, "PM10=");
        lcd.print(6, 1,Pm10);
        if(Pm25>350)
        {led1.on();}
        else
        {led1.off();}
        break;
        }
        case 5:
        {
        lcd.clear();
        lcd.print(0, 0, "TIME="); 
        lcd.print(5,0,hour());
        lcd.print(7,0,":");
        lcd.print(8,0,minute());
        lcd.print(10,0,":");
        lcd.print(11,0,second());
        lcd.print(0, 1, "DATE=");
        lcd.print(5,1,day());
        lcd.print(7,1,"/");
        lcd.print(8,1,month());
        lcd.print(10,1,"/");
        lcd.print(11,1,year());
        led_cnt = 0;
        break;
        }
  
      }
  
  }    

}

