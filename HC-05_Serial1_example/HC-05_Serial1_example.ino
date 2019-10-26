 /**
 * HC-05 Read and Send message example2
 * =======================================
 * arduino micro與arduino Leonardo板子除了原先電腦溝通的USB Serial Port
 * 之外新增一組新的Serial Port(Serial1)，因此在串接HC-05就可以直接使用Serial1
 * 的腳位，不需要而額外指定額外數位腳位來做為TX與RX使用。
 * 
 * 該範例與另一個利用HC-05實作藍芽傳接收大致相同，差別在於直接Serial1的TX與RX腳位，
 * 而不用特別去定義數位腳位來做TX與RX。
 */
const int BLUETOOTH_STATEL_PIN = 10; // HC-05 STATEL PIN

void setup() {
  Serial.begin(9600);
  Serial.println("=====HC-05 by Serial1 傳接收數據 =====");

  // 設定藍牙模組的連線速率
  Serial1.begin(9600);
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
  Serial1.println(val);
}

/**
 * 將Bluetooth prot拿到的資料輸出到Serial Port
 */
void read() {
  if (Serial1.available()) { // 檢查是Bluetooth prot是否有資料 
    char btVal = Serial1.read();
    Serial.print(btVal);
  }
}
