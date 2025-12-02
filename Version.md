### Version 3.2
- Fixed wrong IO number on top silkscreen, IO8 was "1"
#### Version 3.1
- LDO replaced for RT9080
- µŠup konnector moved a little bit inside
- I2C pullups deleted
- Some power optimisation
- LED Added on GPIO 4
#### Version 3.0
- Reworked version with new module ESP32-C3-MINI
#### Version 2.1
Adjusted resistor values in the resistance divider to 1M/1.3M, ADC max. input voltage stays the same.| Upraveny hodnoty rezistorů v odporovém děliči na 1M/1.3M, ADC max. vstupní napětí zůstává stejné.
#### Version 2.0
- Change ESP-12 to ESP32-C3 | Změněn modul ESP-12 na ESP32-C3
- Voltager devider GPIIO0 (Bat_ADC) changed to 100k/130k ADC max. input voltage is 4.335 V | Dělič napětí GPIIO0 (Bat_ADC) změněn na 100k/130k ADC max. vstupní napětí je 4.335 V
- Voltager devider GPIIO1 (Solar_ADC) changed to 1M/330k ADC max. input voltage is 9.874 V | Dělič napětí GPIIO1 (Solar_ADC) změněn na 1M/330k ADC max. vstupní napětí je 9.874 V
- Add 100nF capacitors to ADC inputs Bat_ADC and Solar_ADC | Přidány filtrační kondenzátory 100nF na ADC vstupy Bat_ADC a Solar_ADC
#### Version 1.0
- Initial | Počáteční