// Deep sleep test, ESP32-C6 is getting 14µA 

#define SLEEP_SEC 15         // Measurement interval (seconds)
#define POWER 13

void setup(void)
{
  Serial.begin(115200);

  pinMode(POWER, OUTPUT);
  digitalWrite(POWER, HIGH);
  Serial.println("µŠUP power ON");

  goToSleep();
}

void loop(void) 
{

}

void goToSleep(){

  Serial.println("I'm mot sleeping");
  delay(3000);
  digitalWrite(POWER, LOW);
  Serial.println("µŠUP power OFF");

  Serial.println("going to sleep 15 sek");
  // ESP Deep Sleep 
  Serial.println("ESP in sleep mode");
  Serial.flush(); 
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  esp_deep_sleep_start();
}
