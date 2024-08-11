/*
* This example code is used for LaskaKit microESP32-C3 v3.x board 
*
* MicroESP32-C3 v3.x board reads voltage on Battery  
* and sends every 2 seconds through native USB (USB CDC) and OLED display
* 
* Made by (c) laskakit.cz 2024
* 
* ESP32 library 3.0.x (for ESP32 library 2.0.xy use USBSerial instead of HWCDCSerial and may disable USB CDC On Boot)
* Condition: Tools -> USB CDC On Boot must be enabled
* Board: ESP32-C3 Dev Module
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <ESP32AnalogRead.h> // https://github.com/madhephaestus/ESP32AnalogRead

#define SDA 8
#define SCL 10
ESP32AnalogRead adcB;
#define ADCBpin 0
#define bDeviderRatio 1.7693877551  // Voltage devider ratio on ADC pin 1MOhm + 1.3MOhm
#define SCREEN_ADDRESS 0x3C // or 0x3D
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1); //Nastavit display

void setup() {

  HWCDCSerial.begin(115200);
  Wire.begin(SDA,SCL);  
  
  // setting ADC
  adcB.attach(ADCBpin);
  
  display.begin(SCREEN_ADDRESS, true); 
  display.clearDisplay(); 
  display.setTextColor(SH110X_WHITE); 
  display.setTextSize(1); 

}

void loop() {

  float bat_voltage = adcB.readVoltage() * bDeviderRatio;
  HWCDCSerial.print("Battery Voltage = " );
  HWCDCSerial.print(bat_voltage);
  HWCDCSerial.println("V");

  display.clearDisplay();

  display.setTextSize(1.8);      // Normal 1:1 pixel scale
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.println("Battery: " + String(bat_voltage, 3));
  
  display.display();
  
  delay(2000);
}
