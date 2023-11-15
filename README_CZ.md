# LaskaKit microESP s ESP32-C3

Neskutečně nabušená a přitom miniaturní deska - microESP s nejnovějším čipem ESP32-C3 v modulu ESP32-C3-MINI podporující Wi-Fi i Bluetooth konektivitu a navíc má i velmi malou vlastní spotřebu. 

![Popis microESP_ESP32-C3_BOTTOM.jpg](https://github.com/LaskaKit/microESP/blob/main/img/MicroESP-C3-mini_V3_0_bot.jpg)

PINOUT

![Pinout](https://github.com/LaskaKit/microESP/blob/main/img/MicroESP-C3-mini_V3_0_pinout.jpg)

Jak můžeš vidět na obrázku výše, na desce je toho opravdu hodně. Deska se napájí z připojeného akumulátoru, který může být nabíjen přes integrovaný nabíjecí kontrolér ze solárního panelu. Jmenovité napětí solárního panelu doporučujeme 5V nebo 6V. 

Na desku jsme přidali i náš μŠup konektor, ke kterému můžeš velmi pohodlně a bezpečně připojit nejrůznější I2C čidla. Konektor zajišťuje bezpečnost připojení díky vestavěnému zámku v konektoru. 
Čidla, která se hodí k této vývojové desce jsou například [SHT40 (čidlo teploty a vlhkosti)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/) nebo [SCD41 (čidlo CO2, teploty, vlhkosti](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/). 
Ale i přesto, že jsme tam dali konektor na I2C čidlo, využili jsme prostor ještě k přidání dalších GPIO po stranách modulu.
Vyvedli jsme i RX a TX sběrnice UART, takže pokud máš nějaké čidlo komunikující skrze UART, není problém ho s microESP použít. 

Na horní straně se ještě nachází dva pájecí mosty. Jeden je určený pro měření napětí akumulátoru (výstup za děličem napětí akumulátoru je připojen na IO0). Rezistor R1 je 1M, R2 je 1.3M, maximální vstupní napětí (při 3,3V ADC referenci) je 5,8V. 
Poslední pájecí most je připojení pull-up rezistorů na I2C sběrnici (SDA - IO8, SCL - IO10).

K programování této miniaturní a velmi úsporné desky potřebuješ připojit USB-C kabel k počítači a přepnout ESP32-C3 do bootloader režimu, což provedeš následujícím trikem.
Připoj USB-C do microESP a počítače.
Zmáčkni a drž tlačítko FLASH.
Zmáčkni a uvolni tlačítko RESET.
Uvolni tlačítko FLASH.

Tato deska je dostupná na https://www.laskakit.cz/laskakit-microesp/

![TOP](https://github.com/LaskaKit/microESP/blob/main/img/laskakit-microesp-1.jpg)
![BOTTOM](https://github.com/LaskaKit/microESP/blob/main/img/laskakit-microesp-3.jpg)
