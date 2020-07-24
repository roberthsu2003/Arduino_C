#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
  Mini.LED1.setRGB(0, 0, 0);
  Mini.LED2.setRGB(0, 0, 0);

  Serial.begin(9600);  
  Serial.println("請輸入您的數學成績:");
}

void loop() {
  if(Serial.available()){
    int score = Serial.parseInt();
    if(score >= 80){
      Serial.println("及格!");
      Mini.LED1.setRGB(0, 255, 0);
      Mini.LED2.setRGB(0, 255, 0);
    }else{
      Serial.println("不及格!");
      Mini.LED1.setRGB(255, 0, 0);
      Mini.LED2.setRGB(255, 0, 0);
    }
    delay(2000);
     Mini.LED1.setRGB(0, 0, 0);
     Mini.LED2.setRGB(0, 0, 0);
  }

}
