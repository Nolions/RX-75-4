/**
 * Relay control example
 * ==================================
 * 此範例使用的`高電平`的Relay，高電平繼電器在in 腳位在高電平狀態會讓Relay呈現通電的狀態，
 * 相反的在低電平狀態下則是呈現短路狀態。
 * 
 * 如果今天使用`低電平`的Relay，`in`腳位在高電位會讓繼電器呈現短路狀態，低電位則會讓Relay
 * 呈現通電的狀態。
 */
const int Relay_IN_PIN = 4;
 
void setup() {
  Serial.begin(9600);
  Serial.println("=====控制Relay通/斷電狀態=====");

  // 設定腳位模式
  pinMode(Relay_IN_PIN, OUTPUT);
}

void loop(bool isHight) {
  if (Serial.available()) { // 檢查是Serial prot是否有資料
    // 利用從Serial接收到數據來控制Relay狀態
    char val = Serial.read();

    if (val == 0) { // Serial收到1表示ON
       setRelay(true); 
    } else if(val == 1) {  // Serial收到1表示OFF
      setRelay(false);
    }
  }
}

/**
 * 控制器繼電器狀態
 */
void setRelay(double nowTemp) {
  if (isHight) {
    digitalWrite(Relay_IN_PIN, HIGH);
  } else {
    digitalWrite(Relay_IN_PIN, LOW);
  }
}
