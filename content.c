//每隔2秒，檢查如果是偶數，亮綠燈，如果是奇數就亮紅燈
#include <MatrixMini.h>

void setup() {
  Mini.begin();
  Serial.begin(9600);
  randomSeed(analogRead(A1));
}

void loop() {
  int randomNum = random(1001);
  if(randomNum % 2 == 0){
    //代表偶數
    Mini.RGB1.setRGB(0,255,0);
  }else{
    //代表奇數
    Mini.RGB1.setRGB(0,0,255);
  }
  
  delay(2000);
  Mini.RGB1.setRGB(0,0,0);
  delay(2000);
}
