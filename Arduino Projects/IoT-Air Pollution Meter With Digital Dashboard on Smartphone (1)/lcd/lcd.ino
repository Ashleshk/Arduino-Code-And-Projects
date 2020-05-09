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
 * Output any data on LCD widget!
 *
 * App project setup:
 *   LCD widget, switch to ADVANCED mode, select pin V1
 *
 **************************************************************/
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
 
#define LEDPIN 8
unsigned char SEC1_flag; 
unsigned char led_cnt;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "117a820688214b22b7baf59f8d63c492";

WidgetLCD lcd(V3);
SimpleTimer timer;
WidgetRTC rtc;
BLYNK_ATTACH_WIDGET(rtc, V5);

void setup()
{
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
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
  //lcd.print(0, 0, "Hello"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  //lcd.print(0, 1, "World");
  //delay(100);
  // Please use timed events when LCD printintg in void loop to avoid sending too many commands
  // It will cause a FLOOD Error, and connection will be dropped
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
    SEC1_flag =1;
}

void loop()
{
  Blynk.run();
  timer.run();
  //timer.setInterval(10000L, clockDisplay);
  
  
  
  
  if(SEC1_flag == 1)
  {
  SEC1_flag = 0;
  led_cnt++;
  switch(led_cnt)
      {
	
	case 1:
	{
	//digitalWrite(LEDPIN, LOW);
        lcd.clear();
        lcd.print(0, 0, "Pollution Meter"); 
        lcd.print(0, 1, "EFY DASH Board.");
        
        //led_cnt = 0;
	break;
	}
        case 2:
        {
        lcd.clear();
        lcd.print(0, 0, "Light="); 
        lcd.print(0, 1, "Dew Pt=");
        break;
        }
        case 3:
        {
        lcd.clear();
        lcd.print(0, 0, "Temp="); 
        lcd.print(0, 1, "RH=");
        break;
        }
        case 4:
        {
        lcd.clear();
        lcd.print(0, 0, "PM2.5="); 
        lcd.print(0, 1, "PM10=");
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

