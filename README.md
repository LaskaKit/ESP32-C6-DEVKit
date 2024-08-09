![ESP32-C6 DevKit](https://github.com/LaskaKit/ESP32-C6-DEVKit/blob/main/images/esp32-c6-devkit.JPG)

# ESP32-C6 DEVkit

We have added the long requested ESP32-C6 to our collection of ESP32 based development kits.
https://github.com/LaskaKit/ESP32-C6-DEVKit/tree/main
An ESP32-C6 microcontroller development board specifically designed for ultra-low power battery powered IoT applications. The ESP32-C6-DEVKit is a development board based on the ESP32-C6-WROOM-1-N16, a general purpose module with 16MB SPI flash. This board integrates complete Wi-Fi, Bluetooth LE, Zigbee and Thread functionality. Due to its choice of components and circuit design, it is one of the boards with extremely low power consumption in sleep mode. Also, the type of microcontroller used - SoC ESP32 predestines this board for high performance IoT applications. The board also includes an integrated charger for one Li-ION cell, from which the board is then powered. With this board, you no longer have to choose between power and power consumption, so you can concentrate on your own application development almost without limitations.

The spacing of the I/O pins was deliberately chosen so that the entire board can be inserted into a non-soldering contact field during the development phase, which can greatly simplify the initial design of the application under development.

The board already contains an integrated programmer and so there is no need to use any other. Thanks to the new programmer chip and its wiring, the sleep mode consumption is not significantly affected and therefore it can be used even for applications demanding long run times on battery power.

For the quick start with this development board with ESP32-C6, we wrote several example codes https://github.com/LaskaKit/ESP32-C6-DEVKit/tree/main/SW

I2C (uŠup): 
SDA - IO4 
SCL - IO5
Power - IO11 (active HIGH)

Baterry voltage measurement:
IO3

RGB LED:
Data - IO9

SPI (uŠup):
CS - IO18
SDI/MOSI - IO7
CLK - IO6
MISO - IO2
Power - IO11 (active HIGH)

## You can buy on https://www.laskakit.cz/laskakit-esp32-c6-devkit-wifi-6--bluetooth-5--zigbee/ 
