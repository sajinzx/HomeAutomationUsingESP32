/*************************************************************
  Original Blynk Edgent Example with added
  DHT11 and Soil Moisture Automatic Control (No Blynk Data)
*************************************************************/

#define BLYNK_TEMPLATE_ID "TMPL3zuGf9oHi"
#define BLYNK_TEMPLATE_NAME "Home Automation"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG

#include "BlynkEdgent.h"
#include <DHT.h>

#define DHTPIN 12         // DHT11 sensor connected to GPIO 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_PIN 27        // Soil moisture sensor analog pin
#define TEMP_RELAY 15      // Relay for temperature control
#define SOIL_RELAY 2       // Relay for soil moisture control

// Thresholds
float TEMP_THRESHOLD = 30.0;  // °C
int SOIL_THRESHOLD = 500;     // 0–4095 (ESP32 ADC range)

unsigned long lastSensorRead = 0;
unsigned long sensorInterval = 2000; // Every 2 seconds

void setup() {
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();

  dht.begin();
  
  pinMode(15, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(SOIL_PIN, INPUT);

  Serial.println("System ready with Temperature and Soil Moisture Control");
}

// Existing Blynk controls (unchanged)
BLYNK_WRITE(V0){
  int s1 = param.asInt();
  digitalWrite(15, s1);
}

BLYNK_WRITE(V1){
  int s1 = param.asInt();
  digitalWrite(2, s1);
}

BLYNK_WRITE(V2){
  int s1 = param.asInt();
  digitalWrite(4, s1);
}

BLYNK_WRITE(V3){
  int s1 = param.asInt();
  digitalWrite(5, s1);
}

// Automatic Temperature & Soil Control
void autoControl() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int soilValue = analogRead(SOIL_PIN);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temp: "); Serial.print(temperature);
  Serial.print(" °C | Humidity: "); Serial.print(humidity);
  Serial.print("% | Soil: "); Serial.println(soilValue);

  // Temperature-based relay control
  if (temperature > TEMP_THRESHOLD) {
    digitalWrite(TEMP_RELAY, HIGH);
  } else {
    digitalWrite(TEMP_RELAY, LOW);
  }

  // Soil moisture-based relay control
  if (soilValue < SOIL_THRESHOLD) {
    digitalWrite(SOIL_RELAY, HIGH);
  } else {
    digitalWrite(SOIL_RELAY, LOW);
  }
}

void loop() {
  BlynkEdgent.run();

  if (millis() - lastSensorRead > sensorInterval) {
    lastSensorRead = millis();
    autoControl();
  }
}