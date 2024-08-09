![ESP32-C6 DevKit](https://github.com/LaskaKit/ESP32-C6-DEVKit/blob/main/images/esp32-c6-devkit.JPG)

# ESP32-C6 DEVkit

Do naší už tak bohaté sbírky vývojových kitů založených na čipem ESP32 jsme přidali dlouho žádaný ESP32-C6.

Vývojová deska s mikrokontrolerem ESP32-C6 speciálně navržená pro ultra nízkopříkonové IoT aplikace napájené z baterií. ESP32-C6-DEVKit je vývojová deska založená na ESP32-C6-WROOM-1-N16, modulu pro všeobecné použití s 16MB SPI flash. Tato deska integruje kompletní funkce Wi-Fi, Bluetooth LE, Zigbee a Thread. Díky své volbě použitých komponent a obvodovému řešení se jedná o jednu z desek s extrémně malou spotřebou v režimu spánku. Také použitý typ mikrokontroleru - SoC ESP32 předurčuje tuto desku do vysoce výkonných IoT aplikací. Deska obsahuje i integrovanou nabíječku jednoho Li-ION článku, ze kterého je pak deska i napájena. S touto deskou již nemusíte volit mezi výkonem a spotřebou a tak se můžete plně soustředit na vlastní vývoj aplikace skoro bez omezení.

Rozteč I/O pinů byla záměrně zvolena tak, aby bylo možné celou desku ve fázi vývoje zasunout do nepájivého kontaktního pole, což může značně zjednodušit prvotní návrh vyvíjené aplikace.

Deska již obsahuje integrovaný programátor a tak již není nutné žádný jiný používat. Díky novému čipu programátoru a jeho zapojení není zásadně ovlivně spotřeba v režimu spánku a tudíž jej lze využívat i pro aplikace náročné na dlouhou dobu provozu při napájení z baterie.

Pro co nejrychlejší start s ESP32-C6 DevKit jsme pro tebe připravili vzorové kódy https://github.com/LaskaKit/ESP32-C6-DEVKit/tree/main/SW 

I2C (uŠup): </br>
SDA - IO4 </br>
SCL - IO5</br>
Napájení - IO11 (active HIGH)</br>
</br>
Měření baterie:</br>
IO3</br>
</br>
RGB LED:</br>
Data - IO9</br>
</br>
SPI (uŠup):</br>
CS - IO18</br>
SDI/MOSI - IO7</br>
CLK - IO6</br>
MISO - IO2</br>
Napájení - IO11 (active HIGH)</br>
</br>
## Deska je k dostání na https://www.laskakit.cz/laskakit-esp32-c6-devkit-wifi-6--bluetooth-5--zigbee/ 
