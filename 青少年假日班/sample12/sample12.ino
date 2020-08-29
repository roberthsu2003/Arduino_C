//arduinoC
/*
試用if-else敘述，選寫一個判斷輸入的數字為奇數或偶數的程式,
數字為奇數(LED1亮綠燈)或偶數(LED2亮綠燈)的程式
顯示=============
請輸入數字:15
您輸入的15是奇數
 */
 
#include <MatrixMini.h>
MatrixMini Mini;
int inputNumber;
String message;

void setup() {
  Mini.begin();
  Serial.begin(9600);  
}

void loop() {
  Serial.println("請輸入數字:");
  while(true){
    if(Serial.available()){
      Mini.LED1.setRGB(0, 0, 0);
      Mini.LED2.setRGB(0, 0, 0);
      inputNumber = Serial.parseInt();
      if(inputNumber % 2 == 0){
        message = "偶數";
        Mini.LED1.setRGB(0, 255, 0);
      }else{
        message = "奇數";
        Mini.LED2.setRGB(0, 255, 0);
      }
      break;
    }
  }

  Serial.print("您輸入的" + (String)inputNumber + "是" + message + "\n");

}
