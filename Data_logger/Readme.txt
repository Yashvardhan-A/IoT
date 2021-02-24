## General info

	DATA LOGGER USING NODEMCU ESP8266

 This code is written to read data using the LDR(Light Dependent Resistor) on ESP8266 and save the readings in its flash memory. There is a provision of button given to print the data in serial output saved in the flash memory.

## Technology used

* NodeMCU ESP8266 development Board 

* Arduino IDE

* Library EEPROM.H is included (In ESP8266 the EEPOM library is used to write to Flash memory.)

* Components - Breadboard, jumper wires, LDR, NodeMCU ESP8266, button, resistors

## Setup

To run this project, setup the ldr and switch using resistorn on a bread board along the NodeMCU ESP 8266 for the pins mentioned in the source code. Copy the code in Arduino IDE compile the code and upload it to the target.(Make sure to have the NodeMCU ESP8266 board selected.)