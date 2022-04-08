/*
* This example code is used for LaskaKit microESP board 
* with our Temperature and Humidity SHT40 module
* MicroESP board reads temperature and humidity from SHT40 sensor 
* and sends every second through UART
* 
*       microESP-12   microESP32-C3
* SDA - GPIO4         GPIO19
* SCL - GPIO5         GPIO18
*
* Made by (c) laskakit.cz 2021
*
* Libraries: https://github.com/Sensirion/arduino-i2c-sht4x
* 
*/

#include <Arduino.h>
#include <SensirionI2CSht4x.h>
#include <Wire.h>

SensirionI2CSht4x sht4x;

#define SDA 19
#define SCL 18

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
