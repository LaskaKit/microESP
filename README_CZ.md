# LaskaKit microESP s ESP32-C3

Neskutečně nabušená a přitom miniaturní deska - microESP s nejnovějším čipem ESP32-C3 podporující Wi-Fi i Bluetooth konektivitu a navíc má i velmi malou vlastní spotřebu. 

![Popis microESP_ESP32-C3_BOTTOM.jpg](https://github.com/LaskaKit/microESP/blob/main/img/microESP_ESP32-C3_BOTTOM.jpg)

Jak můžeš vidět na obrázku výše, na desce je toho opravdu hodně. Deska se napájí z připojeného akumulátoru, který může být nabíjen přes integrovaný nabíjecí kontrolér ze solárního panelu. Jmenovité napětí solárního panelu doporučujeme 5V nebo 6V. 
Na horní straně desky je pájecí most, kterým si můžeš vybrat nabíjecí proud do akumulátoru - 0,4A nebo 0,26A. Záleží od toho, jaký akumulátor a solární panel k tomu připojíš.
Naše doporučení: 
Pokud máš solár s výstupním proudem od 250 do 400mA, zvol 260 mA. Pokud vyšší než 400mA, pak 400mA. K tomu se váže i podmínka kapacity akumulátoru. Pokud je kapacita akumulátoru menší než 500, zvol raději 260 mA i kdybys měl solár, co dodá třeba 500mA.

Na desku jsme přidali i náš μŠup konektor, ke kterému můžeš velmi pohodlně a bezpečně připojit nejrůznější I2C čidla. Konektor zajišťuje bezpečnost připojení díky vestavěnému zámku v konektoru. 
Čidla, která se hodí k této vývojové desce jsou například [SHT40 (čidlo teploty a vlhkosti)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/) nebo [SCD41 (čidlo CO2, teploty, vlhkosti](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/). 
Ale i přesto, že jsme tam dali konektor na I2C čidlo, využili jsme prostor ještě k přidání pěti SMD plošek, 3x GPIO (IO3, IO4, IO5) a napájení (3.3V a GND).
Vyvedli jsme na SMD pady i RX a TX sběrnice UART, takže pokud máš nějaké čidlo komunikující skrze UART, není problém ho s microESP použít. 
Na další dva pady jsme ještě vyvedli opět napájení (3.3V a GND).

Na horní straně se ještě nachází tři pájecí mosty. Dva jsou určené pro měření napětí, u prvního je to napětí akumulátoru (výstup za děličem napětí akumulátoru je připojen na IO0). Rezistor R1 je 100k, R2 je 130, maximální vstupní napětí (při 3,3V ADC referenci) je 5,8V. U druhého je připojen na IO1 a rezistory jsou 1M a 330k. Maximální měření napětí ze solárního panelu tak může být až 13,3V (ADC reference je nastavena na 3,3V).
Poslední pájecí most je připojení pull-up rezistorů na I2C sběrnici (IO18, IO19).

K programování můžeš použít náš LaskaKit CH340 programmer USB-C, microUSB(https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/). I proto je microESP tak úsporná. Neobsahuje žádné zbytečné součástky, které by zbytečně odebíraly vzácnou energii z akumulátoru.

![Popis microESP_ESP32-C3_TOP.jpg](https://github.com/LaskaKit/microESP/blob/main/img/microESP_ESP32-C3_TOP.jpg)
