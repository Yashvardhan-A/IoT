#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include "coap_client.h"

//instance for coapclient
coapClient coap;

//WiFi connection info
const char* ssid = "home";
const char* password = "kasturi@1234";
String DEVICE_SECRET_KEY  = "5683";

//ip address and default port of coap server in which your interested in
IPAddress ip(192, 168, 2, 6);
int port = 5683;
char* path = "events";

StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

// coap client response callback
void callback_response(coapPacket &packet, IPAddress ip, int port) {
  char p[packet.payloadlen + 1];
  memcpy(p, packet.payload, packet.payloadlen);
  p[packet.payloadlen] = NULL;

  //response from coap server
  if (packet.type == 3 && packet.code == 0) {
    Serial.println("ping ok");
  }

  Serial.println(p);
}

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.println(" ");

  // Connection info to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    yield();
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address of client
  Serial.println(WiFi.localIP());

  // client response callback.
  // this endpoint is single callback.
  coap.response(callback_response);

  // start coap client
  coap.start();
}

void loop() {
  root["name"] = "temperature";
  root["data"] =  21.5;
  root["accessToken"] =  DEVICE_SECRET_KEY;

  String data;
  root.printTo(data);
  char dataChar[data.length() + 1];
  data.toCharArray(dataChar, data.length() + 1);
  bool state;


  //post request
  //arguments server ip address,default port,resource name, payload,payloadlength
  int msgid = coap.post(ip, port, path, dataChar, data.length());

  state = coap.loop();

  delay(5000);
}
