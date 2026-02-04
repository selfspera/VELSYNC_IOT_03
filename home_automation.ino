// Wi-Fi controlled home automation using Blynk App & ESP8266

#define BLYNK_TEMPLATE_ID "TMPL38q_TfX1s"
#define BLYNK_TEMPLATE_NAME "HOME AUTOMATION"
#define BLYNK_AUTH_TOKEN "VFLjEPGRYF_vvoTJsSF0CdDxaOvN31Ci"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Huii";   // Your Wifi Name
char pass[] = "90909090"; // Your Wifi Password

// Blynk virtual pins and the corresponding relay GPIO pins
BLYNK_WRITE(V1) {
  int value = param.asInt();
  Serial.println(value);
  if (value == 1) {
    digitalWrite(D1, LOW); // Turn relay on (active low)
    Serial.println("Relay 1 ON");
  }
  if (value == 0) {
    digitalWrite(D1, HIGH); // Turn relay off
    Serial.println("Relay 1 OFF");
  }
}

BLYNK_WRITE(V2) {
  int value = param.asInt();
  Serial.println(value);
  if (value == 1) {
    digitalWrite(D2, LOW); // Turn relay on (active low)
    Serial.println("Relay 2 ON");
  }
  if (value == 0) {
    digitalWrite(D2, HIGH); // Turn relay off
    Serial.println("Relay 2 OFF");
  }
}

BLYNK_WRITE(V3) {
  int value = param.asInt();
  Serial.println(value);
  if (value == 1) {
    digitalWrite(D3, LOW); // Turn relay on (active low)
    Serial.println("Relay 3 ON");
  }
  if (value == 0) {
    digitalWrite(D3, HIGH); // Turn relay off
    Serial.println("Relay 3 OFF");
  }
}

BLYNK_WRITE(V4) {
  int value = param.asInt();
  Serial.println(value);
  if (value == 1) {
    digitalWrite(D4, LOW); // Turn relay on (active low)
    Serial.println("Relay 4 ON");
  }
  if (value == 0) {
    digitalWrite(D4, HIGH); // Turn relay off
    Serial.println("Relay 4 OFF");
  }
}

void setup() {
  // Start serial monitor for debugging
  Serial.begin(115200);
  
  // Initialize WiFi and Blynk
  Blynk.begin(auth, ssid, pass);
  
  // Set relay pins as OUTPUT
  pinMode(D1, OUTPUT); // GPIO 5 (D1)
  pinMode(D2, OUTPUT); // GPIO 4 (D2)
  pinMode(D3, OUTPUT); // GPIO 0 (D3) 
  pinMode(D4, OUTPUT); // GPIO 2 (D4)

  // Initialize relay pins to HIGH (off)
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void loop() {
  // Run the Blynk protocol
  Blynk.run();
}
