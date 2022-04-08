#include <Wire.h>
#include <driver/adc.h>


void setup() {
  // put your setup code here, to run once:
  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11);
  adc1_config_channel_atten(ADC1_CHANNEL_1, ADC_ATTEN_DB_11);
  
  Serial.begin(115200);
  delay(100); // let serial console settle

}

void loop() {

  int BAT_ADC = adc1_get_raw((adc1_channel_t)0);
  Serial.print("Battery ADC VALUE = ");
  Serial.println(BAT_ADC);
  float bat_voltage = (BAT_ADC * 3.17 ) / (4095);
  Serial.print("Voltage = ");
  Serial.print(bat_voltage * 3.3);
  Serial.println("V");

  Serial.println("");

  int SOLAR_ADC = adc1_get_raw((adc1_channel_t)1);
  Serial.print("Solar ADC VALUE = ");
  Serial.println(SOLAR_ADC);
  float solar_voltage = (SOLAR_ADC * 3.17 ) / (4095);
  Serial.print("Voltage = ");
  Serial.print(solar_voltage * 10);
  Serial.println("V");
  Serial.println("");
  delay(1000);
}
