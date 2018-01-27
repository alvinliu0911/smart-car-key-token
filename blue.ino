#include <SoftwareSerial.h>
SoftwareSerial Genotronex(10, 11);

const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino
int PulseSensorPurplePin = A1;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13;   //  The on-board Arduion LED

int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 700;  
int limit;
int value;
int heartcheck,alchocheck;
int ledpin=13; // led on D13 will show blink on / off
void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  
  pinMode(ledpin,OUTPUT);

pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin); 
   if(Signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
     heartcheck==1;
   } else {
     heartcheck==0; 
     Serial.print("heartbit checked");//  Else, the sigal must be below "550", so "turn-off" this LED.
   }
value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin

Serial.print("Alcohol value: ");
Serial.println(value);//prints the alcohol value
//prints the limit reached as either LOW or HIGH (above or underneath)
delay(100);
if (value>700){
alchocheck=1;//if limit has been reached, LED turns on as status indicator
}
else{
alchocheck=0;//if threshold not reached, LED remains off
}

   
    if ((heartcheck == 0)&&(alchocheck == 0)){ Genotronex.println("ok");Genotronex.println("alchocol");Genotronex.print(value);Genotronex.println("heart");delay(1000);
    if (Signal-500<=60){Genotronex.print(0);}
    else{
    Genotronex.print(Signal-515);delay(1000);}}
    else if ((heartcheck == 1)||(alchocheck==1)) {Genotronex.println("no");Genotronex.println("alchocol");Genotronex.print(value);Genotronex.println("heart");
    if (Signal-500<=60){Genotronex.print(0);delay(1000);}
    else{
    Genotronex.print(Signal-515);delay(1000);}}
 
  
}
