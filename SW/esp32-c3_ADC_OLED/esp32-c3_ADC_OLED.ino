/*
* This example code is used for LaskaKit microESP board 
*
* MicroESP board reads voltage on Battery and Solar panel 
* and sends every 2 seconds through UART and OLED display
* 
*
* Made by (c) laskakit.cz 2022
* 
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32AnalogRead.h> 

ESP32AnalogRead adcB;
#define ADCBpin 0
#define bDeviderRatio 1.7693877551  // Voltage devider ratio on ADC pin 1MOhm + 1.3MOhm

ESP32AnalogRead adcS;
#define ADCSpin 1
#define sDeviderRatio 3.15           // Voltage devider ratio on ADC pin 1M + 330kOhm

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C // 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, 4);

void setup() {
    
  Serial.begin(115200);
  delay(100); // let serial console settle
  
  // setting ADC
  adcB.attach(ADCBpin);
  adcS.attach(ADCSpin);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
     for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();

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

  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.println("Battery" + String(bat_voltage, 3));
  display.println("Solar" + String(solar_voltage, 3));
  
  display.display();

  
  delay(2000);
}
