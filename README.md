# LaskaKit microESP with ESP32-C3

An incredibly powerful yet miniature board - microESP with the latest ESP32-C3 chip in the ESP32-C3-MINI module supporting Wi-Fi and Bluetooth connectivity and also has very low power consumption.

![Popis microESP_ESP32-C3_BOTTOM.jpg](https://github.com/LaskaKit/microESP/blob/main/img/MicroESP-C3-mini_V3_0_bot.jpg)

As you can see above, the board includes a lot of things. Let's describe the boardy in details. 
The board is powered from Li-Pol battery what is charger through li-pol charger from solar panel. The recommended voltage of solar panel shall be 5V or 6V.

We put our versatile and safe μŠup connector where you can connect I2C sensors. The lock of connector is mounted inside the connector, so no worries, you can not damage the sensor because you can not turn over the connector.
The sensor what are useful for this board are [SHT40 (temperature and humidity)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/) or [SCD41 (CO2, temperature, humidity](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/). 
Moreover, we added GPIOs on both sides of board what you can use for what you want.

On the upper side, there are two solder bridges. First solder bridge is used for enabling of voltage measurement from battery. 
One is battery voltage measurement (connected to IO0) and the maximum input voltage is 5.8V (with 3.3V ADC reference voltage, R1 1M, R2 1.3M). 
The second solder bridge is used for connecting of I2C pull up resistors (SDA - IO8, SCL - IO10) to power supply (3.3V).

To program this miniature and very economical board, you need to connect a USB-C cable to your computer and switch the ESP32-C3 to bootloader mode with the following trick.
Connect the USB-C to the microESP and the computer.
Press and hold the FLASH button.
Press and release the RESET button.
Release the FLASH button.

This board is available on https://www.laskakit.cz/laskakit-microesp/

![TOP](https://github.com/LaskaKit/microESP/blob/main/img/laskakit-microesp-1.jpg)
![BOTTOM](https://github.com/LaskaKit/microESP/blob/main/img/laskakit-microesp-3.jpg)
