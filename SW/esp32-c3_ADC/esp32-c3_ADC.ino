/*
* This example code is used for LaskaKit microESP32-C3 board  https://www.laskakit.cz/laskakit-microesp/
*
* microESP32-C3 board reads voltage of Battery  
* and sends every 2 seconds through native USB of microESP32-C3
*
* Made by (c) laskakit.cz 2024
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
*/

#include <SPI.h>
#include <Wire.h>
#include <ESP32AnalogRead.h>    // https://github.com/madhephaestus/ESP32AnalogRead

ESP32AnalogRead adcB;
#define ADCBpin 0
#define bDeviderRatio 1.7693877551  // Voltage devider ratio on ADC pin 1MOhm + 1.3MOhm

void setup() {
    
  USBSerial.begin(115200);
  delay(100); // let serial console settle
  
  // setting ADC
  adcB.attach(ADCBpin);
}

void loop() {

  float bat_voltage = adcB.readVoltage() * bDeviderRatio;
  USBSerial.print("Battery Voltage = " );
  USBSerial.print(bat_voltage);
  USBSerial.println("V");

  delay(2000);
}
