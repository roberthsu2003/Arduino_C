
//使用光敏電阻,檢查目前的亮度
//插入至Ａ1孔
//小於等於100 很亮
//小於等於200,大於100 亮
//小於等於400,大於200有點亮
//小於等於600,大於400有點暗
//小於等於800,大於600暗
//小於等於1023,大於800 很暗



#include <MatrixMini.h>
#define LIGHT_SENSOR A1
#define LIGHT_DIGHTOR A0

MatrixMini Mini;
String state;

void setup() {
  Mini.begin();
  Serial.begin(9600);
  Serial.println("==========光敏電阻測試==============");
  pinMode(LIGHT_DIGHTOR, INPUT);
}

void loop() {
  Serial.println("==========光敏電阻數位訊號輸出==============");
  bool digitalValue = digitalRead(LIGHT_DIGHTOR);
  Serial.print("數位訊號是:");
  Serial.println(digitalValue);
  Serial.println("\n\n");
  Serial.println("==========光敏電阻類比訊號輸出==============");
  int analogValue = analogRead(LIGHT_SENSOR);
  Serial.print("類比訊號是:");
  Serial.println(analogValue);
  

  if(analogValue < 100){
    state = "很亮";
    Mini.LED1.setRGB(0,255,255);
    Mini.LED2.setRGB(0,255,255);
  }else if(analogValue < 200){
    state = "亮";
    Mini.LED1.setRGB(127,255,212);
    Mini.LED2.setRGB(127,255,212);
  }else if(analogValue < 400){
    state = "有點亮";
    Mini.LED1.setRGB(0,139,0);
    Mini.LED2.setRGB(0,139,0);
  }else if(analogValue < 600){
    state = "有點暗";
    Mini.LED1.setRGB(255,0,0);
    Mini.LED2.setRGB(255,0,0);
  }else if(analogValue < 800){
    state = "暗";
    Mini.LED1.setRGB(0,255,0);
    Mini.LED2.setRGB(0,255,0);
  }else{
    state = "很暗";
    Mini.LED1.setRGB(0,0,255);
    Mini.LED2.setRGB(0,0,255);
  }
  Serial.print("目前狀態:");
  Serial.println(state);
  delay(1000);
}
