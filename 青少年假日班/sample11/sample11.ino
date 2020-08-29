//成績及格判斷
//請使用者輸入成績，若成績大於等於60分，則LED1顯示綠燈，否則LED1顯示紅燈。

#include <MatrixMini.h>

MatrixMini Mini;
int score;

void setup() {
  Serial.begin(9600);
  Mini.begin(); 
}

void loop() {
  Serial.println("請輸入成績:");
  while(true){
     if(Serial.available()){
        score = Serial.parseInt();
        if(score>=60){
          Serial.println("及格!");
          Mini.LED1.setRGB(0, 255, 0);
        }else{
          Serial.println("不及格");
          Mini.LED1.setRGB(255, 0, 0);
        }
        delay(5000);
        Mini.LED1.setRGB(0, 0, 0);
        break;   
     }
  }
 
}
