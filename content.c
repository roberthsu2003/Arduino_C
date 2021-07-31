#include <MatrixMini.h>

void setup() {
  Mini.begin();
  Serial.begin(9600);
  Serial.println("小車按鈕和RGB LED測試");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Mini.BTN1.get()){
    Mini.RGB1.setRGB(255,0,0);
  }else{
    Mini.RGB1.setRGB(0,0,0);
  }

  if(Mini.BTN2.get()){
    Mini.RGB2.setRGB(0,255,0);
  }else{
    Mini.RGB2.setRGB(0,0,0);
  }
  delay(50);
}
