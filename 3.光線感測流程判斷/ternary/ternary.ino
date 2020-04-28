//arduinoC
/*
請使用三元運算子? : 製作一個判斷奇偶數的程式，程式的執行結果
顯示=============
請輸入數字:15
您輸入的15是奇數
 */

#include <MatrixMini.h>
MatrixMini Mini;


void setup(){
  Mini.begin();
  Serial.begin(9600);  
  Serial.println("請輸入數字:");  
}

void loop() {
  int inputNumber;
  String message;
  if(Serial.available()){
    Mini.LED1.setRGB(0,0,0);
    Mini.LED2.setRGB(0,0,0);
    inputNumber = Serial.parseInt();
    
    message = (inputNumber % 2 == 0) ? "偶數" : "奇數";
       
    Serial.print("您輸入的");
    Serial.print(inputNumber);
    Serial.print("是");
    Serial.println(message);
  }
  
}
