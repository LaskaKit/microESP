/*
* This example code is used for LaskaKit microESP board 
*
* MicroESP board reads voltage on Battery and Solar panel 
* and sends every 2 seconds through UART
*
* Made by (c) laskakit.cz 2022
* 
*/

#include <SPI.h>
#include <Wire.h>
#include <ESP32AnalogRead.h>    // https://github.com/madhephaestus/ESP32AnalogRead

ESP32AnalogRead adcB;
#define ADCBpin 0
#define bDeviderRatio 1.7693877551  // Voltage devider ratio on ADC pin 1MOhm + 1.3MOhm

ESP32AnalogRead adcS;
#define ADCSpin 1
#define sDeviderRatio 3.15           // Voltage devider ratio on ADC pin 1M + 330kOhm

void setup() {
    
  Serial.begin(115200);
  delay(100); // let serial console settle
  
  // setting ADC
  adcB.attach(ADCBpin);
  adcS.attach(ADCSpin);
}

void loop() {

  float bat_voltage = adcB.readVoltage() * bDeviderRatio;
  Serial.print("Battery Voltage = " );
  Serial.print(bat_voltage);
  Serial.println("V");

  float solar_voltage = adcS.readVoltage() * sDeviderRatio;
  Serial.print("Solar Voltage = " );
  Serial.print(solar_voltage);
  Serial.println("V");

  delay(2000);
}
