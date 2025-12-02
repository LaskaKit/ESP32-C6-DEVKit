/* Board test for LaskaKit ESP32-C6-DEVkit
 * example from Adafruit library is used
 * 
 * Board:   LaskaKit ESP32-C6-DEVkit                    https://www.laskakit.cz/laskakit-esp32-c6-devkit-wifi-6--bluetooth-5--zigbee/
 * Sensor:  LaskaKit SHT40 Humidity & Temp Sensor       https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/
 * Display: LaskaKit OLED displej 128x32 0.91" I²C      https://www.laskakit.cz/laskakit-oled-displej-128x32-0-91--i--c/
 * 
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

// Requires Adafruit SHT4x Adafruit_GFX and Adafruit_SSD1306 library

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_SHT4x.h"

#define PIN_ON 11
#define PIN_SCL 5
#define PIN_SDA 4
#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_SHT4x sht4 = Adafruit_SHT4x();

void setup() {
  Serial.begin(115200);
  pinMode(PIN_ON, OUTPUT);
  digitalWrite(PIN_ON, HIGH);
  delay(100);
  Wire.begin(PIN_SDA, PIN_SCL);

  while (!Serial)
    delay(10);

  Serial.println("Adafruit SHT4x test");
  if (! sht4.begin()) {
    Serial.println("Couldn't find SHT4x");
    while (1) delay(1);
  }
  Serial.println("Found SHT4x sensor");
  Serial.print("Serial number 0x");
  Serial.println(sht4.readSerial(), HEX);

  // You can have 3 different precisions, higher precision takes longer
  sht4.setPrecision(SHT4X_HIGH_PRECISION);
  switch (sht4.getPrecision()) {
     case SHT4X_HIGH_PRECISION: 
       Serial.println("High precision");
       break;
     case SHT4X_MED_PRECISION: 
       Serial.println("Med precision");
       break;
     case SHT4X_LOW_PRECISION: 
       Serial.println("Low precision");
       break;
  }

  // You can have 6 different heater settings
  // higher heat and longer times uses more power
  // and reads will take longer too!
  sht4.setHeater(SHT4X_NO_HEATER);
  switch (sht4.getHeater()) {
     case SHT4X_NO_HEATER: 
       Serial.println("No heater");
       break;
     case SHT4X_HIGH_HEATER_1S: 
       Serial.println("High heat for 1 second");
       break;
     case SHT4X_HIGH_HEATER_100MS: 
       Serial.println("High heat for 0.1 second");
       break;
     case SHT4X_MED_HEATER_1S: 
       Serial.println("Medium heat for 1 second");
       break;
     case SHT4X_MED_HEATER_100MS: 
       Serial.println("Medium heat for 0.1 second");
       break;
     case SHT4X_LOW_HEATER_1S: 
       Serial.println("Low heat for 1 second");
       break;
     case SHT4X_LOW_HEATER_100MS: 
       Serial.println("Low heat for 0.1 second");
       break;
  }
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // Clear the buffer
  display.clearDisplay();
}


void loop() {
  sensors_event_t humidity, temp;
  
  uint32_t timestamp = millis();
  sht4.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  timestamp = millis() - timestamp;

  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 5);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.println("Temperature: " + String(temp.temperature) + "C");
  display.println("Humidity: " + String(temp.relative_humidity) + "%");
  display.display();

  Serial.print("Read duration (ms): ");
  Serial.println(timestamp);

  delay(1000);
}