/*
成績及格判斷
請使用者輸入成績，若成績大於等於60分，則LED1顯示綠燈，否則LED1顯示紅燈。
*/
#include <MatrixMini.h>
MatrixMini Mini;

unsigned int score;
void setup() {
  Mini.begin();
  Mini.LED1.setRGB(0, 0, 0);
  Serial.begin(9600);  
  Serial.println("請輸入成績:");
}

void loop() {
  if(Serial.available()){
    //true
    score = Serial.parseInt();
    if(score >= 60){
      Serial.println("及格!");
      Mini.LED1.setRGB(0, 255, 0);
      delay(500);
      Mini.LED1.setRGB(0, 0, 0);      
      delay(500);

      Mini.LED1.setRGB(0, 255, 0);
      delay(500);
      Mini.LED1.setRGB(0, 0, 0);
      delay(500);

      Mini.LED1.setRGB(0, 255, 0);
      delay(500);
      Mini.LED1.setRGB(0, 0, 0);
      delay(500);

    }else{
      Serial.println("不及格!");
      Mini.LED1.setRGB(255, 0, 0);
      delay(500);
      Mini.LED1.setRGB(0, 0, 0);
      delay(500);

      Mini.LED1.setRGB(255, 0, 0);
      delay(500);
      Mini.LED1.setRGB(0, 0, 0);
      delay(500);

      Mini.LED1.setRGB(255, 0, 0);
      delay(500);
      Mini.LED1.setRGB(0, 0, 0);
      delay(500);

    }
  }
  
}
