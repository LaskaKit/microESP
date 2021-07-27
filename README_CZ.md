# LaskaKit microESP

![microESP se solárním panelem](https://github.com/LaskaKit/microESP/blob/main/img/microESP_1.jpg)

Představujeme vám naší nejmenší vývojovou desku - [LaskaKit microESP](https://www.laskarduino.cz/laskakit-microesp/). Footprint je kompatibilní s ESP12, ESP07 nebo ESP32-C3 - záleží na vás, jaký modul preferujete a jaký osadíte. 
A i když je velikost plošného spoje jen 24x21,5mm a váha pouhé 4g, obsahuje například - vstup na Li-ion akumulátor i nabíjecí obvod, stabilizátor na 3.3V s velmi nízkou vlastní spotřebou, vstup na solární panel a také konektor pro čidla s I2C rozhraním. 

## Rozvržení

![TOP strana microESP](https://github.com/LaskaKit/microESP/blob/main/img/microESP_TOP.jpg)


![BOTTOM strana microESP](https://github.com/LaskaKit/microESP/blob/main/img/microESP_BOT.jpg)

## Solární panel

Jako solární panel musí být použitý takový, který má jmenovité napětí 5V, maximálně 6V. Jako nabíjecí obvod slouží [TP4054](https://www.laskarduino.cz/toppower-tp4054-nabijecka-li-ion-clanku--0-4a--sot-23-5/). Jeho maximální napětí může být až 10V, doporučené je však maximálně 6,5V. 

Nabíjecí proud je nastaven rezistorem R11 na hodnotu 400 mA.

## 3,3V regulátor

Jako regulátor je použitý známý HT7833, který má velmi nízkou vlastní spotřebu (typ. 4uA). V kombinaci s nízkou spotřebou Wi-Fi modulu ESP12 činí spotřeba celé desky pouhých 22 uA v režimu nejhlubšího spánku.

## Programátor

K programování může sloužit náš USB-UART převodník s čipem CH340, [LaskaKit CH340 programmer](https://www.laskarduino.cz/laskakit-ch340-programmer-usb-c--microusb--uart/). Tento převodník můžete připojit k počítači přes microUSB kabel, ale i přes kabel s USB-C konektorem. 
Do LaskaKit microESP se pouze vsune, je pinově kompatibilní s deskou.
Převodník automaticky sám přepne microESP do programovacího režimu a po naprogramování opět resetuje. 

## Další vlastnosti

[LaskaKit microESP](https://www.laskarduino.cz/laskakit-microesp/) navíc obsahuje i I2C konektor nejen pro náš modul teploty a vlhkosti s SHT4x/SHT3x.
Není ale nezbytné použít pouze tento modul s čidlem. Použít přímo můžete například modul s [SHT31](https://www.laskarduino.cz/senzor-teploty-a-vlhkosti-vzduchu-sht30/), nebo nepřímo i [senzor tlaku, teploty a vlhkosti BME280](https://www.laskarduino.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), [infračervený teploměr MLX90615](https://www.laskarduino.cz/arduino-infracerveny-teplomer-mlx90615/) nebo [GY-21 HTU21D senzor teploty a vlhkosti](https://www.laskarduino.cz/gy-21-htu21d-senzor-teploty-a-vlhkosti/).

Na desce se ještě nachází reset tlačítko, propojka mezi GPIO16 a reset (probuzení z nejhlubšího spánku) a také je deska osazena odporovým děličem napětí, který je připojen na vstup z akumulátoru. 
Poměr rezistorů je 3,3, to znamená, že maximální měřitelné napětí je 4,3V. Což je dostačující pro měření Li-ion akumulátoru.

![microESP se solárním panelem](https://github.com/LaskaKit/microESP/blob/main/img/microESP_2.jpg)

## Praktické použití

Jedno z praktických použití můžete vidět na fotografii výše. 
Nabíjení akumulátoru ze solárního panelu je indikován osazenou LED. Modul čidla [Temp-HumSensor-SHTxx](https://github.com/LaskaKit/Temp-HumSensor-SHTxx) může být napřímo připojen k LaskaKit microESP vývojovému kitu

Příklad použití můžete najít [na našem github](https://github.com/LaskaKit/microESP/tree/main/examples). V tomto příkladu ESP12 (který jsme použili) vyčte aktuální teplotu a vlhkost z čidla SHT40. Teplotu a vlhkost vypíše do serial terminálu.  
