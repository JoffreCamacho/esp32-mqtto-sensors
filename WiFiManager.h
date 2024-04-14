// WiFiManager.h
#ifndef WiFiManager_h
#define WiFiManager_h
#include "config.h"
#include <WiFi.h>

class WiFiManager {
public:
    static void connect(const char* ssid, const char* password) {
        Serial.begin(115200);
        Serial.println("Booting");
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password);

        int retries = 0;
        while (WiFi.waitForConnectResult() != WL_CONNECTED && retries < MAX_RETRIES) {
            Serial.println("Connection Failed! Retrying...");
            delay(5000);
            WiFi.begin(ssid, password);
            retries++;
        }
        if (retries >= MAX_RETRIES) {
            Serial.println("Failed to connect to WiFi. Check configuration.");
            ESP.restart(); // Handle error (e.g., enter deep sleep, blink an LED, etc.)
        }

        Serial.println("Connected to WiFi");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
};

#endif
