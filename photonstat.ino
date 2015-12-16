/*

*/

#include "HTU21D.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define OLED_RESET D4
Adafruit_SSD1306 display(OLED_RESET);

HTU21D htu = HTU21D();
float hum;
float temp;
int setPoint = 68;
String mode = "";

void setup() {
  Serial.begin(9600);
  Time.zone(-6);
  Particle.function("command", command);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  hum = htu.readHumidity();
  temp = htu.readTemperature();
  Serial.print("Hum: ");
  Serial.println(hum);
  Serial.print("Temp: ");
  Serial.println(temp);
  delay(1000);
}
