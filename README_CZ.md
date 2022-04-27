# LaskaKit microESP-C3

Neskutečně nabušená a přitom miniaturní deska - microESP-C3 s nejnovějším čipem ESP32-C3 podporující Wi-Fi i Bluetooth konektivitu a navíc má i velmi malou vlastní spotřebu. 

![Popis microESP-C](https://github.com/LaskaKit/microESP/blob/main/img/microesp-popis.jpg)

Jak můžeš vidět na obrázku výše, na desce je toho opravdu hodně. Deska se napájí z připojeného solárního panelu. Jmenovité napětí doporučujeme 5V nebo 6V. Deska samotná je osazena čipem pro pohodlné a bezpečné nabíjení lipol akumulátoru. Na horní straně desky je pájecí most, kterým si můžeš vybrat nabíjecí proud - 0.4A nebo 0.26A. Záleží od toho, jaký akumulátor a solární panel k tomu připojíš.
Naše doporučení: 
Pokud máš solár s výstupním proudem od 250 do 400mA, zvol 260 mA. Pokud vyšší než 400mA, pak 400mA. K tomu se váže i podmínka kapacity akumulátoru. Pokud je kapacita akumulátoru menší než 500, zvol raději 260 mA i kdybys měl solár, co dodá třeba 500mA.

Na desku jsme přidali i náš uŠup konektor, ke kterému můžeš velmi pohodlně a bezpečně připojit nejrůznější I2C čidla. Konektor zajišťuje bezpečnost připojení díky vestavěnému zámku v konektoru. 
Ale i přesto, že jsme tam dali konektor na I2C čidlo, využili jsme prostor ještě k přidání pěti SMD plošek, 3x GPIO (IO3, IO4, IO5) a napájení (3.3V a GND).
Vyvedli jsme na SMD pady i RX a TX sběrnice UART, takže pokud máš nějaké čidlo komunikující skrze UART, není problém ho s microESP-C3 použít. 

Na horní straně se ještě nachází dva pájecí mosty. Oba jsou určené pro měření napětí, u prvního je to napětí akumulátoru (výstup za děličem napětí akumulátoru je připojen na IO0) a převodní poměr je 3,3:1, u druhého je připojen na IO1 a převodní poměr je 10:1 s tím, že referenční napětí ADC převodníku je 3.3V.

K programování můžeš použít náš LaskaKit CH340 programmer USB-C, microUSB(https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/). I proto je microESP-C3 tak úsporná. Neobsahuje žádné zbytečné součástky, které by zbytečně odebírali vzácnou energii z akumulátoru.

