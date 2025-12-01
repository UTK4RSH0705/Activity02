// Blynk credentials
#define BLYNK_TEMPLATE_ID "TMPL3C9F07ms5"
#define BLYNK_TEMPLATE_NAME "Air Quality Monitoring System"
#define BLYNK_AUTH_TOKEN "akq_-DPpKX-JVC4SRYWfPbbLDj4yOEoM"
char ssid[] = "Room No 14";
char pass[] = "Mauli@1414";

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"


// Sensor pins
#define DHTPIN 13
#define DHTTYPE DHT11          // DHT sensor type
#define MQ135_PIN 34           // MQ135 analog pin

// LED pins
#define RED_LED 14             // GPIO14 for "Bad" air (red)
#define GREEN_LED 27           // GPIO27 for "Good/Moderate" air (green)

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Use your LCD address (0x27 or try 0x3F if 0x27 doesn't work)

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int mq135Value = analogRead(MQ135_PIN);

  // LCD: Temperature
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(t,1);
  lcd.print("C");
  delay(2000);

  // LCD: Humidity
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(h,1);
  lcd.print("%");
  delay(2000);

  // LCD: Air Quality + Status
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Air Q:");
  lcd.print(mq135Value);
  lcd.setCursor(0,1);

  // LED Logic + Notifications
  if (mq135Value >= 1400) {
    lcd.print("Air: Poor");
    digitalWrite(RED_LED, HIGH);      // Red LED for BAD air
    digitalWrite(GREEN_LED, LOW);
    Blynk.logEvent("air_warning", "Warning! Air quality is Poor.");
  } else {
    if (mq135Value < 650) {
      lcd.print("Air: Good");
    } else {
      lcd.print("Air: Moderate");
    }
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);    // Green LED for MODERATE/GOOD air
  }
  delay(2000);

  // Virtual Pins for Blynk
  Blynk.virtualWrite(V0, t);          // Temperature
  Blynk.virtualWrite(V1, h);          // Humidity
  Blynk.virtualWrite(V2, mq135Value); // MQ135 raw value

  Blynk.run();
}
