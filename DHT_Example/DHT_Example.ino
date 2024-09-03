
#include "DHT.h"

#define DHTPIN #     // Your Pin #
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); //Wait 2s 
  float humidite = dht.readHumidity(); // Humidity in %
  float temp = dht.readTemperature(); // Temperature in Celsius.
  // Verify if there is an error
  if (isnan(humidite) || isnan(temp)) {
    Serial.println(F("Erreur de lecture depuis le capteur DHT !"));
    return;
  }
  Serial.print("Temperature: "+temp+" Humidity: "+humidite)
}
