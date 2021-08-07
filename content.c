#include <MatrixMini.h>
#define LIGHT_SENSOR A1
#define LIGHT_DIGITAL A0

void setup() {
  Mini.begin();
  Serial.begin(9600);
  Serial.println("============光每電阻測試=============");
  pinMode(LIGHT_DIGITAL,INPUT);
}

void loop() {
  Serial.println("==========光敏電阻數位訊號輸出==============");
  bool digitalValue=digitalRead(LIGHT_DIGITAL);
  Serial.println("數位訊號是:" + String(digitalValue));
  Serial.println("\n\n");
  Serial.println("==========光敏電阻類比訊號輸出==============");
  int analogValue=analogRead(LIGHT_SENSOR);
  Serial.println("類比訊號是:" + String(analogValue));
  if(digitalValue == 0){
    Mini.RGB1.setRGB(0,0,0);
    Mini.RGB2.setRGB(0,0,0);
  }else{
    Mini.RGB1.setRGB(255,0,0);
    Mini.RGB2.setRGB(255,0,0);
  }
  delay(1000);
}
