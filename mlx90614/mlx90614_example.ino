
/**
 * 使用MLX90614取得目標與環境溫度
 * 
 * Reference:
 * 1. http://iotdk.intel.com/docs/upm/v0.4.0/classupm_1_1_m_l_x90614.html
 */
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  Serial.println("=====透過MLX90614取得溫度=====");
  mlx.begin();
}

void loop() {
  // 取得並印出目標溫度
  Serial.print("目標溫度:");
  Serial.print(objectTempOfFah());
  Serial.print("°C/");
  Serial.print(objectTempOfFah());
  Serial.println("°F");

  // 取得並印出環境溫度
  Serial.print("環境溫度:");
  Serial.print(ambientTempOfCelsius());
  Serial.print("°C / ");
  Serial.print(ambientTempOfFah());
  Serial.println("°F");

  // 延遲500毫秒
  delay(500);
}

/**
 * 取得MLX90614紅外線目標攝氏溫度
 */
float objectTempOfCelsius() {
  return mlx.readObjectTempC();
}

/**
 * 取得MLX90614紅外線目標華氏溫度
 */
float objectTempOfFah() {
  return mlx.readObjectTempC();
}

/**
 * 取得MLX906145周圍目標攝氏溫度
 */
float ambientTempOfCelsius(){
  return mlx.readAmbientTempC();
}

/**
 * 取得MLX906145周圍目標華氏溫度
 */
float ambientTempOfFah(){
  return mlx.readAmbientTempF();
}
