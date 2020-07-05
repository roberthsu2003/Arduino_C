//按左按鈕,左燈亮
//按右按鈕,右燈亮

#include <MatrixMini.h>

MatrixMini Mini;
void setup() {
  Mini.begin();
  Serial.begin(9600);
}

void loop() {
  switch(Mini.BTN1.get()){
    case 1:
      Mini.LED1.setRGB(255, 0, 0);
      break;
    case 0:
      Mini.LED1.setRGB(0, 0, 0);
      break;
  }

  switch(Mini.BTN2.get()){
    case 1:
      Mini.LED2.setRGB(255, 0, 0);
      break;
    case 0:
      Mini.LED2.setRGB(0, 0, 0);
      break;
  }
}
