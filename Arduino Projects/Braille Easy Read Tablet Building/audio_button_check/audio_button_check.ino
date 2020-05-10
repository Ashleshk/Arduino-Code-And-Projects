int  i; 
int arr[] ={A12,A13,A14,A15};
void setup() {
 pinMode(A12,OUTPUT);  //pin 9
 pinMode(A13,OUTPUT);//pin 13
 pinMode(A14,OUTPUT);//pin 14
 pinMode(A15,OUTPUT);//pin15
 

}

void loop() {

 
    
         
   analogWrite(A12,0);
   analogWrite(A13,255);
   analogWrite(A14,255);
   analogWrite(A15,255);
   
// analogWrite(A12,255);
//   analogWrite(A13,0);
//   analogWrite(A14,255);
//   analogWrite(A15,255);
//   delay(5000);

//   analogWrite(A12,255);
//   analogWrite(A13,255);
//   analogWrite(A15,0);
//   analogWrite(A14,255);
//   delay(5000);
//   analogWrite(A12,255);
//   analogWrite(A13,255);
//   analogWrite(A14,255);
//   analogWrite(A15,0);
//   delay(5000);
   
}
