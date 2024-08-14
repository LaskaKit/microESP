/*
* This example code is used for LaskaKit microESP32-C3 board https://www.laskakit.cz/laskakit-microesp/
* with our Temperature and Humidity SHT40 module https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/
* MicroESP32-C3 board reads temperature and humidity from SHT40 sensor 
* and sends every second through native USB
* 
* SDA - GPIO8
* SCL - GPIO10
*
* !!! ESP library version !!!
* ESP32 library 3.0.x
* Condition: Tools -> if USB CDC On Boot is ENABLED then
* Serial means native USB
* Tools -> if USB CDC On Boot is DISABLED then
* Serial means UART
* ---
* ESP32 library 2.0.xy
* Condition: Tools -> USB CDC On Boot must be disabled
* use USBSerial to send data through native USB 
*
* Board: ESP32-C3 Dev Module
*
* Libraries: https://github.com/Sensirion/arduino-i2c-sht4x
* 
*/

#include <Arduino.h>
#include <SensirionI2CSht4x.h>
#include <Wire.h>

SensirionI2CSht4x sht4x;

#define SDA 8
#define SCL 10

void setup() {

    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }

    Wire.begin(SDA,SCL);

    uint16_t error;
    char errorMessage[256];

    sht4x.begin(Wire);

    uint32_t serialNumber;
    error = sht4x.serialNumber(serialNumber);
    if (error) {
        Serial.print("Error trying to execute serialNumber(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("Serial Number: ");
        Serial.println(serialNumber);
    }
}

void loop() {
    uint16_t error;
    char errorMessage[256];

    delay(1000);

    float temperature;
    float humidity;
    error = sht4x.measureHighPrecision(temperature, humidity);
    if (error) {
        Serial.print("Error trying to execute measureHighPrecision(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("Temperature:");
        Serial.print(temperature);
        Serial.print("\t");
        Serial.print("Humidity:");
        Serial.println(humidity);
    }
}
