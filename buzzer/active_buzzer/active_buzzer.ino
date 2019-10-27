/**
 * 控制蜂鳴器
 * =============================
 * 透過Serial port來設定蜂鳴器發出聲音的時間，當接收到的
 * 值<0時蜂鳴器則會一直持續不斷發生聲音直到接受到值>0
 * 
 * 此範例的蜂鳴器使用的是有源蜂鳴器
 *
 */

// 指定有源蜂鳴器腳位
const int BUZZEER_PIN = 4;
 
void setup() {
//  腳位設位輸出模式
  pinMode(BUZZEER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) { // 檢查是Serial prot是否有資料 
      // 從Serial port 接收數據並轉成int
      char cmd = int(Serial.read());

      if (cmd <= 0) {
        stopSoundAlert();
      } else {
        soundAlert(1000, cmd);  
      }
  }
}

/**
 * 設定蜂鳴器
 * =====================
 * 當tone()函數未指定時間，則不斷發生音效，直到呼叫noTone()函數
 * 
 * @param int frequency 聲音頻率
 * @param int time 發出聲音時間(毫秒)
 */
void soundAlert(int frequency, int time){
  if (time != 0) {
    tone(BUZZEER_PIN, frequency, time);
  } else {
    tone(BUZZEER_PIN, frequency);
  }
}

/**
 * 強制停止蜂鳴器
 * 
 */
void stopSoundAlert(){
  noTone(BUZZEER_PIN);
}
