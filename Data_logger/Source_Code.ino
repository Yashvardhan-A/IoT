#include <EEPROM.h>
 
#define TIME_DELAY 2000  //The time between each EEPROM write function call in ms
 
int vPin = A0;      // pin for analog input
int printPin = 2;     //the print button pin
 
int address = 0;      //EEPROM address counter
 
unsigned long timer;
 
float multi = 0.0;   //defining variable for conversion from 0-1024 to 0-5 range
 

// Defining functions

// Function to print stored value from EEPROM
void printVal()
{
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    byte value = EEPROM.read(i);                //read EEPROM data at address i
    if(value != 0)                              //skip "empty" addresses
    {
      float x = value*multi;            //convert ADC values to 0-5V
 
      Serial.println(x);
    }
  }
}
 

// Function to write value to EEPROM
void writeVal()
{
  byte value = analogRead(vPin);     //read sensor value
   
  EEPROM.write(address, value);         //write value to current address counter address
 
  Serial.print("Sensor value stored at address ");
  Serial.println(address);
   
  address++;                      //increment address counter
  if(address == EEPROM.length())  //check if address counter has reached the end of EEPROM
  {
    address = 0;              //reset address counter if true
  }
}
 
void setup(){
  Serial.begin(9600);     //start the serial connection
  multi = 5.0/1023.0;  //find value to do the conversion
  timer = millis();         //millis() returns the time since program start in ms
}
 
void loop(){
  if(millis()-timer > TIME_DELAY)  //time check if new value needs to be read
  {
    writeVal();
    timer = millis();
  }
 
  if(!digitalRead(printPin))  //check if print button is pressed
  {
    printVal();
    delay(500);
  }
 
   
  delay(1);
}
 
