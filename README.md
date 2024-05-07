# esp32-mqtto-sensors
project to connect multiple sensors over the esp32 wifi network and MQTTO server


- OTA updates can be sent via Wi-Fi.
- Update your credentials in the config.h file for Wifi and MQTTO server connection.
- Wifi reconnects automatically if the connection fails. 
- esp32 ADC2 pins cannot be used in this dev.
- the MAX_DISTANCE represents the position of the ultrasonic sensor inside the water tank at the desired level to be measured when empty.
- the SEALEVELPRESSURE_HPA has to be calibrated according to your geolocation.
- the voltage is calibrated to the specific esp32 by readADC_Calibrated();


# Please be advised that this is an ongoing project, and the code is constantly changing, so take the code with a grain of salt.
Any feedback, please send it over to hogar.digital2@gmail.com (joffre)
