//============================================================================
// Name        : while2.cpp
//小明想要存錢買一輛機車,機車每輛30000元，他將每月存的錢輸入，當存款足夠買機車時，就顯示提示訊息告知。
//存款不足，顯示紅燈，響一次
//存款足夠，顯示綠燈，響音樂
//============================================================================
//BUZZER插在D1孔
#include <MatrixMini.h>
#define BUZZER 3

//建立小車
MatrixMini Mini;
//存款
long deposit = 0;

//存款次數
int num=0;

//接收使用者輸入的值
int inputNum;

void setup() {
  Serial.begin(9600);
  //起動小車
  Mini.begin();
  Mini.LED1.setRGB(255, 0, 0);
  Mini.LED2.setRGB(255, 0, 0);
  //啟動Buzzer
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, HIGH);

  while(deposit < 30000){
    num++;
    digitalWrite(BUZZER, LOW);
    delay(100);
    digitalWrite(BUZZER, HIGH);
    
    Serial.print("請輸入第" + String(num) +"個月分的存款:");
    while(true){
      if(Serial.available()){
        inputNum = Serial.parseInt();
        Serial.println(inputNum);
        deposit += inputNum;
        break;
      }
    }
    Mini.LED1.setRGB(255, 0, 0);
    Mini.LED2.setRGB(255, 0, 0);
  }

  //錢已經存夠了
  Mini.LED1.setRGB(0, 255, 0);
  Mini.LED2.setRGB(0, 255, 0);
  Serial.print("恭喜!已經存夠了,存了" + String(num) + "個月的總存款為:" + String(deposit) + "元");
  digitalWrite(BUZZER, LOW);
  delay(500);
  digitalWrite(BUZZER, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
