// In config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <driver/adc.h>
#include <esp_adc_cal.h>

#define DEFAULT_VREF    1100        // Default Vref in mV (use 1100 unless you've measured a different value)
#define NO_OF_SAMPLES   64          // Multisampling

esp_adc_cal_characteristics_t *adc_chars;

// Wifi AUTH
const char* ssid = "YOURSSID";
const char* password = "YOURPASSWORD";
const char* mqttServer = "YOURMQTTO_IP";
const int mqttPort = YOURMQTOPORT;

// Using const instead
const int ECHO_PIN = 18;
const int TRIGGER_PIN = 23;

// Similarly, for other constants
// Can not be used with wifi [25,26,27,14,12,13,4,2,15]
// Only input pins [34-39]
// Available ADC1 pins [36,39,34,35,32,33]

const int CO2_TX_PIN = 1;  // TX pin for MH-Z19B
const int CO2_RX_PIN = 3;  // RX pin for MH-Z19B
const int ONE_WIRE_BUS1 = 16; 
const int ONE_WIRE_BUS2 = 17;
const int RELAY_PIN = 19;
const int RELAY2_PIN = 22;
const int TURBIDITY_SENSOR_PIN = 32;          //ADC1_CHANNEL_4
const int RELAY3_PIN = 33;                    //ADC1_CHANNEL_5
const int LIGHT_SENSOR_PIN = 34; //input only //ADC1_CHANNEL_6
const int TDS_SENSOR_PIN = 35; //input only   //ADC1_CHANNEL_7
const int CO2_SENSOR_PIN = 36; //input only   //ADC1_CHANNEL_0
const int PH_SENSOR_PIN = 39; //input only    //ADC1_CHANNEL_3
const float SEALEVELPRESSURE_HPA = 1010.01;
const int MAX_SENSOR_VALUE = 4095;
const int MAX_RETRIES = 5;

// For constants representing distances
const float MAX_DISTANCE = 109.22;
const float MIN_TANK_DISTANCE = 70.0;

#endif
