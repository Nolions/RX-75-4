/**
 * 透過MAX6675從k-Type取得溫度(°C)
 * 
 * Reference:
 * 1. https://github.com/adafruit/MAX6675-library
 */

#include <max6675.h>

const int THERM_CS_PIN = 9;
const int THERM_SCK_PIN = 8;
const int THERM_SO_PIN = 10;

MAX6675 thermo(THERM_SCK_PIN, THERM_CS_PIN, THERM_SO_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("=====透過MAX6675從k-Type取得溫度=====");
}

void loop() {
  // 取得並印出溫度
  Serial.print("目標溫度:");
  Serial.print(kTypeTemp());
  Serial.print("°C");

  // 延遲500毫秒
  delay(500);
}

/**
 * 從k-type取得溫度(°C)
 */
double kTypeTemp() {
  return thermo.readCelsius();
}
