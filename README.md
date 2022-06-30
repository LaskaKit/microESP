# LaskaKit microESP with ESP32-C3

So powerful and small evaluation board called microESP with ESP32-C3 what includes Wi-Fi and Bluetooth connectivity and moreover the own power consumption is so low.

![Description microESP_ESP32-C3_BOTTOM.jpg](https://github.com/LaskaKit/microESP/blob/main/img/microESP_ESP32-C3_BOTTOM.jpg)

As you can see above, the board includes a lot of things. Let's describe the boardy in details. 
The board is powered from Li-Pol battery what is charger through li-pol charger from solar panel. The recommended voltage of solar panel shall be 5V or 6V.
Thanks to solder bridge on the up, you can choose the charging current to battery - 0.4A or 0.26A. It is depending what lipol battery and solar panel you connected.
Our recommendation:
If you want to use solar panel with current more than 250mA but less than 400mA, use 260 mA charging current. If you the current from solar panel is higher than 400mA, choose 400mA charging current. One more condition is the capacity of lipol battery. If the capacity is lower than 500mA, use 260mA charging current doesn't matter if the current from solar panel is higher than 400mA. Just use 260mA in case the capacity of lipol battery is lower than 500mA.

We put our versatile and safe μŠup connector where you can connect I2C sensors. The lock of connector is mounted inside the connector, so no worries, you can not damage the sensor because you can not turn over the connector.
The sensor what are useful for this board are [SHT40 (temperature and humidity)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/) or [SCD41 (CO2, temperature, humidity](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/). 
Moreover, we added five SMD pads 3x GPIO (IO3, IO4, IO5) and power supply (3.3V and GND) what you can use for what you want.
Also RX and TX of UART bus have SMD pads so if you have sensor with UART bus, you can use it without issue.
Just in case, we added two more SMD pads with 3.3V and GND.

On the upper side, there are three solder bridges. First two solder bridges are used for enabling of voltage measurement from battery and solar panel. 
One is battery voltage measurement (connected to IO0) and the maximum input voltage is 5.8V (with 3.3V ADC reference voltage, R1 100k, R2 130k). The second solder bridge is connected to IO1 and to input of solar panel. The maximum input voltage may be 13.3 V (ADC reference voltage 3.3V, R1 1M, R2 330k) but keep in mind that we recommend the voltage of solar panel 5V or 6V. 
The last solder bridge is used for connecting of I2C pull up resistors (IO18, IO19) to power supply (3.3V).

The best programmer is our [LaskaKit CH340 programmer USB-C, microUSB](https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/) becuase it is pin-to-pin compatible with microESP with ESP32-C3.

![Description microESP_ESP32-C3_TOP.jpg](https://github.com/LaskaKit/microESP/blob/main/img/microESP_ESP32-C3_TOP.jpg)
