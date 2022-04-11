# esp32-mqtto-sensors
test project to connect multiple sensors over esp32 wifi network

/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_SSI";
const char* password = "YOUR_PASSWORD";
const char* mqttServer = "192.168.1.99";
const int mqttPort = 1883;
WiFiClient espClient;
PubSubClient client(espClient);
// Sensor de luz GPIO 34 (Analog ADC1_CH6) 
const int LuzPin = 34;
int LuzValue = 0;
long lastMsg = 0;
char msg[50];
int value = 0;

void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Connected to AP successfully!");
}
void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Disconnected from WiFi access point");
  Serial.print("WiFi lost connection. Reason: ");
  Serial.println(info.disconnected.reason);
  Serial.println("Trying to Reconnect");
  WiFi.begin(ssid, password);
}



void setup(){
  Serial.begin(115200);
  // delete old config
  WiFi.disconnect(true);
  delay(1000);
  WiFi.onEvent(WiFiStationConnected, SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WiFiGotIP, SYSTEM_EVENT_STA_GOT_IP);
  WiFi.onEvent(WiFiStationDisconnected, SYSTEM_EVENT_STA_DISCONNECTED);
  /* Remove WiFi event
  Serial.print("WiFi Event ID: ");
  Serial.println(eventID);
  WiFi.removeEvent(eventID);*/
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.println();
  Serial.println("Wait for WiFi... ");
  client.setServer(mqttServer, mqttPort); 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT..."); 
    if (client.connect("ESP32Client")) { 
      Serial.println("connected"); 
    } else { 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000); 
    }
  }
  client.publish("esp/test", "Hello from ESP32");
}

void loop(){
  // Reading potentiometer value
  LuzValue = analogRead(LuzPin);
  Serial.println(LuzValue);
  delay(100);
}
