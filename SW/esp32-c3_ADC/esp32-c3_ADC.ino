/*
* This example code is used for LaskaKit microESP32-C3 v2.x board  https://www.laskakit.cz/laskakit-microesp/
*
* microESP32-C3 v2.x board reads voltage on Battery  
* and sends every 2 seconds through UART
* microESP32-C3 v2.x, For microESP32-C3 v3.x use (native) USBSerial instead of Serial.
*
* Made by (c) laskakit.cz 2023
* 
*/

#include <SPI.h>
#include <Wire.h>
#include <ESP32AnalogRead.h>    // https://github.com/madhephaestus/ESP32AnalogRead

ESP32AnalogRead adcB;
#define ADCBpin 0
#define bDeviderRatio 1.7693877551  // Voltage devider ratio on ADC pin 1MOhm + 1.3MOhm

void setup() {
    
  Serial.begin(115200);
  delay(100); // let serial console settle
  
  // setting ADC
  adcB.attach(ADCBpin);
}

void loop() {

  float bat_voltage = adcB.readVoltage() * bDeviderRatio;
  Serial.print("Battery Voltage = " );
  Serial.print(bat_voltage);
  Serial.println("V");

  delay(2000);
}
