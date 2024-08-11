/*
* This example code is used for LaskaKit microESP32-C3 !!! v3 !!! board https://www.laskakit.cz/laskakit-microesp/
* with our Temperature and Humidity SHT40 module https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/
* MicroESP32-C3 v3 board reads temperature and humidity from SHT40 sensor 
* and sends every second through native USB (USB CDC) 
* 
* SDA - GPIO8
* SCL - GPIO10
*
* I2C power - GPIO2
*
* Made by (c) laskakit.cz 2024
*
* Libraries: https://github.com/Sensirion/arduino-i2c-sht4x
* ESP32 library 3.0.x
* Condition: Tools -> USB CDC On Boot must be enabled
* Board: ESP32-C3 Dev Module
* 
*/

#include <Arduino.h>
#include <SensirionI2CSht4x.h>
#include <Wire.h>

SensirionI2CSht4x sht4x;

#define SDA 8
#define SCL 10

void setup() {

    HWCDCSerial.begin(115200);
    while (!HWCDCSerial) {
        delay(100);
    }

    Wire.begin(SDA,SCL);

    uint16_t error;
    char errorMessage[256];

    sht4x.begin(Wire);

    uint32_t serialNumber;
    error = sht4x.serialNumber(serialNumber);
    if (error) {
        HWCDCSerial.print("Error trying to execute serialNumber(): ");
        errorToString(error, errorMessage, 256);
        HWCDCSerial.println(errorMessage);
    } else {
        HWCDCSerial.print("Serial Number: ");
        HWCDCSerial.println(serialNumber);
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
        HWCDCSerial.print("Error trying to execute measureHighPrecision(): ");
        errorToString(error, errorMessage, 256);
        HWCDCSerial.println(errorMessage);
    } else {
        HWCDCSerial.print("Temperature:");
        HWCDCSerial.print(temperature);
        HWCDCSerial.print("\t");
        HWCDCSerial.print("Humidity:");
        HWCDCSerial.println(humidity);
    }
}
