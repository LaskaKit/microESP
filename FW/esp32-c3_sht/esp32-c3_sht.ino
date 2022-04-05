#include <Wire.h>
#include <driver/adc.h>

#include "SHTSensor.h"

SHTSensor sht;
// To use a specific sensor instead of probing the bus use this command:
// SHTSensor sht(SHTSensor::SHT3X);

void setup() {
  // put your setup code here, to run once:
  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11);
  adc1_config_channel_atten(ADC1_CHANNEL_1, ADC_ATTEN_DB_11);
  
  Wire.begin(19, 18);
  Serial.begin(115200);
  delay(1000); // let serial console settle

  if (sht.init()) {
      Serial.print("init(): success\n");
  } else {
      Serial.print("init(): failed\n");
  }
  sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM); // only supported by SHT3x

}

void loop() {
  // put your main code here, to run repeatedly:

  if (sht.readSample()) {
      Serial.print("SHT:\n");
      Serial.print("  RH: ");
      Serial.print(sht.getHumidity(), 2);
      Serial.print("\n");
      Serial.print("  T:  ");
      Serial.print(sht.getTemperature(), 2);
      Serial.print("\n");
  } else {
      Serial.print("Error in readSample()\n");
  }

  int ADC_VALUE = adc1_get_raw((adc1_channel_t)0);
  Serial.print("ADC CH0 VALUE = ");
  Serial.println(ADC_VALUE);
  float voltage_value = (ADC_VALUE * 3.17 ) / (4095);
  Serial.print("Voltage = ");
  Serial.print(voltage_value * 3.3);
  Serial.println("V");

  Serial.println("");

  int ADC_VALUE1 = adc1_get_raw((adc1_channel_t)1);
  Serial.print("ADC CH1 VALUE = ");
  Serial.println(ADC_VALUE1);
  float voltage_value1 = (ADC_VALUE1 * 3.17 ) / (4095);
  Serial.print("Voltage = ");
  Serial.print(voltage_value1 * 10);
  Serial.println("V");
  delay(1000);
}
