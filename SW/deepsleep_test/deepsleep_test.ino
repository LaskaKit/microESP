// Must be disabled USB CDC On Boot

#define SLEEP_SEC 15         // Measurement interval (seconds)

void setup(void)
{
  USBSerial.begin(115200);

  goToSleep();
}

void loop(void) 
{

}

void goToSleep(){

  USBSerial.println("I'm mot sleeping");
  delay(3000);
  USBSerial.println("going to sleep 15 sek");
  // ESP Deep Sleep 
  USBSerial.println("ESP in sleep mode");
  USBSerial.flush(); 
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  esp_deep_sleep_start();
}
