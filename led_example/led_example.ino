/**
 * 控制LED明滅
 */
const int LED_PIN = 4;
 
void setup() {
  Serial.begin(9600);
  Serial.println("=====控制LED燈狀態=====");

  // 設定腳位模式
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  if (Serial.available()) { // 檢查是Serial prot是否有資料
    // 利用從Serial接收到數據來控制Relay狀態
    char val = Serial.read();

    if (val == 0) { // Serial收到1表示ON
       setLEDStatus(true); 
    } else if(val == 1) {  // Serial收到1表示OFF
      setLEDStatus(false);
    }
  }
}

void setLEDStatus(bool isOpen) {
  if (isOpen) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
