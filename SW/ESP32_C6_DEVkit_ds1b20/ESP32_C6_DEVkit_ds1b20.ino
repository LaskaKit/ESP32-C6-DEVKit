/* Board test for LaskaKit ESP32-C6-DEVkit
 * example from DAllaTemperature library by Miles Burton is used
 * 
 * Board:   LaskaKit ESP32-C6-DEVkit                              https://www.laskakit.cz/laskakit-esp32-c6-devkit-wifi-6--bluetooth-5--zigbee/
 * Sensor:  Maxim Integrated DS18B20+ digital temperature sensor  https://www.laskakit.cz/maxim-integrated/
 * 
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */


#include <OneWire.h>
#include <DallasTemperature.h>

#define PIN_ON 11
#define ONE_WIRE_BUS 10

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  pinMode(PIN_ON, OUTPUT);
  digitalWrite(PIN_ON, HIGH);
  delay(100);
  while(!Serial);    // time to get serial running

  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
}


void loop() { 
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  delay(1500);
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  }
  else
  {
    Serial.println("Error: Could not read temperature data");
  }
}
