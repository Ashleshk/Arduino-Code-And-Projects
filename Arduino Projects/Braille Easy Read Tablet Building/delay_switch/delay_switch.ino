int state =LOW;
int lastState = LOW;
static int count=0,Pause=2000;
void SetDelay()
{
  if (state==LOW && lastState==HIGH)
  {
  count++;
  
  }
  lastState=state;
  state=digitalRead(24);


  //setting delay();
  if(count<=3)
  {
    if(count==1)
      Pause=4000;  //slow
    else if(count==2)
      Pause=1000; //medium
    else if(count==3)
      Pause=500;
    else
      Pause=2000;   
     
  }
   
  count=0;  
}

void setup(){
  Serial.begin(9600);
  pinMode(24, INPUT);
  state=digitalRead(24);
}
void loop(){
  SetDelay();
  Serial.print(count);
  Serial.println(Pause);
}
