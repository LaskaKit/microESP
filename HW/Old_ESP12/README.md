# LaskaKit microESP

![microESP with solar panel](https://github.com/LaskaKit/microESP/blob/main/img/microESP_1.jpg)

We would like to introduce the smallest evaluation board - [LaskaKit microESP](https://www.laskarduino.cz/laskakit-microesp/). The footprint is compatible with ESP12 or ESP07. It depends on you what you prefer to assemble. 
The dimension of PCB is only 24x21.5mm and the weight is 4g. The evaluation board includes - input of Li-ion battery, charging IC, 3.3V regulator with low quiescent current, input for solar panel and also connector with I2C bus.

## Layout

![TOP of microESP](https://github.com/LaskaKit/microESP/blob/main/img/microESP_TOP.jpg)

![BOTTOM of microESP](https://github.com/LaskaKit/microESP/blob/main/img/microESP_BOT.jpg)

## Solar panel

The [TP4054](https://www.laskarduino.cz/toppower-tp4054-nabijecka-li-ion-clanku--0-4a--sot-23-5/) is used as charging IC, the maximum input voltaga is 10V hence the nominal voltage of solar panel shall be 5V, maximum 6V.

The charging current is defined by R11 resistor and the current is set to 400 mA.

## 3.3V regulator

We used HT7833 as main 3.3V regulator. The main advantage of this regulator is very low quiescentcurrent, typicaly 4 uA. 
Thanks to this regulator and the design of board, the overall current in deepsleep is only 22 uA.

## Programmer

We have own USB-UART programmer with CH340 IC, [LaskaKit CH340 programmer](https://www.laskarduino.cz/laskakit-ch340-programmer-usb-c--microusb--uart/). You can connect this programmer to your laptop through microUSB or USB-C cabel. 
The pinout of programmer is compatible with microESP. The programmer automatically switches the ESP8266 to bootloader mode and after the uploading of code, the ESP is automatically reset. 

## Another features

[LaskaKit microESP](https://www.laskarduino.cz/laskakit-microesp/) contains I2C connector for our temperature/humidity SHT4x/SHT3x module, buti t is not necessary to use only our module. You may directly use for example this module with [SHT31 module](https://www.laskarduino.cz/senzor-teploty-a-vlhkosti-vzduchu-sht30/), and indirectly [sensor of pressure, temperature and humidity BME280](https://www.laskarduino.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), [infrared sensor MLX90615](https://www.laskarduino.cz/arduino-infracerveny-teplomer-mlx90615/) or [GY-21 HTU21D sensor of temperature and humidity](https://www.laskarduino.cz/gy-21-htu21d-senzor-teploty-a-vlhkosti/).

Moreover there are reset button, solder bridge between GPIO16 and reset (to enable the wake up from deepsleep) and also there is voltage divider what is connected to battery and ADC. 
The maximum measured voltage is 4.3V what is enough for measuring of Li-ion battery.

![microESP with solar panel](https://github.com/LaskaKit/microESP/blob/main/img/microESP_2.jpg)

## Demo

We created a demo with our microESP, what you can see on the picture above.
The charging is indicated by LED on board, the sensor module [Temp-HumSensor-SHTxx](https://github.com/LaskaKit/Temp-HumSensor-SHTxx) may be directly connected to the main board. 

The example is available on [our github repository](https://github.com/LaskaKit/microESP/tree/main/examples). IN this example, ESP12 (which we soldered) reads the current temperature and humidity from SHT40 and send to Serial monitor.
