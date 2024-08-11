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
* Condition: Tools -> USB CDC On Boot must be enabled
* use HWCDCSerial instead of USBSerial
* ---
* ESP32 library 2.0.xy
* Condition: Tools -> USB CDC On Boot must be disabled
* use USBSerial instead of HWCDCSerial
*
* Board: ESP32-C3 Dev Module
*
* Made by (c) laskakit.cz 2024
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

    USBSerial.begin(115200);
    while (!USBSerial) {
        delay(100);
    }

    Wire.begin(SDA,SCL);

    uint16_t error;
    char errorMessage[256];

    sht4x.begin(Wire);

    uint32_t serialNumber;
    error = sht4x.serialNumber(serialNumber);
    if (error) {
        USBSerial.print("Error trying to execute serialNumber(): ");
        errorToString(error, errorMessage, 256);
        USBSerial.println(errorMessage);
    } else {
        USBSerial.print("Serial Number: ");
        USBSerial.println(serialNumber);
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
        USBSerial.print("Error trying to execute measureHighPrecision(): ");
        errorToString(error, errorMessage, 256);
        USBSerial.println(errorMessage);
    } else {
        USBSerial.print("Temperature:");
        USBSerial.print(temperature);
        USBSerial.print("\t");
        USBSerial.print("Humidity:");
        USBSerial.println(humidity);
    }
}
