/*
  *  Example code for deep sleep test with microESP32-C3 v3.x
  *  Code shows how to go to deep sleep mode.
  *  https://www.laskakit.cz/laskakit-microesp/
  *  laskakit.cz (2024)
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
*/

#define SLEEP_SEC 15         // Measurement interval (seconds)

void setup(void)
{
  Serial.begin(115200);

  goToSleep();
}

void loop(void) 
{

}

void goToSleep(){

  Serial.println("I'm mot sleeping");
  delay(3000);
  Serial.println("going to sleep 15 sek");
  // ESP Deep Sleep 
  Serial.println("ESP in sleep mode");
  Serial.flush(); 
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  esp_deep_sleep_start();
}
