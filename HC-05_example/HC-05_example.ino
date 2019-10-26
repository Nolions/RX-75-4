#include <SoftwareSerial.h>

const int BLUETOOTH_RX_PIN = 8;
const int BLUETOOTH_TX_PIN = 9;
const int BLUETOOTH_STATEL_PIN = 10;

SoftwareSerial BT(BLUETOOTH_RX_PIN, BLUETOOTH_TX_PIN); // 接收腳, 傳送腳

void setup() {
  Serial.begin(9600);
  Serial.println("=====HC-05 傳接收數據=====");

  // 設定藍牙模組的連線速率
  BT.begin(9600);
}

void loop() {

  if (isBluetoohtConn) {
    Serial.println("Conection Success");
    
    // 將Serial prot拿到資料透過Bluetooth Port發送
    if (Serial.available()) { // 檢查是Serial prot是否有資料 
      send(Serial.read());
    }

    read();
  } else {
    Serial.println("Conection Fail");
  }

  // 延遲500毫秒
  delay(500);
}

/**
 * 藍芽練線是否建立
 * ====================
 * 當HC-05確定藍芽連線成功建立時STATEL該腳位會為高電位狀態，反之STATE為低電位時則表示藍芽連線未建立
 * PS. 必須要HC-05有把STATEL腳位接出來，才能使用STATE腳位高低電位狀態來判斷藍芽連線是否建立。
 */
bool isBluetoohtConn() {
  if ( digitalRead(BLUETOOTH_STATEL_PIN) == HIGH)  {
    return true;
  }
  return false;
}

/**
 * 透過Bluetooth Port發送訊息
 */
void send(char val) {
  BT.println(val);
}

/**
 * 將Bluetooth prot拿到的資料輸出到Serial Port
 */
void read() {
  if (BT.available()) { // 檢查是Bluetooth prot是否有資料 
    char btVal = BT.read();
    Serial.print(btVal);
  }
}
