// In config.h
#ifndef CONFIG_H
#define CONFIG_H

// Wifi AUTH
const char* ssid = "NETGEAR92";
const char* password = "YOURSSID";
const char* mqttServer = "YOURMQTTO_IP";
const int mqttPort = YOURMQTOPORT;

// Using const instead
const int ECHO_PIN = 18;
const int TRIGGER_PIN = 23;

// Similarly, for other constants
const int RELAY2_PIN = 25;
const int ONE_WIRE_BUS1 = 26;
const int ONE_WIRE_BUS2 = 14;
const int RELAY_PIN = 27;
const int TURBIDITY_SENSOR_PIN = 13;
const int RELAY3_PIN = 33;
const int LIGHT_SENSOR_PIN = 12;
const int TDS_SENSOR_PIN = 35;
const int CO2_SENSOR_PIN = 36;
const int PH_SENSOR_PIN = 39;
const float SEALEVELPRESSURE_HPA = 1010.01;
const int MAX_SENSOR_VALUE = 4095;
const int MAX_RETRIES = 5;

// For constants representing distances
const float MAX_DISTANCE = 109.22;
const float MIN_TANK_DISTANCE = 70.0;

#endif
