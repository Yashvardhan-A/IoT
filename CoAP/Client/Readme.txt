## General info

	CoAP client on NodeMCU ESP8266

## Technology used

* NodeMCU ESP8266 development Board 

* Arduino IDE

* Library ESP8266WiFi.h is included (Install the library in the IDE)

* Library ArduinoJson.h is included (Install the library in the IDE)

* Library coap_client.h is included (Install the library in the IDE, available on internet)

* Components - NodeMCU ESP8266

## Setup

To run this project, the server and the client need to be on the same network, change the wifi details in the source code to your network details. set the device secret key to the one set for the server. change the ip address to you netwrok's ip address(type ipconfig in CMD). Compile the code and uload it to the target. It should start communication with the server. (Make sure NodeMCU ESP8266 board is selected in Arduino IDE)