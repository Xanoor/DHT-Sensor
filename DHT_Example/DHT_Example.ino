
#include "DHT.h"

#define DHTPIN #     // Votre Pin a la place du #
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); //Attendre 2s (obligatoire)
  float humidite = dht.readHumidity(); // Humidité en %
  float temp = dht.readTemperature(); // Température en Celsius.
  // Vérification d'erreur
  if (isnan(humidite) || isnan(temp)) {
    Serial.println(F("Erreur de lecture depuis le capteur DHT !"));
    return;
  }
  Serial.print("Température: "+temp+" Humidité: "+humidite)
}
