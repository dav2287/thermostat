/*

*/

#include "HTU21D.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"


#define AC_RELAY D2
#define HEAT_RELAY D3
#define FAN_RELAY D4
#define OLED_RESET D5

// Initialize display
Adafruit_SSD1306 display(OLED_RESET);
// Initialize temp probe
HTU21D htu = HTU21D();

// Define global variables
float hum;
float temp;
int setPoint = 68;
String mode = "";

void setup() {
  Serial.begin(9600);
  Time.zone(-6); // Sets timezone to Central

  // Start display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  // Set pinModes
  pinMode(AC_RELAY, OUTPUT);
  pinMode(HEAT_RELAY, OUTPUT);
  pinMode(FAN_RELAY, OUTPUT);

  // Register Particle cloud
  Particle.function("command", command);
}

void loop() {
  hum = htu.readHumidity();
  temp = htu.readTemperature();
  Serial.print("Hum: ");
  Serial.println(hum);
  Serial.print("Temp: ");
  Serial.println(temp);
  logic();
  delay(59000);
}

void logic() {
  if ((mode == "heat") && (temp < setPoint)) {
    digitalWrite(HEAT_RELAY, HIGH);
    digitalWrite(FAN_RELAY, HIGH);
  }
  if ((mode == "heat") && (temp >= setPoint)) {
    digitalWrite(HEAT_RELAY, LOW);
    digitalWrite(FAN_RELAY, LOW);
  }
  if ((mode == "cool") && temp > setPoint) {
    digitalWrite(AC_RELAY, HIGH);
    digitalWrite(FAN_RELAY, HIGH);
  }
  if ((mode == "cool") && temp <= setPoint) {
    digitalWrite(AC_RELAY, LOW);
    digitalWrite(FAN_RELAY, LOW);
  }
  else {
    // Turn everything off
    digitalWrite(AC_RELAY, LOW);
    digitalWrite(HEAT_RELAY, LOW);
    digitalWrite(FAN_RELAY, LOW);
  }
}
